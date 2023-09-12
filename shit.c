#include <stdio.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 10

void moveCursorToColumn(int column);

int main() {
    char text[NUM_ROWS][NUM_COLUMNS];
    char ch;

    // Initialize the 2D array with spaces
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLUMNS; j++) {
            text[i][j] = ' ';
        }
    }

    // Print the 2D array column by column
    for (int col = 0; col < NUM_COLUMNS; col++) {
        // Move the cursor to the top of the terminal
        printf("\033[H");

        // Print the current content of the 2D array
        for (int row = 0; row < NUM_ROWS; row++) {
            putchar(text[row][col]);
        }

        // Move the cursor to the next column
        moveCursorToColumn(col + 1);

        // Prompt for user input for the current column
        printf("Enter text for column %d: ", col + 1);

        // Get user input for the current column
        for (int row = 0; row < NUM_ROWS; row++) {
            ch = getchar();
            if (ch == '\n' || ch == EOF) {
                // Stop getting input if Enter key or EOF is pressed
                break;
            }
            text[row][col] = ch;
        }

        // Clear any remaining input in the input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }

    // Move the cursor to the bottom of the terminal
    printf("\033[%dB", NUM_ROWS);

    return 0;
}

// Function to move the cursor to a specific column using ANSI escape code
void moveCursorToColumn(int column) {
    printf("\033[%dG", column);
}
