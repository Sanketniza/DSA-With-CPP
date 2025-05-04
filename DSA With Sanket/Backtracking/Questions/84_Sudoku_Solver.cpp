/* 
    ? link :- https://www.geeksforgeeks.org/n-queen-problem-backtracking-1/
    ? https://www.naukri.com/code360/problems/sudoku-solver_699919?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

    Problem statement
You have been given a 9x9 2d integer matrix 'MAT' representing a Sudoku puzzle. The empty cells of the Sudoku are filled with zeros, and the rest of the cells are filled with integers from 1 to 9. Your task is to fill all the empty cells such that the final matrix represents a Sudoku solution.

Note:
A Sudoku solution must satisfy all the following conditions-
1. Each of the digits 1-9 must occur exactly once in each row.
2. Each of the digits 1-9 must occur exactly once in each column.
3. Each of the digits 1-9 must occur exactly once in each of the 9, 3x3 sub-grids of the grid.

You can also assume that there will be only one sudoku solution for the given matrix.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
Size of MAT is 9x9
0 <= MAT[i][j] <= 9

where an empty cell is given by 0 in the matrix.
Output Format :
The output is consists of 9 lines. Each line contains 9 single space-separated integers where the empty cells from the input matrix are replaced by some integers.
Note
You are not required to print anything, and it has already been taken care of. Just implement the function.
Sample Input 1
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0

Sample Output 1
3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9
Explanation For Sample Output 1
In the output:
In each row, each of the digits 1-9 is occurring exactly once.
In each column, each of the digits 1-9 is occurring exactly once.
In each 3x3 sub-grids of the grid, each of the digits is occurring exactly once.

 */

#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &board, int n, int row, int col, int val) {
    for (int i = 0; i < n; i++) {
        // Check for row
        if (board[row][i] == val) {
            return false;
        }

        // Check for column
        if (board[i][col] == val) {
            return false;
        }

        // Check for 3x3 subgrid
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>> &board) {
    int n = board.size();

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {

            if (board[row][col] == 0) {
                for (int val = 1; val <= 9; val++) {
                    if (isSafe(board, n, row, col, val)) {
                        board[row][col] = val;

                        // Recursive call
                        bool possible = solve(board);
                        if (possible) {
                            return true;
                        } else {
                            // Backtrack
                            board[row][col] = 0;
                        }
                    }
                }
                return false; // If no number from 1 to 9 can be placed
            }
            
        }
    }
    return true; // When all cells are filled
}

void printBoard(const vector<vector<int>> &board) {
    for (const auto &row : board) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
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

    if (solve(board)) {
        cout << "Sudoku solved successfully:" << endl;
        printBoard(board);
    } else {
        cout << "No solution exists for the given Sudoku puzzle." << endl;
    }

    return 0;
}
