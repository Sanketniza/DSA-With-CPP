/* 
    ? 139: Wildcard Pattern Matching
    ? https://leetcode.com/problems/wildcard-matching/description/

    Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

    '?' Matches any single character.
    '*' Matches any sequence of characters (including the empty sequence).
    The matching should cover the entire input string (not partial).

    

    Example 1:

    Input: s = "aa", p = "a"
    Output: false
    Explanation: "a" does not match the entire string "aa".
    Example 2:

    Input: s = "aa", p = "*"
    Output: true
    Explanation: '*' matches any sequence.
    Example 3:

    Input: s = "cb", p = "?a"
    Output: false
    Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* int solve(string &s , string &p , int i , int j) {

    //base case
    if(i == s.length() && j == p.length())
        return 1;

    if(j == p.length())
        return 0;

    if(i == s.length()) {
        for(int k = j; k < p.length(); k++) {
            if(p[k] != '*')
                return 0;
        }
        return 1;
    }

    if(s[i] == p[j] || p[j] == '?') {
        return solve(s , p , i + 1 , j + 1);
    }

    if(p[j] == '*') {
        return solve(s , p , i + 1 , j) || solve(s , p , i , j + 1);
    }

    return 0;
} */

    int solve(string &a , string &b , int i , int j) {

        // base case

        if(i < 0 && j < 0) {
            return 1;
        }

        if(i >= 0 && j < 0) {
            return 0;
        }

        if(i < 0 && j >= 0) {
            for(int k = 0; k <= j; k++) {
                if(b[k] != '*') {
                    return 0;
                }
            }
            return 1;
        }

        if(a[i] == b[j] || b[j] == '?') {
            return solve(a , b , i - 1 , j - 1);
        }

        else if(b[j] == '*') {
            return solve(a , b , i - 1 , j) || solve(a , b , i , j - 1);
        }

        return 0;
    }

    int solveM(string &str , string &pattern , int i , int j , vector<vector<int>>&dp) {

        //base cases

        if(i < 0 && j < 0 ) {
            return 1;
        }

        if(i >= 0 && j < 0) {
            return 0;
        }

        if(i < 0 && j >= 0) {
            for(int k = 0; k <= j; k++) {
                if(pattern[k] != '*') {
                    return 0;
                }
            }
            return 1;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(str[i] == pattern[j] || pattern[j] == '?') {
            dp[i][j] = solveM(str , pattern , i - 1 , j - 1 , dp);
            return dp[i][j];
        }

        else if(pattern[j] == '*') {
            dp[i][j] = solveM(str , pattern , i - 1 , j , dp) || solveM(str , pattern , i , j - 1 , dp);
            return dp[i][j];
        }

        else {
           dp[i][j] = 0;
        }

        return dp[i][j];
    }

        int solveMM(string &str , string &pattern , int i , int j , vector<vector<int>> &dp) {

        // base cases

        if(i == 0 && j == 0) {
            return true;
        }

        if(i > 0 && j == 0) {
            return false;
        }

        if(i == 0 && j > 0) {
            for(int k = 1; k <= j; k++) {
                if(pattern[k - 1] != '*') {
                    return false;
                }
            }
            return true;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // recu

        if(str[i -1] == pattern[j - 1] || pattern[j - 1] == '?') {
            return dp[i][j] = solveMM(str , pattern , i - 1 , j - 1 , dp);
        }

        else if(pattern[j -1] == '*') {
            return dp[i][j] = ( solveMM(str , pattern , i - 1 , j ,dp ) || solveMM(str, pattern , i , j - 1, dp));
        }

        else {
            return false;
        }

    }


    int solveT(string &a , string &b ) {

        int n = a.length();
        int m = b.length();
        vector<vector<int>> dp(n + 1 , vector<int> (m + 1 , 0));

        // base case
        dp[0][0] = 1;

        for(int j = 1; j <= m; j++) {
            if(b[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(a[i - 1] == b[j - 1] || b[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                else if(b[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }

                else {
                    dp[i][j] = 0;
                }
            }
        }

        return dp[n][m];
    }

    int solveS(string &str , string &pattern) {

        int n = str.length();
        int m = pattern.length();

        vector<int> curr(m + 1 , 0);
        vector<int> prev(m + 1 , 0);

        // base case
        prev[0] = true;

        for(int j = 1; j <= m; j++) {
            if(pattern[j - 1] == '*') {
                prev[j] = prev[j - 1];
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(str[i - 1] == pattern[j - 1] || pattern[j - 1] == '?') {
                    curr[j] = prev[j - 1];
                }

                else if(pattern[j - 1] == '*') {
                    curr[j] = (prev[j] || curr[j - 1]);
                }

                else {
                    curr[j] = false;
                }
            }

            prev = curr;
            fill(curr.begin() , curr.end() , 0);
        }

        return prev[m];
    }

int main() {

    string s = "adceb";
    string p = "*a*b";

    int n = s.length();
    int m = p.length();

    //todo: Recursive Approach
        int a = solve(s , p , 0 , 0);
        cout << "ans is : " << a << endl;
    
    //todo: dp approach (top down)
        vector<vector<int>> dp(n , vector<int> (m , -1));
        int b = solveM(s , p , 0 , 0 , dp); // zero base indexing
        cout << "ans is : " << b << endl;


        vector<vector<int>> dpp(n + 1 , vector<int> (m + 1 , -1));
        int d =  solveMM(s , p ,  n  , m  , dpp); // one base indexing
        cout << "ans is : " << d << endl;


    //todo: Tabulation (bottom up)
        int c = solveT(s , p);
        cout << "ans is : " << c << endl;    

    //todo: Space Optimization
        // int e = solveS(s , p);
        // cout << "ans is : " << e << endl;    

 return 0;
}