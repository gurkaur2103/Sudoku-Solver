# Sudoku-Solver
This project provides a solution to the classic Sudoku puzzle using the backtracking algorithm. The solver takes an unsolved Sudoku board as input and solves it, if a solution exists.

## Features:
- Solves a Sudoku puzzle using the backtracking technique.
- Checks for validity of each number placement (row, column, and 3x3 grid).
- Prints the initial board and the solved Sudoku board.

## Usage:
1. Clone the repository or download the source code.
2. Compile the code using a C++ compiler (C++11 or above is recommended).
3. Run the executable to solve the provided Sudoku puzzle.

### Example:
The provided Sudoku puzzle will be solved and printed in the console.

**Initial Sudoku Board:**
{
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    }

**Solved Sudoku Board:**
{  
    {5, 3, 4, 6, 7, 8, 9, 1, 2 },
    {6, 7, 2, 1, 9, 5, 3, 4, 8 },
    {1, 9, 8, 3, 4, 2, 5, 6, 7 },
    {8, 5, 9, 7, 6, 1, 4, 2, 3 },
    {4, 2, 6, 8, 5, 3, 7, 9, 1 },
    {7, 1, 3, 9, 2, 4, 8, 5, 6 },
    {9, 6, 1, 5, 3, 7, 2, 8, 4 },
    {2, 8, 7, 4, 1, 9, 6, 3, 5 },
    {3, 4, 5, 2, 8, 6, 1, 7, 9 }
  }
## How to Compile and Run:

1. **Clone the Repository:**
   git clone https://github.com/gurkaur2103/Sudoku-Solver.git
Navigate to the Project Directory:
cd Sudoku-Solver

Compile the Code:
g++ -o sudokuSolver sudokuSolver.cpp

Run the Program:
./sudokuSolver

**Algorithm Explanation**
The Sudoku solver uses the backtracking approach to fill in the empty cells of the Sudoku board. The algorithm:

Finds an empty spot (denoted by 0).
Tries to fill the spot with numbers 1 to 9, checking the validity of each placement.
If a valid placement is found, it recursively attempts to solve the board further.
If the solution leads to an invalid configuration later, it backtracks by removing the last placed number and tries the next possible number.
If the board is filled without conflicts, the puzzle is solved.

# Author
Gurpreet Kaur
