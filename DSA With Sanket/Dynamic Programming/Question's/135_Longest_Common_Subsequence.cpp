
/* 
    ? 135: Longest Common Subsequence
    ? https://leetcode.com/problems/longest-common-subsequence/description/

    Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

    A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

    For example, "ace" is a subsequence of "abcde".
    A common subsequence of two strings is a subsequence that is common to both strings.

    

    Example 1:

    Input: text1 = "abcde", text2 = "ace" 
    Output: 3  
    Explanation: The longest common subsequence is "ace" and its length is 3.
    Example 2:

    Input: text1 = "abc", text2 = "abc"
    Output: 3
    Explanation: The longest common subsequence is "abc" and its length is 3.
    Example 3:

    Input: text1 = "abc", text2 = "def"
    Output: 0
    Explanation: There is no such common subsequence, so the result is 0.
    
 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(string &a , string &b , int i , int j) {

    //base case
    if(i == a.size() || j == b.size()) {
        return 0;
    }

    //recursive case
    int ans = 0;

    if(a[i] == b[j]) {
        ans = 1 + solve(a , b , i + 1 , j + 1);
    }

    else {
        int op1 = solve(a , b , i + 1 , j);
        int op2 = solve(a , b , i , j + 1);
        ans = max(op1 , op2);
    }

    return ans;
}

int solveM(string &a , string &b , int i , int j , vector<vector<int>> &dp) {

    //base case
    if(i == a.size() || j == b.size()) {
        return 0;
    }

    //check
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    //recursive case
    int ans = 0;

    if(a[i] == b[j]) {
        ans = 1 + solveM(a , b , i + 1 , j + 1 , dp);
    }

    else {
        int op1 = solveM(a , b , i + 1 , j , dp);
        int op2 = solveM(a , b , i , j + 1 , dp);
        ans = max(op1 , op2);
    }

    return dp[i][j] = ans;
}

int solveTabulation(string &a , string &b) {

    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n + 1 , vector<int> (m + 1 , 0));

    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {

            int ans;
            if(a[i] == b[j]) {
                dp[i][j] = 1 + dp[i + 1][j + 1];
                // ans = 1 + dp[i + 1][j + 1];
            }

            else {
                dp[i][j] = max(dp[i + 1][j] , dp[i][j + 1]);
                // ans = max(dp[i + 1][j] , dp[i][j + 1]);
            }

            // dp[i][j] = ans;
        }
    }

    return dp[0][0];
}

int solveTabulationSpaceOptimized(string &a , string &b) {

        vector<int> curr(b.length() + 1 , 0);
        vector<int> next(b.length() + 1 , 0);

        for(int i = a.length() - 1; i >= 0; i--) {
            for(int j = b.length() - 1; j >= 0; j--) {

                int ans = 0;

                if(a[i] == b[j]) {
                    ans = 1 + next[j+1];
                }      

                else {
                    ans = max( next[j], curr[j+1] );
                }    

                curr[j] = ans;  
                
            }
            next = curr;
        }

        return next[0];
    }

int main() {

    string text1 = "abcde";
    string text2 = "ace";

    int n = text1.size();
    int m = text2.size();

    //todo: Recursive
       int a = solve(text1 , text2 , 0 , 0); // 0 is starting  index of text1 , 0 is starting  index of text2
       cout << "ans is : " << a << endl;

    //todo: Memoization
        vector<vector<int>> dp(n , vector<int> (m , -1));
        int b = solveM(text1 , text2 , 0 , 0 , dp);
        cout << "ans is : " << b << endl;

    //todo: Tabulation
        int c = solveTabulation(text1 , text2);
        cout << "ans is : " << c << endl;

    //todo: space optimized tabulation
        int d = solveTabulationSpaceOptimized(text1 , text2);
        cout << "ans is : " << d << endl;           



 return 0;
} 