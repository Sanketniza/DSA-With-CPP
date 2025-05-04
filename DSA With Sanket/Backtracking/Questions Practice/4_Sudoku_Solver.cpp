#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &board , int row , int col , int val) {

    for(int i = 0; i < board.size(); i++) {
        
        // row check
        if(board[row][i] == val) {
            return false;
        }

        // column check
        if(board[i][col] == val) {
            return false;
        }

        // 3x3 subgrid check
        if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) {
            return false;
        }
    }

    return true;
}

bool solve(vector<vector<int>> &board) {

    int n = board.size();

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {

            if(board[row][col] == 0) {
                
                for(int val = 1; val <= 9; val++) {
                    if(isSafe(board , row , col , val)) {
                        board[row][col] == val;
                        // Recursive call

                        bool possible = solve(board);
                        if(possible) {
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

    return true;
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

    if(solve(board)) {
        cout << "Sudoku solved successfully!" << endl;
        for (const auto& row : board) {
            for (int num : row) {
                cout << num << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }

 return 0;
}