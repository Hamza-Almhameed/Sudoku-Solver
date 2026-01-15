#include <stdio.h>
#include <stdbool.h>

int sudoku[9][9] = {
    {0, 5, 0, 0, 0, 0, 1, 9, 0},
    {0, 0, 0, 0, 0, 0, 0, 4, 2},
    {9, 1, 0, 0, 2, 7, 5, 6, 8},
    {3, 4, 5, 0, 0, 1, 9, 0, 6},
    {7, 0, 0, 3, 4, 0, 0, 0, 0},
    {8, 9, 0, 2, 0, 6, 0, 0, 3},
    {0, 0, 8, 7, 0, 0, 2, 1, 0},
    {1, 6, 0, 0, 0, 8, 0, 0, 4},
    {0, 0, 0, 1, 0, 0, 6, 8, 5},
}; // Example 9x9 Sudoku puzzle where 0 = empty cell

int length = sizeof(sudoku) / sizeof(sudoku[0]);

bool isValid(int row, int col, int num) {
    // Check row
    for(int x = 0; x < length; x++) {
        if(sudoku[row][x] == num) {
            return false;
        }
    }

    // Check column
    for(int y = 0; y < length; y++) {
        if(sudoku[y][col] == num) {
            return false;
        }
    }

    // Check the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(sudoku[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku() {
    for(int row = 0; row < length; row++) {
        for(int col = 0; col < length; col++) {
            if(sudoku[row][col] == 0) { //If the cell is empty

                for(int num = 1; num <= 9; num++) { // Try numbers 1-9
                    if(isValid(row, col, num)) {
                        sudoku[row][col] = num; // Place the number

                        if(solveSudoku()) { // Recursion
                            return true;
                        }

                        sudoku[row][col] = 0; // Backtrack
                    }
                }
                return false; // No valid number found
            }
        }
    }
    return true;
}

void printSudoku() {
    for(int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

int main() {
    if(solveSudoku()) {
        printSudoku();
    }else {
        printf("no solution exists");
    }
    return 0;
}