#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row , int col , vector<vector<int>> &arr , int n , vector<vector<bool>> &visited) {
    
    if((row >= 0 && row < n && col >= 0 && col < n ) && (!visited[row][col] && arr[row][col] == 1)) {
        return true;
    }

    else {
        return false;
    }
}

void solve(int row , int col , vector<vector<int>> &arr , int n , vector<string> &result , vector<vector<bool>> &visited , string path) {

    // base case
    if(row == n -1 && col == n - 1) {
        result.push_back(path);
        return;
    }

    visited[row][col] = true;

    // down
    if(isSafe(row + 1 , col , arr , n , visited)) {
        solve(row + 1 , col , arr , n , result , visited , path + 'D');
    }

    // left
    if(isSafe(row , col - 1 , arr , n , visited)) {
        solve(row , col - 1 , arr , n , result , visited , path + 'L');
    }

    // right
    if(isSafe(row , col + 1 , arr , n , visited)) {
        solve(row , col + 1 , arr , n , result , visited , path + 'R');
    }

    // up
    if(isSafe(row - 1 , col , arr , n , visited)) {
        solve(row - 1 , col , arr , n , result , visited , path + 'U');
    }

    visited[row][col] = false;
}

vector<string> solve (vector<vector<int>> &arr , int n) {

    vector<string> result;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string path = "";

    if(arr[0][0] == 0) {
        return result;
    
    }

    solve(0 , 0 , arr , n , result , visited , path);

    return result;
}

int main() {

    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    int n = maze.size();

    vector<string> ans = solve(maze, n);

    for(int i = 0; i < ans.size(); i++) {
        cout << "Path " << i + 1 << " : " << ans[i] << endl;
    }
    
 return 0;
}