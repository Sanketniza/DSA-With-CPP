#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int fib(int n , vector<int> &dp) {
    
    // base case
    if(n <= 1) {
        return n;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    // recursive case
    int x = fib(n - 1, dp) + fib(n - 2, dp);
    dp[n] = x; // store the result in dp array

    // dp[n] = fib(n - 1, dp) + fib(n - 2, dp); // alternative way to write
    return dp[n];
}

int main() {

    int n = 10;

    // top - down approach

    // create dp array with -1 val
    vector<int> dp(n + 1, -1);

    int ans = fib(n, dp);
    cout << "ans is : " << ans << endl;

 return 0;
}