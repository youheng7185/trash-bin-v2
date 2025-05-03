import os
import glob
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
from tensorflow.keras.utils import to_categorical
import tensorflow as tf
from nnom import generate_model

# Path to your saved Keras model
MODEL_PATH = "v7_v3_48_conv2d_model.keras"

# Constants
DATASET_PATH = "dataset"
NUM_CLASSES = 4
NUM_FRAMES = 48
NUM_COEFFS = 13
CLASSES = ["aluminium", "general", "paper", "plastic"]

def load_partial_mfcc_q15(bin_file, num_frames=48, num_coeffs=13):
    expected_bytes = num_frames * num_coeffs * 2  # 2 bytes per int16
    try:
        with open(bin_file, "rb") as f:
            raw = f.read(expected_bytes)
            if len(raw) != expected_bytes:
                print(f"Warning: {bin_file} has {len(raw)} bytes, expected {expected_bytes}. Skipping.")
                return None
            data = np.frombuffer(raw, dtype=np.int16).astype(np.float32) / 32768.0
            return data.reshape((num_frames, num_coeffs))
    except Exception as e:
        print(f"Error reading {bin_file}: {e}")
        return None

def load_dataset():
    features, labels = [], []
    for label in CLASSES:
        files = glob.glob(os.path.join(DATASET_PATH, label, f"{label}*.bin"))
        print(f"Loading {len(files)} from {label}")
        for file in files:
            mfcc = load_partial_mfcc_q15(file)
            if mfcc is not None:
                features.append(mfcc)
                labels.append(label)
    X = np.array(features)
    y = LabelEncoder().fit_transform(labels)
    y = to_categorical(y, num_classes=NUM_CLASSES)
    return X, y

def fix_model_for_nnom(model):
    """Create a new model with the same architecture but without the Gaussian noise layer"""
    # Create a simplified model without GaussianNoise and Dropout layers
    inputs = tf.keras.layers.Input(shape=model.input_shape[1:])
    x = inputs
    
    for layer in model.layers[1:]:  # Skip the input layer
        if isinstance(layer, (tf.keras.layers.GaussianNoise, tf.keras.layers.Dropout)):
            # Skip these layers for inference
            continue
        else:
            # Clone the layer with the same weights
            config = layer.get_config()
            if hasattr(layer, 'get_weights'):
                weights = layer.get_weights()
                new_layer = type(layer).from_config(config)
                x = new_layer(x)
                if weights:
                    new_layer.set_weights(weights)
            else:
                # For layers without weights
                new_layer = type(layer).from_config(config)
                x = new_layer(x)
    
    # Create a new model
    new_model = tf.keras.models.Model(inputs=inputs, outputs=x)
    new_model.compile(
        optimizer='adam',
        loss='categorical_crossentropy',
        metrics=['accuracy']
    )
    
    return new_model

def main():
    # Load the dataset
    print("Loading dataset...")
    X, y = load_dataset()
    X = X[..., np.newaxis]  # Add channel dimension for Conv2D
    
    # Split the dataset to get some test data
    _, X_test, _, _ = train_test_split(X, y, test_size=0.2, random_state=42)
    
    print(f"Test data shape: {X_test.shape}")
    
    # Load the pre-trained Keras model
    print(f"Loading model from {MODEL_PATH}...")
    model = tf.keras.models.load_model(MODEL_PATH)
    
    # Print model summary
    print("Original model:")
    model.summary()
    
    # Fix the model for NNoM compatibility
    print("Creating inference model (removing GaussianNoise and Dropout layers)...")
    inference_model = fix_model_for_nnom(model)
    
    print("Inference model for deployment:")
    inference_model.summary()
    
    # Save the inference model temporarily
    inference_model.save("inference_model_for_nnom.keras")
    
    try:
        # Convert model to NNoM format using real test data
        print("Converting model to NNoM format...")
        generate_model(inference_model, X_test, name="weights.h")
        print("NNoM model successfully saved as weights.h")
    except Exception as e:
        print(f"Error during NNoM conversion: {e}")
        print("\nTrying alternative approach...")
        
        # Alternative approach using q_list parameter
        try:
            # Create a default q_list for all layers
            q_list = {}
            for layer in inference_model.layers:
                q_list[layer.name] = [7, 0]  # Using 7 bits for all layers
                
            generate_model(inference_model, X_test, name="weights.h", layer_q_list=q_list)
            print("NNoM model successfully saved using alternative approach!")
        except Exception as e2:
            print(f"Alternative approach also failed: {e2}")
            print("\nPlease try the NNoM GitHub examples for more guidance.")
    
    # Clean up temporary model file
    if os.path.exists("inference_model_for_nnom.keras"):
        os.remove("inference_model_for_nnom.keras")

if __name__ == "__main__":
    main()