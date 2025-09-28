
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(int newx, int newy, vector<vector<int>> &arr, int n, vector<vector<bool>> &vis) {
    if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && (!vis[newx][newy]) && (arr[newx][newy] == 1)) {
        return true;
    } else {
        return false;
    }
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &vis, string path) {
    
    // base case
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    // 4 movement D L R U
    // Down

        vis[x][y] = true;

    if (isSafe(x + 1, y, arr, n, vis)) {
        // vis[x][y] = true;
        solve(x + 1, y, arr, n, ans, vis, path + 'D');
        // vis[x][y] = false;
    }

    // Left
    if (isSafe(x, y - 1, arr, n, vis)) {
        // vis[x][y] = true;
        solve(x, y - 1, arr, n, ans, vis, path + 'L');
        // vis[x][y] = false;
    }

    // Right
    if (isSafe(x, y + 1, arr, n, vis)) {
        // vis[x][y] = true;
        solve(x, y + 1, arr, n, ans, vis, path + 'R');
        // vis[x][y] = false;
    }

    // Up
    if (isSafe(x - 1, y, arr, n, vis)) {
        // vis[x][y] = true;
        solve(x - 1, y, arr, n, ans, vis, path + 'U');
        // vis[x][y] = false;
    }
        vis[x][y] = false;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
    
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string path = "";

    if (arr[0][0] == 0) {
        return ans;
    } 

    solve(0, 0, arr, n, ans, visited, path);

    return ans;
}

int main() {

    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {1, 1, 1, 1}
    };

    int n = maze.size();
    cout << "size of maze: " << n << "x" << n << endl;
    vector<string> ans = searchMaze(maze, n);

    cout << "Paths to reach the destination: " << endl;
    for (const string &path : ans) {
        cout << path << " " << endl;
    }

    cout << "Paths to reach the destination: " << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl << endl;

    cout << "Paths to reach the destination: " << endl;
    for(string s : ans) {
        cout << s << " ";
    }
    cout << endl << endl;

    cout << "Paths to reach the destination: " << endl;
    for(auto s : ans) {
        cout << s << " ";
    }
    cout << endl << endl;

    cout << "Paths to reach the destination: " << endl;
    for(auto &s : ans) {
        cout << s << " ";
    }
    cout << endl << endl;

    return 0;
}