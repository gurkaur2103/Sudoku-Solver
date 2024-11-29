#include <iostream>
#include <vector>

using namespace std;

const int N = 9; // Size of Sudoku grid

// Function to print the Sudoku board
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a number can be placed at position (row, col)
bool isSafe(const vector<vector<int>>& board, int row, int col, int num) {
    // Check if the number is not repeated in the row
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num) {
            return false;
        }
    }

    // Check if the number is not repeated in the column
    for (int x = 0; x < N; x++) {
        if (board[x][col] == num) {
            return false;
        }
    }

    // Check the 3x3 sub-grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(vector<vector<int>>& board) {
    int row, col;
    bool emptySpot = false;

    // Find an empty spot (denoted by 0)
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                emptySpot = true;
                break;
            }
        }
        if (emptySpot) {
            break;
        }
    }

    // If no empty spot, the puzzle is solved
    if (!emptySpot) {
        return true;
    }

    // Try all numbers (1-9) for the empty spot
    for (int num = 1; num <= N; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;

            // Recur to check if this placement leads to a solution
            if (solveSudoku(board)) {
                return true;
            }

            // Backtrack if placing num didn't work
            board[row][col] = 0;
        }
    }

    // No valid number can be placed, backtrack
    return false;
}

int main() {
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Initial Sudoku Board:" << endl;
    printBoard(board);

    // Solving the Sudoku puzzle
    if (solveSudoku(board)) {
        cout << "\nSolved Sudoku Board:" << endl;
        printBoard(board);
    } else {
        cout << "\nNo solution exists!" << endl;
    }

    return 0;
}
