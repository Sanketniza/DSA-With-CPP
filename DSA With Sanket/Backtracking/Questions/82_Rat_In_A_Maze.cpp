/* 
    ? lecture 82 :  Rat In A Maze
    ? https://www.naukri.com/code360/problems/rat-in-a-maze_1215030?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

    Problem statement
You are given a starting position for a rat which is stuck in a maze at an initial point (0, 0) (the maze can be thought of as a 2-dimensional plane). The maze would be given in the form of a square matrix of order 'N' * 'N' where the cells with value 0 represent the maze’s blocked locations while value 1 is the open/available path that the rat can take to reach its destination. The rat's destination is at ('N' - 1, 'N' - 1). Your task is to find all the possible paths that the rat can take to reach from source to destination in the maze. The possible directions that it can take to move in the maze are 'U'(up) i.e. (x, y - 1) , 'D'(down) i.e. (x, y + 1) , 'L' (left) i.e. (x - 1, y), 'R' (right) i.e. (x + 1, y).

Note:
Here, sorted paths mean that the expected output should be in alphabetical order.
For Example:
Given a square matrix of size 4*4 (i.e. here 'N' = 4):
1 0 0 0
1 1 0 0
1 1 0 0
0 1 1 1 
Expected Output:
DDRDRR DRDDRR 
i.e. Path-1: DDRDRR and Path-2: DRDDRR

The rat can reach the destination at (3, 3) from (0, 0) by two paths, i.e. DRDDRR and DDRDRR when printed in sorted order, we get DDRDRR DRDDRR.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
2 <= N <= 5
0 <= MATRIX[i][j] <= 1

Where N is the size of the square matrix.

Time Limit: 1sec
Sample Input 1:
4
1 0 0 0 
1 1 0 1
1 1 0 0
0 1 1 1
Sample Output 1:
DDRDRR DRDDRR
Explanation For Sample Input 1:
The rat can reach the destination at (3, 3) from (0, 0) by two paths, i.e. DRDDRR and DDRDRR when printed in sorted order, we get DDRDRR DRDDRR.
Sample Input 2:
2
1 0
1 0
Sample Output 2:
[]
Explanation For Sample Input 2:
As no valid path exists in Sample input 2 so we return an empty list.


 */

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