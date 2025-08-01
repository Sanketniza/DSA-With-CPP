#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &board , int n , int row , int col , int val) {

    for(int i = 0; i < n; i++) {

        // check for row 
        if(board[row][i] == val) {
            return false;
        }

        if(board[i][col] == val) {
            return false;
        }

        if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) {
            return false;
        }
    }
    return true;

}



bool solveSudoku(vector<vector<int>> &board) {

    int n = board.size();

    for(int row = 0; row < n; row++ ) {
        for(int col = 0; col < n; col++) {

            if(board[row][col] == 0) {

                for(int val = 1; val <= 9; val++) {
                    if(isSafe(board , n , row , col , val)) {
                        board[row][col] = val;
                        bool possible = solveSudoku(board);

                        if(possible) {
                            return true;
                        } else {
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printSudoku(const vector<vector<int>> &board) {

    for(const auto &row : board) {
        for( int val : row  ) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {

    // vector<vector<int>> board {
    //     {5, 3, 0, 0, 7, 0, 0, 0, 0},
    //     {6, 0, 0, 1, 9, 5, 0, 0, 0},
    //     {0, 9, 8, 0, 0, 0, 0, 6, 0},
    //     {8, 0, 0, 0, 6, 0, 0, 0, 3},
    //     {4, 0, 0, 8, 0, 3, 0, 0, 1},
    //     {7, 0, 0, 0, 2, 0, 0, 0, 6},
    //     {0, 6, 0, 0, 0, 0, 2, 8, 0},
    //     {0, 0, 0, 4, 1, 9, 0, 0, 5},
    //     {0, 0, 0, 0, 8, 0, 0, 7, 9}
    // };

    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 7, 7, 9}
    };

    if(solveSudoku(board)) {
        cout << "Sudoku solved successfully:" << endl;
        printSudoku(board);
    }
    else {
        cout << "No solution exists for the given Sudoku puzzle." << endl;
    }
    
 return 0;
}