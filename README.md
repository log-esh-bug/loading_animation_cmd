# loading_animation_cmd
# Progress Bar Program (C)

This is a simple command-line program written in C that simulates a progress bar, updating it over a user-defined duration. The progress bar updates every fraction of the total duration and is displayed in a clean, easy-to-read format. It's a useful tool for visualizing the progress of a task that takes a certain amount of time to complete.

## Features:
- Displays a progress bar in the terminal.
- Allows the user to specify the duration (in seconds) for the progress bar.
- The progress bar is updated smoothly over the given duration.
- Supports a customizable width for the progress bar.

## Requirements:
- A C compiler (e.g., `gcc`).
- The program uses standard C libraries such as `<stdio.h>`, `<unistd.h>`, and `<stdlib.h>`.

## Usage:

1. **Clone or download the repository**.
2. Open a terminal and navigate to the directory containing the source code.
3. Compile the program using `gcc` (or any other C compiler):

    ```bash
    gcc -o progress_bar progress_bar.c
    ```

4. Run the program with the desired duration (in seconds) for the progress bar:

    ```bash
    ./progress_bar <duration_in_seconds>
    ```

    Example:

    ```bash
    ./progress_bar 5
    ```

    This command will run the progress bar for 5 seconds.

## Code Explanation:
- **BAR_WIDTH**: The width of the progress bar in characters (default is 50).
- **`draw_bar` function**: This function takes the current progress and prints the progress bar to the terminal. The filled portion of the bar is represented by `#` symbols, and the empty portion is represented by `-` symbols.
- **`usleep` function**: The program uses `usleep` to pause the execution for a specified amount of time (in microseconds) to make the progress bar appear smooth and proportional to the total duration.
- **Duration Calculation**: The duration (in seconds) is passed as a command-line argument. The program calculates how long to wait before updating the progress bar, ensuring that the bar reaches 100% at the end of the specified time.

## Example Output:

When you run the program with a duration of 4 seconds, the output will look like this:

[########################################] 100% Loading Complete!


## Customization:
- You can change the width of the progress bar by modifying the `BAR_WIDTH` constant in the code.
- The progress bar can be scaled for different durations by passing different values as command-line arguments.

## License:
This project is open-source and available for personal or educational use. Feel free to modify the code to suit your needs.
