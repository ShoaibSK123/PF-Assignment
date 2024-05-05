#include <stdio.h>

//PF Assignment Q#3
//Shoaib Khan
//23P-0007
//Note: To explain the complex nature of the code, I have added alot of comments. 

//Grid: We call the 20x20 array the grid

/*Summary: We look at the grid in different ways—side to side, up and down,
and even diagonally. At each step, we examine groups of four numbers next to each other.
If we find a group where the multiplication result is bigger than what we've seen before, we remember it
and say whether it was from a row, a column, or a diagonal. In the end, we tell which group of
numbers gave us the biggest result and what direction it was in.*/

const int ROWS= 20;
const int COLS= 20;

// Function to find the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the largest product of four adjacent numbers in a grid
int largestProduct(int grid[ROWS][COLS], char *direction) {
    int maxProduct = 0;
    *direction = ' '; // Initialize direction to empty

        // Check horizontally, loop through each row and calculate the product of fourdjacent numbers in the same row
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) { // Avoid the last 3 columns to ensure four adjacent numbers
            int product = grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3]; // Calculate the product
            if (product > maxProduct) { // If the product is greater than the current maximum
                maxProduct = product; // Update the maxlmum product
                *direction = 'H'; // Set direction to horizontal
            }
        }
    }
    
    // Check vertically, lop through each column and calcuate the product of four adjacent numbers in the same column
    for (int i = 0; i < ROWS - 3; i++) { // Avoid the last 3 rows to ensure four adjacent numbers
        for (int j = 0; j < COLS; j++) {
            int product = grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j]; // Calculate the product
            if (product > maxProduct) { // If the product is greater than the current maximum
                maxProduct = product; // Update the maximum product
                *direction = 'V'; // Set directin to vertical
            }
        }
    }
    
    // Check diagonally (top-lef to bottom-right), loop through each row and column
    for (int i = 0; i < ROWS - 3; i++) { // Avoid the last 3 rows
        for (int j = 0; j < COLS - 3; j++) { // Avoid the last 3 columns
            int product = grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3]; // Calculate the product
            if (product > maxProduct) { // If the product is greater than the current maximum
                maxProduct = product; // Update the maximum product
                *direction = 'D'; // Set direction to iagonal
            }
        }
    }
    
    // Check diagonally (bo  ttom-left to top-right), loop through each row starting from the 4th row
    for (int i = 3; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) { // Avoid the last 3 columns
            int product = grid[i][j] * grid[i - 1][j + 1] * grid[i - 2][j + 2] * grid[i - 3][j + 3]; // Calculate the product
            if (product > maxProduct) { // If the prodct is greater than the current maximum
                maxProduct = product; // Update the maximum product
                *direction = 'D'; // Set direction to diagonal
            }
        }
}


    return maxProduct;
}

int main() {
    int grid[ROWS][COLS] = {
    { 8, 2, 22, 97, 38, 15, 0, 40, 0, 75},
    { 49, 49, 99, 40, 17, 81, 18, 57, 60, 87},
    { 81, 49, 31, 95, 73, 55, 79, 14, 29, 93, 71},
    { 52, 70, 23, 4, 60, 11, 42, 69, 24, 68},
    { 22, 31, 16, 71, 51, 67, 63, 89, 41, 92},
    { 24, 47, 32, 60, 99, 3, 45, 2, 44, 75},
    { 32, 98, 81, 28, 64, 23, 67, 10, 26, 38},
    { 67, 26, 20, 68, 2, 62, 12, 20, 95, 63},
    { 24, 55, 58, 5, 66, 73, 99, 26, 97, 17},
    { 21, 36, 23, 9, 75, 0, 76, 44, 20, 45},
    { 78, 17, 53, 28, 22, 75, 31, 67, 15, 94},
    { 16, 39, 5, 42, 96, 35, 31, 47, 55, 58},
    { 86, 56, 0, 81, 48, 35, 71, 89, 7, 5, 44},
    { 19, 80, 68, 5, 94, 47, 69, 28, 73, 92},
    { 4, 52, 8, 83, 97, 35, 99, 16, 7, 97},
    { 88, 36, 68, 87, 57, 62, 20, 72, 3, 46},
    { 4, 42, 16, 73, 38, 25, 39, 11, 24, 94},
    { 20, 69, 36, 41, 72, 30, 23, 88, 34, 62},
    { 20, 73, 35, 29, 78, 31, 90, 1, 74, 31},
    { 1, 70, 54, 71, 83, 51, 54, 69, 16, 92}
};

    char direction;
    // Find the largest product and its direction
    int result = largestProduct(grid, &direction);

    // Output the result and diection
    printf("The largest product of four adjacent numbers is: %d\n", result);
    switch (direction) {
        case 'H':
            printf("Direction: Horizontal\n");
            break;
        case 'V':
            printf("Direction: Vertical\n");
            break;
        case 'D':
            printf("Direction: Diagonal\n");
            break;
        default:
            printf("Direction: Unknown\n");
            break;
    }

    return 0;
}
