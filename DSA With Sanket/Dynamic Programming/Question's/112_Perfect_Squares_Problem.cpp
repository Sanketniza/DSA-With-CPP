/* 
    112: Perfect Squares Problem
    https://www.youtube.com/watch?v=aJTCcyPrPOA&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=121

    Get Minimum Squares
    Difficulty: MediumAccuracy: 45.22%Submissions: 38K+Points: 4
    Given a number n, find the minimum number of perfect squares (square of an integer) that sum up to n. 

    Examples:

    Input: n = 100
    Output: 1
    Explanation: 10 * 10 = 100
    Input: n = 6
    Output: 3
    Explanation = 1 * 1 + 1 * 1 + 2 * 2 = 6 
    Expected Time Complexity: O(n * sqrt(n))
    Expected Space Complexity: O(n)

    Constraints:
 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Recursive approach 1
int solve(int n) {

    // base case
    if(n == 0) {
        return 0;
    }

    int ans = INT_MAX;
    for(int i = 1; i * i <= n; i++) {
        ans = min(ans, solve(n - i * i) + 1);
    }

    return ans;
}

// Recursive approach 2 , using memoization
int solveM(int n, vector<int> &dp) {

    // base case
    if(n == 0) {
        return 0;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    int ans = INT_MAX;
    for(int i = 1; i * i <= n; i++) {
        ans = min(ans, solveM(n - i * i, dp) + 1);
    }

    dp[n] = ans;
    return dp[n];
}

// Iterative approach
int solveI(int n) {

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    return dp[n];
}

int main() {

    int n = 5;

    // Recursive approach 1 
    int ans = solve(n);
    cout << "ans is : " << ans << endl;

    // Recursive approach 2 , using memoization
    vector<int> dp(n + 1, -1);
    int ansM = solveM(n, dp);
    cout << "ansM is : " << ansM << endl;

    // Iterative approach
    int ansI = solveI(n);
    cout << "ansI is : " << ansI << endl;


 return 0;
} 