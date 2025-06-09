#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve( int n) {

    // base case
    if(n == 0) return 0;

    if(n == 1) return 0;

    if(n == 2) return 1;

    int ans = (n - 1) * (solve(n - 1) + solve(n - 2));

    return ans;
    
}

int mamo(int n , vector<int> &dp) {

    // base case
    if(n == 0) return 0;
    if(n == 1) return 0;
    if(n == 2) return 1;

    if(dp[n] != -1) return dp[n];

    int ans = (n - 1) * (mamo(n - 1, dp) + mamo(n - 2, dp));

    return dp[n] = ans;
}

int tab(int n) {

    vector<int> dp(n + 1, 0);
    dp[0] = 0; // base case
    dp[1] = 0; // base case
    dp[2] = 1; // base case

    for(int i = 3; i <= n; i++) {
       dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    }

    return dp[n];
}

int space(int n) {

    int a = 0;
    int b = 1;
    int c;

    for(int i = 3; i <= n; i++) {

        c = (i - 1) * (a + b);
        a = b;
        b = c;
    }

    return c; // c will hold the value of dp[n]
}

int main() {

    int n = 4;

    // first way 
    int a = solve(n);
    cout << "Count of derangements using recursion: " << a << endl;

    // second way
    vector<int> dp(n + 1, -1);
    int b = mamo(n , dp);
    cout << "Count of derangements using memoization: " << b << endl;

    // third way
    int c = tab(n);
    cout << "Count of derangements using tabulation: " << c << endl;

    // fourth way
    int d = space(n);
    cout << "Count of derangements using space optimization: " << d << endl;

 return 0;
}