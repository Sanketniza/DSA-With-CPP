/* 
    Question Link: https://leetcode.com/problems/n-queens/
    ? https://www.naukri.com/code360/problems/the-n-queens-puzzle_981286?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
    
 */

#include <bits/stdc++.h> 
using namespace std;

void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n) {
    vector<int> temp;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
    int x = row;
    int y = col;

    // Check for same row
    while (y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        y--;
    }

    x = row;
    y = col;

    // Check for upper diagonal
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        x--;
        y--;
    }

    x = row;
    y = col;

    // Check for lower diagonal
    while (x < n && y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        y--;
        x++;
    }

    return true;
}

void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n) {
    // Base case
    if (col == n) {
        addSolution(board, ans, n);
        return;
    }

    // Recursive call
    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 1;
            solve(col + 1, board, ans, n);

            // Backtracking
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n) {

    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, board, ans, n);

    return ans;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<int>> result = nQueens(n);

    cout << "Number of solutions: " << result.size() << endl;

    for (const auto &solution : result) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << solution[i * n + j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
