#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool safe(int x , int y , vector<vector<int>> &arr , int n , vector<vector<bool>> &vis) {
    
    if( (x >= 0 && x < n) && (y >= 0 && y < n) && (!vis[x][y]) && (arr[x][y] == 1)) {
        return true;
    }

    return false;
}

void solve(int x , int y , vector<vector<int>> &arr , int n , vector<string> &ans , vector<vector<bool>> &vis , string path) {
    
    // base case
    if(x == n -1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    // 4 movement D L R U
    vis[x][y] = true;

    // Down
    if(safe(x + 1 , y , arr , n , vis)) {
        solve(x + 1 , y , arr , n , ans , vis , path + 'D');
    }

    // Left
    if(safe(x , y - 1 , arr , n , vis)) {
        solve(x , y - 1 , arr , n , ans , vis , path + 'L');
    }

    // right
    if(safe(x , y + 1 , arr , n , vis)) {
        solve(x , y + 1 , arr , n , ans , vis , path + 'R');
    }

    // up
    if(safe(x - 1 , y , arr , n , vis)) {
        solve(x - 1 , y , arr , n , ans , vis , path + 'U');
    }

    vis[x][y] = false; // backtrack
}

vector<string> maze(vector<vector<int>> &arr , int n) {

    vector<string> ans;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    string path = "";
    solve(0 , 0 , arr , n , ans , vis , path);
    return ans;
}

int main() {

    vector<vector<int>> arr = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    int n = arr.size();

    vector<string> ans = maze(arr, n);
    for (const string &path : ans) {
        cout << path << " ";
    }
 return 0;
}