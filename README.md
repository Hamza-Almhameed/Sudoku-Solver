# Sudoku Solver

This is a simple C program that solves a 9x9 Sudoku puzzle using a backtracking algorithm.

## How It Works

1. The program uses a 2D array to represent the Sudoku grid. Empty cells are represented by `0`.
2. The `solveSudoku` function applies a recursive backtracking algorithm to fill the grid.
3. The `isValid` function checks if placing a number in a specific cell is valid according to Sudoku rules.
4. Once solved, the program prints the completed Sudoku grid.

## Usage

1. Clone or download this repository.
2. Open the `sudoku.c` file and modify the `sudoku` array to input your puzzle.
3. Compile the program using a C compiler:
   ```bash
   gcc sudoku.c -o sudoku
   ```
4. Run the program:
   ```bash
   ./sudoku
   ```

## Notes

- Ensure the input puzzle is valid (follows Sudoku rules) for the solver to work correctly.
- The program assumes a 9x9 grid and does not support other sizes.
