#include <stdio.h>
#include <stdlib.h>

// Function to modify a copy of the array
void modifyArray(int **copy, int rows, int cols) {
    // Modify the copy of the array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            copy[i][j] += 1; // Modify the copy in some way
        }
    }
}

int main() {
    int rows = 3;
    int cols = 4;

    // Allocate memory for the original array
    int **original = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        original[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the original array with some values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            original[i][j] = i * cols + j;
        }
    }

    // Create a copy of the original array
    int **copy = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        copy[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            copy[i][j] = original[i][j]; // Copy the values from the original to the copy
        }
    }

    // Call the function to modify the copy
    modifyArray(copy, rows, cols);

    // Print the original array
    printf("Original array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", original[i][j]);
        }
        printf("\n");
    }

    // Print the modified copy
    printf("Modified copy:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", copy[i][j]);
        }
        printf("\n");
    }

    // Free the memory for both arrays
    for (int i = 0; i < rows; i++) {
        free(original[i]);
        free(copy[i]);
    }
    free(original);
    free(copy);

    return 0;
}
