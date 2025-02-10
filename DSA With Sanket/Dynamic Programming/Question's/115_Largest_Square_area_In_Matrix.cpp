
/* 
    115: Largest Square area in Matrix
    https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1

    argest square formed in a matrix
   
    Given a binary matrix mat, find out the maximum length of a side of a square sub-matrix with all 1s.

    Examples:

   Input: mat = [[0, 1, 1, 0, 1], 
              [1, 1, 0, 1, 0],
              [0, 1, 1, 1, 0],
              [1, 1, 1, 1, 0],
              [1, 1, 1, 1, 1],
              [0, 0, 0, 0, 0]]
Output: 3


Explanation: 

The maximum length of a side of the square sub-matrix is 3 where every element is 1.

    The maximum length of a side of the square sub-matrix is 3 where every element is 1.
    Input: mat = [[1, 1], 
                [1, 1]]
    Output: 2
    Explanation: The maximum length of a side of the square sub-matrix is 2. The matrix itself is the maximum sized sub-matrix in this case.
    Input: mat = [[0, 0], 
                [0, 0]]
    Output: 0
    Explanation: There is no 1 in the matrix.

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve (vector<vector<int> >&mat , int row , int col , int &ans) {

    if(row >= mat.size() || col >= mat[0].size()) {
        return 0;
    }

    int right = solve(mat , row , col + 1 , ans);
    int down = solve(mat , row + 1 , col , ans);
    int diagonal = solve(mat , row + 1 , col + 1 , ans);

    if(mat[row][col] == 1) {
        int temp = 1 + min(right , min(down , diagonal));
        ans = max(ans , temp);
        return temp;
    }

    else {
        return 0;
    }
}

int solveM(vector<vector<int> >&mat , int row , int col , int &ans , vector<vector<int>>&dp) {

    if(row >= mat.size() || col >= mat[0].size()) {
        return 0;
    }

    if(dp[row][col] != -1) {
        return dp[row][col];
    }

    int right = solveM(mat , row , col + 1 , ans , dp);
    int down = solveM(mat , row + 1 , col , ans , dp);
    int diagonal = solveM(mat , row + 1 , col + 1 , ans , dp);

    if(mat[row][col] == 1) {
        int temp = 1 + min(right , min(down , diagonal));
        ans = max(ans , temp);
        dp[row][col] = temp;
        return temp;
    }

    else {
        dp[row][col] = 0;
        return 0;
    }
}

int solveT(vector<vector<int> >&mat , int& maxi) {
    
    int row = mat.size();
    int col = mat[0].size();
    
    vector<vector<int>> dp(row, vector<int>(col, -1));
    
    for(int i = row - 1; i >= 0; i--) {
        for(int j = col - 1; j >= 0; j--) {
            
            int right = (j + 1 < col) ? dp[i][j + 1] : 0;
            int diagonal = (i + 1 < row && j + 1 < col) ? dp[i + 1][j + 1] : 0;
            int down = (i + 1 < row) ? dp[i + 1][j] : 0;
            
            if(mat[i][j] == 1) {
                dp[i][j] = 1 + min(right, min(diagonal, down));
                maxi = max(maxi, dp[i][j]);
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    
    return maxi;
}

int main() {

    vector<vector<int>> mat = {
                {0, 1, 1, 0, 1}, 
                {1, 1, 0, 1, 0},
                {0, 1, 1, 1, 0},
                {1, 1, 1, 1, 0},
                {1, 1, 1, 1, 1},  
                {0, 0, 0, 0, 0}
            };

    int row = mat.size();
    cout << "row is : " << row << endl;
    int col = mat[0].size();
    cout << "col is : " << col << endl;

    // todo: Recursive Approach
     int ans = 0;
     solve(mat , 0, 0 , ans);
     cout << "ans is : " << ans << endl;

    //todo: Recursive + Memoization Approach
    vector<vector<int>> dp(row , vector<int>(col , -1));
    int ans1 = 0;
    solveM(mat , 0, 0 , ans1 , dp);
    cout << "ans is : " << ans1 << endl;

    //todo: tabulation Approach
    int ans2 = 0;
    solveT(mat , row , col , ans2);
    cout << "ans is : " << ans2 << endl;

    // todo: Brute Force Approach
    /* vector<vector<int>> dp(row , vector<int>(col , 0));

    int ans = 0;

    //^ inserting all rows into dp array vector
    for(int i = 0; i < row; i++) {
        dp[i][0] = mat[i][0];
        // cout << "dp[i][0] is : " << dp[i][0] << endl;
        ans = max(ans , dp[i][0]);
    }

    //^ inserting all columns into dp array vector
    for(int i = 0; i < col; i++) {
        dp[0][i] = mat[0][i];
        // cout << "dp[0][i] is : " << dp[0][i] << endl;
        ans = max(ans , dp[0][i]);
    }

    for(int i = 1; i < row; i++) {
        for(int j = 1; j < col; j++) {
            if(mat[i][j] == 1) {
                dp[i][j] = 1 + min(dp[i - 1][j - 1] , min(dp[i - 1][j] , dp[i][j - 1]));
                ans = max(ans , dp[i][j]);
            }
        }
    }

    cout << "ans is : " << ans << endl; */

 return 0;
} 