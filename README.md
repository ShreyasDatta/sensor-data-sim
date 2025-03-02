# Sensor Data Simulator

This C program simulates data generation from an external sensor and processes it periodically.

## Features
- Simulates a timer that generates random bytes every second.
- Prints the latest 50 bytes in hexadecimal format every 10 seconds.
- Uses a circular buffer to store and manage data.

## Assumptions
- The program is designed to run in an online C compiler, so real-time timers and multithreading are not used.
- The buffer size is fixed at 100 bytes for simplicity.
- The program runs indefinitely until manually stopped.

## How to Run
1. Copy the code into an online C compiler.
2. Compile and run the program.
3. Observe the output in the console.

## Repository Structure
- `main.c`: The C program.
- `README.md`: Documentation.