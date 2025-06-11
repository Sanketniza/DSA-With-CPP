#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int n) {

    // base case
    if(n == 0) {
        return 0;
    }

    if( n == 1) return 1;

    int ans = INT_MAX;
    for(int i = 1; i * i <= n; i++) {
        ans = min(ans , solve(n - i * i ) + 1);
    }

    return ans;
}

int memo(int n , vector<int> &dp) {

    // base case
    if(n == 0) {
        return 0;
    }

    if(n == 1) return 1;

    if(dp[n] != -1) {
        return dp[n];
    }

    int ans = INT_MAX;

    for(int i = 1; i * i <= n; i++) {
        ans = min(ans , memo(n - i * i , dp) + 1);
    }

    dp[n] = ans;

    return dp[n];
}

int tap(int n) {

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    // dp[1] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j * j <= n; j++) {
            // dp[j] = min(dp[j], dp[j - i * i] + 1);
            if(i - j * j >= 0) // Check to avoid negative index
                dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    return dp[n];
}

int main() {

    int n = 14;

    // Recursive approach
    cout << "Recursive approach: " << solve(n) << endl;

    // memoization approach
    vector<int> dp(n + 1 , -1);
    cout << "Memoization approach: " << memo(n, dp) << endl;

    // Iterative approach
    cout << "Iterative approach: " << tap(n) << endl;

 return 0;
}