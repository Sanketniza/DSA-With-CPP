#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void addSolution(vector<vector<int>> &board , vector<vector<int>> &ans , int n) {

    vector<int> temp;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }

    ans.push_back(temp);
}

bool isSafe(int row , int col , vector<vector<int>> &board , int n) {

    int x = row;
    int y = col;

    // check all row
    while (y >= 0) {
        if(board[x][y] = 0) {
            return false;
        }

        y--;
    }

    x =  row;
    y =  col;

    while(y >= 0 && x >= 0) {
        if(board[x][y] == 1) {
            return false;
        }

        x--;
        y--;
    }

    x =  row;
    y =  col;

    while (y >= 0 && x >= 0) {
        if(board[x][y] == 1){
            return false;
        }

        x++;
        y++;
    }

    return true;
}

void solve( int col , vector<vector<int>> &board , vector<vector<int>> &ans , int n) {

    //base case
    if(col == n) {
        addSolution(board , ans , n);
        return;
    }

    for(int row = 0; row < n; row++) {
        if(isSafe(row , col , board , n)) {
            board[row][col] = 1;
            solve(col + 1 , board , ans, n);

            board[row][col] = 0; // backtraking
        }
    }
}

vector<vector<int>> nQueens(int n) {

    vector<vector<int>> board (n , vector<int> (n , 0));

    vector<vector<int>> ans;

    solve(0  , board , ans ,  n);

    return ans;
}

int main() {

    int n;
    cout << "Enter value n : " << endl;
    cin >> n;

    vector<vector<int>> result = nQueens(n);

    cout << "All write " << endl;
    
 return 0;
}