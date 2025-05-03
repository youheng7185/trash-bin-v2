import os
import glob
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import (InputLayer, SeparableConv2D, BatchNormalization,
                                     AveragePooling2D, Dropout, Flatten, Dense, GaussianNoise,
                                     GlobalAveragePooling2D, Conv2D)

from tensorflow.keras.optimizers import Adam
from tensorflow.keras.utils import to_categorical
from tensorflow.keras.regularizers import l2

# Constants
DATASET_PATH = "dataset"
NUM_CLASSES = 4
NUM_FRAMES = 48  # Change to 48 frames for training
NUM_COEFFS = 13
SLICE_BYTES = NUM_FRAMES * NUM_COEFFS
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

def create_model(input_shape, num_classes):
    reg = l2(0.0003)
    model = Sequential([
        InputLayer(input_shape=input_shape),
        GaussianNoise(0.01),

        Conv2D(16, (3, 3), activation='relu', padding='same'),
        BatchNormalization(),
        AveragePooling2D((2, 2)),
        Dropout(0.1),

        Conv2D(32, (3, 3), activation='relu', padding='same'),
        BatchNormalization(),
        AveragePooling2D((2, 2)),
        Dropout(0.2),

        Conv2D(64, (3, 3), activation='relu', padding='same'),
        BatchNormalization(),
        AveragePooling2D((2, 2)),
        Dropout(0.3),

        GlobalAveragePooling2D(),
        Dense(64, activation='relu', kernel_regularizer=reg),
        Dropout(0.4),
        Dense(num_classes, activation='softmax')
    ])
    model.compile(
        optimizer=Adam(0.0005),
        loss='categorical_crossentropy',
        metrics=['accuracy']
    )
    return model

def main():
    X, y = load_dataset()
    X = X[..., np.newaxis]  # Add channel dimension
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, stratify=y)

    print("Building model...")
    model = create_model(input_shape=X_train.shape[1:], num_classes=NUM_CLASSES)
    model.summary()

    print("Training...")
    model.fit(
        X_train, y_train,
        validation_split=0.1,
        epochs=1000,
        batch_size=32,
        verbose=1
    )

    print("Evaluating...")
    test_loss, test_acc = model.evaluate(X_test, y_test)
    print(f"Test accuracy: {test_acc:.4f}")
    model.save("v7_v3_48_conv2d_model.keras")


if __name__ == "__main__":
    main()
