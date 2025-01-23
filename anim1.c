#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BAR_WIDTH 50

void draw_bar(int progress) {
    int i;

    printf("[");

    for (i = 0; i < BAR_WIDTH; i++) {
        if (i < progress) {
            printf("#");  // Filled portion
        } else {
            printf("-");  // Empty portion
        }
    }

    printf("] %d%%", (progress * 100) / BAR_WIDTH);  

    fflush(stdout);

    printf("\r");
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <duration_in_seconds>\n", argv[0]);
        return 1;
    }

    int sec = atoi(argv[1]);
    if (sec <= 0) {
        printf("Please provide a positive integer for the duration.\n");
        return 1;
    }

    int progress = 0;
    
    long step = (sec * 1000000) / BAR_WIDTH;  

    while (progress <= BAR_WIDTH) {
        draw_bar(progress);
        usleep(step);  
        progress++;
    }

    printf("\nLoading Complete!\n");

    return 0;
}
