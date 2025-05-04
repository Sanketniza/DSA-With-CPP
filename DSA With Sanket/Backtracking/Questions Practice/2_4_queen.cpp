#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row , int col , vector<vector<int>> &board , int n) {

    int x = row;
    int y = col;

    // check for same row but in back direction 
    while (y >= 0) {
        if(board[x][y] == 1) {
            return false;
        }
        y--;
    }

    x = row;
    y = col;

    // check for upper diagonal
    while (x >= 0 && y >= 0) {
        if(board[x][y] == 1) {
            return false;
        }
        x--;
        y--;
    }

    x = row;
    y = col;

    // check for lower diagonal
    while (x < n && y >= 0) {
        if(board[x][y] == 1) {
            return false;
        }
        y--;
        x++;
    }

    return true;

}

void addSolution(vector<vector<int>> &board , vector<vector<int>> &ans , int n) {

    vector<int> temp;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }

    ans.push_back(temp);
}

void solve(int col , vector<vector<int>> &board , vector<vector<int>> &ans , int n) {

    // base case
    if(col == n) {
        addSolution(board , ans , n);
        return;
    }

    // recursion call 
    for(int row = 0; row < n; row++) {
        if(isSafe(row , col , board , n)) {
            board[row][col] = 1;
            solve(col + 1 , board , ans , n);
            board[row][col] = 0; // backtrack
        }
    }
}

vector<vector<int>> solveNQueens(int n) {

    vector<vector<int>> board (n , vector<int>(n , 0));
    vector<vector<int>> ans;
    solve(0 , board , ans , n);
    return ans;
}

int main() {

    int n;
    cout << "Enter the size of the board: ";
    cin >> n;

    vector<vector<int>> result = solveNQueens(n);
    cout << "Number of solutoin is : " << result.size() << endl;

    cout << "Solution is : " << endl;
    for(int i = 0; i < result.size(); i++) {
        
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                cout << result[i][j * n + k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

 return 0;

}