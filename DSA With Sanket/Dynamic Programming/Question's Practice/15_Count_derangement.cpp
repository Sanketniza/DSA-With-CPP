#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveRec(int n ) {

    if(n == 1) return 0;
    if(n == 2) return 1;

    int ans = (n - 1) * (solveRec(n - 2) + solveRec(n - 1));
    return ans;
}

int solveMem(int n , vector<int> &dp) {

    // base case
    if( n == 1 ) return 0;
    if( n == 2 ) return 1;

    if(dp[n] != -1) return dp[n];

    int ans =  (n - 1) * (solveMem(n - 1 , dp) + solveMem(n - 2 , dp));
    dp[n] = ans;
    return dp[n];
}

int solveTab(int n ) {

    // create vector
    vector<int> dp(n + 1 , 0);
    dp[1] = 0;
    dp[2] = 1;

    for(int i = 3; i <= n; i++) {
        int ans = (i - 1) * (dp[i - 2] + dp[i - 1]);
        dp[i] = ans;
    }

    return dp[n];
}


int main() {

    int n = 3;

    int ans = solveRec(n);

    if(ans < 0) {
        cout << "Not Possible" << endl;
    }

    else {
        cout << ans << endl;
    }

    // using memoization
    vector<int> dp(n + 1, -1);
    int a = solveMem(n , dp);

    if(a < 0) {
        cout << "Not Possible" << endl;
    }

    else {
        cout << a << endl;
    }

    // using tabulation
    int b = solveTab(n);

    if(b < 0) {
        cout << "Not Possible" << endl;
    }

    else {
        cout << b << endl;
    }
 return 0;
}