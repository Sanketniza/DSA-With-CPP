/* 
    ? 136: Longest Palindromic Subsequence
    ? https://leetcode.com/problems/longest-palindromic-subsequence/

    Given a string s, find the longest palindromic subsequence's length in s.

    A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

    

    Example 1:

    Input: s = "bbbab"
    Output: 4
    Explanation: One possible longest palindromic subsequence is "bbbb".
    Example 2:

    Input: s = "cbbd"
    Output: 2
    Explanation: One possible longest palindromic subsequence is "bb".
 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    int solveTab(string &a , string &b) {

        int n = a.length();
        int m = b.length();

        vector<vector<int>> dp(n + 1 , vector<int> (m + 1 , 0));

        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {

                int ans = 0;
                if(a[i] == b[j]) {
                    ans = 1 + dp[i+1][j+1];
                }

                else{
                    ans = max( dp[i+1][j] , dp[i][j + 1]);
                }

                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }

    int solveSpace(string &a , string &b) {

        int n = b.length();
        int m = a.length();
        vector<int> curr(n + 1 , 0);
        vector<int> next(n + 1 , 0);

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {

                int ans = 0;

                if(a[i] == b[j]) {
                    ans = 1 + next[j + 1];
                }

                else {
                    ans = max(next[j] , curr[j+1]);
                }

                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }

    int solveM(string &a , string &b , int i , int j , vector<vector<int>> &dp) {

        //base case
        if(i == a.length() || j == b.length())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];    

        int ans = 0;

        if(a[i] == b[j]) {
            ans = 1 + solveM(a , b, i+ 1, j + 1 , dp);
        }    

        else {
            ans = max( solveM(a , b , i + 1, j , dp) , solveM(a , b ,i , j + 1 , dp) );
        }

        return dp[i][j] = ans;
    }


    int solve(string &a , string &b , int i , int j) {

        //base case
        if(i == a.length() || j == b.length())
            return 0;

        int ans = 0;

        if(a[i] == b[j]) {
            ans = 1 + solve(a , b, i+ 1, j + 1);
        }    

        else {
            ans = max( solve(a , b , i + 1, j) , solve(a , b ,i , j + 1) );
        }

        return ans;
    }

int main() {

    string a = "bbbab";
    string b = a;
    reverse(b.begin() , b.end());


    //todo: Recursive
    cout << "ans is : " << solve(a , b , 0 , 0) << endl;

    //todo: Memoization
    vector<vector<int>> dp(a.length() , vector<int> (b.length() , -1));
    cout << "ans is : " << solveM(a , b , 0 , 0 , dp) << endl;

    //todo: Tabulation
    cout << "ans is : " << solveTab(a , b) << endl;

    //todo: Tabulation Space Optimized
    cout << "ans is : " << solveSpace(a , b) << endl;


 return 0;
}