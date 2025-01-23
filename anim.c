#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define BAR_WIDTH 40  // Width of the progress bar

void draw_bar(int progress) {
    int i;

    // Print the start of the bar
    printf("[");
    
    // Print the filled portion of the bar
    for (i = 0; i < BAR_WIDTH; i++) {
        if (i < progress) {
            printf("#");  // Filled portion
        } else {
            printf("-");  // Empty portion
        }
    }

    // Print the end of the bar
    printf("] %d%%", (progress * 100) / BAR_WIDTH);  // Show percentage

    // Flush the output buffer and move cursor to the beginning of the line
    fflush(stdout);

    // Move the cursor back to the beginning of the line for the next update
    printf("\r");
}

int main(int argc, char *argv[]) {
    // Check if the user provided the duration argument
    if (argc != 2) {
        printf("Usage: %s <duration_in_seconds>\n", argv[0]);
        return 1;
    }

    // Convert the argument to an integer (duration in seconds)
    int sec = atoi(argv[1]);
    if (sec <= 0) {
        printf("Please provide a positive integer for the duration.\n");
        return 1;
    }
    int progress = 0;

    // int sec = 4;

    // long mSec = sec*1000000;


    // int stepPer10000ms = 100/sec;
    double step = sec*1000000/BAR_WIDTH;


    // Loop to update the progress bar
    while (progress <= BAR_WIDTH) {
        draw_bar(progress);
        usleep(step);  // Sleep for 100 milliseconds
        progress++;
    }

    // Print completion message after the bar reaches 100%
    printf("\nLoading Complete!\n");

    return 0;
}
