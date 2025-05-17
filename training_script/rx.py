#!/usr/bin/env python3
import serial
import wave
import struct
import argparse
import time
from tqdm import tqdm

def receive_audio_and_save(port, baud_rate, output_file, sample_rate=16000, record_seconds=2):
    """
    Receives audio data from serial port and saves it as a WAV file.
    
    Args:
        port (str): Serial port name (e.g., 'COM3' on Windows, '/dev/ttyUSB0' on Linux)
        baud_rate (int): Baud rate of the serial connection
        output_file (str): Output WAV file path
        sample_rate (int): Sample rate of the audio (defaults to 16000 Hz)
        record_seconds (int): Duration of the recording in seconds
    """
    # Calculate expected number of samples
    sample_count = sample_rate * record_seconds
    
    # Initialize serial connection
    try:
        ser = serial.Serial(port, baud_rate, timeout=10)
        print(f"Connected to {port} at {baud_rate} baud")
    except Exception as e:
        print(f"Error opening serial port: {e}")
        return
    
    # Make sure connection is established
    time.sleep(2)
    
    print(f"Receiving {record_seconds} seconds of audio data...")
    
    # Expected bytes to receive (2 bytes per sample for 16-bit audio)
    expected_bytes = sample_count * 2
    
    # Read data from serial
    audio_data = bytearray()
    
    # Use tqdm for a progress bar
    with tqdm(total=expected_bytes) as pbar:
        bytes_received = 0
        
        # Set a timeout limit (seconds)
        timeout_start = time.time()
        timeout_limit = record_seconds * 3  # 3x the expected recording time
        
        while bytes_received < expected_bytes:
            if time.time() - timeout_start > timeout_limit:
                print(f"\nTimeout reached after receiving {bytes_received} bytes")
                break
                
            if ser.in_waiting > 0:
                chunk = ser.read(min(ser.in_waiting, expected_bytes - bytes_received))
                audio_data.extend(chunk)
                bytes_received += len(chunk)
                pbar.update(len(chunk))
    
    # Close serial connection
    ser.close()
    
    # Check if we received enough data
    if len(audio_data) < expected_bytes:
        print(f"Warning: Received only {len(audio_data)} bytes out of {expected_bytes} expected")
    elif len(audio_data) > expected_bytes:
        print(f"Warning: Received {len(audio_data)} bytes, trimming to {expected_bytes} expected bytes")
        audio_data = audio_data[:expected_bytes]
    
    # Convert bytes to 16-bit samples
    samples = []
    for i in range(0, len(audio_data), 2):
        if i + 1 < len(audio_data):
            sample = struct.unpack('<h', audio_data[i:i+2])[0]  # Little-endian 16-bit
            samples.append(sample)
    
    # Save as WAV file
    with wave.open(output_file, 'wb') as wav_file:
        wav_file.setnchannels(1)  # Mono
        wav_file.setsampwidth(2)  # 16-bit
        wav_file.setframerate(sample_rate)
        wav_file.writeframes(struct.pack('<' + 'h' * len(samples), *samples))
    
    print(f"Audio saved to {output_file}")

def main():
    parser = argparse.ArgumentParser(description="Receive audio data from serial port and save as WAV")
    parser.add_argument('--port', type=str, required=True, help='Serial port (e.g., COM3, /dev/ttyUSB0)')
    parser.add_argument('--baud', type=int, default=115200, help='Baud rate (default: 115200)')
    parser.add_argument('--output', type=str, default='output.wav', help='Output WAV file (default: output.wav)')
    parser.add_argument('--sample-rate', type=int, default=16000, help='Sample rate in Hz (default: 16000)')
    parser.add_argument('--duration', type=int, default=2, help='Recording duration in seconds (default: 2)')
    
    args = parser.parse_args()
    
    receive_audio_and_save(
        args.port, 
        args.baud, 
        args.output,
        args.sample_rate,
        args.duration
    )

if __name__ == "__main__":
    main()