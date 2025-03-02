#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define BUFFER_SIZE 100

// Global data structure to store bytes
unsigned char buffer[BUFFER_SIZE];
int buffer_index = 0;

// Function to generate random bytes and add to buffer
void generate_data(int upper_limit) {
    int num_bytes = rand() % (upper_limit + 1); // Random number of bytes (0 to upper_limit)
    for (int i = 0; i < num_bytes; i++) {
        buffer[buffer_index] = rand() % 256; // Random byte (0 to 255)
        buffer_index = (buffer_index + 1) % BUFFER_SIZE; // Circular buffer
    }
}

// Function to print and clear the latest 50 bytes
void process_data() {
    if (buffer_index >= 50) {
        printf("Latest 50 bytes (hex): ");
        for (int i = 0; i < 50; i++) {
            int index = (buffer_index - 50 + i) % BUFFER_SIZE;
            printf("%02X ", buffer[index]);
        }
        printf("\n");
        buffer_index -= 50; // Remove printed bytes
        if (buffer_index < 0) {
            buffer_index += BUFFER_SIZE; // Adjust for circular buffer wrap-around
        }
    } else {
        printf("Not enough data (current bytes: %d)\n", buffer_index);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int upper_limit;
    printf("Enter the upper limit for the number of random bytes generated (0 to 5): ");
    scanf("%d", &upper_limit);

    if (upper_limit < 0 || upper_limit > 5) {
        printf("Invalid input. Please enter a number between 0 and 5.\n");
        return 1;
    }

    int timer = 0;
    while (1) {
        // Simulate timer task (every second)
        generate_data(upper_limit);
        timer++;

        // Simulate main task (every 10 seconds)
        if (timer % 10 == 0) {
            process_data();
        }

        sleep(1); // Wait for 1 second
    }

    return 0;
}