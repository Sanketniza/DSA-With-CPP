#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int n , int x , int y , int z) {
    
    // base case
    if(n == 0) return 0;
    if(n < 0) return INT_MIN;

    // recursive call
    int a = solve( n - x , x , y , z) + 1;
    int b = solve( n - y , x , y , z) + 1;
    int c = solve( n - z , x , y , z) + 1;

    int ans = max(a , max(b , c));
    return ans;
}

int d(int n , int x , int y , int z , vector<int> &dp) {

    // base case
    if(n == 0) return 0;
    if(n < 0) return INT_MIN;

    // check if already computed
    if(dp[n] != -1) return dp[n];

    // recursive call
    int a = d(n - x, x, y, z, dp) + 1;
    int b = d(n - y, x, y, z, dp) + 1;
    int c = d(n - z, x, y, z, dp) + 1;

    int ans = max(a, max(b, c));

    return  dp[n] = ans; // store the result in dp array
 
}

int SolveTab(int n , int x , int y , int z) {

    vector<int> dp(n + 1 , INT_MIN); //if(n < 0) return INT_MIN;
    dp[0] = 0; // base case if(n == 0) return 0;

    for(int i = 1; i <= n; i++) {

        if(i - x >= 0)
            dp[i] = max(dp[i] , dp[i - x] + 1);

        if(i - y >= 0)
            dp[i] = max(dp[i] , dp[i - y] + 1);

        if(i - z >= 0)
            dp[i] = max(dp[i] , dp[i - z] + 1);

    }

    return  dp[n];
}

int main() {

    int n = 7; // Length of the rod
    int x = 5; // Length of segment X
    int y = 2; // Length of segment Y
    int z = 2; // Length of segment Z

    // recursive way
    int ans = solve(n , x , y , z);

    if(ans < 0) {
        cout << "No valid segments can be cut." << endl;
    } else {
        cout << "Maximum number of segments that can be cut: " << ans << endl;
    }

    // dp
    vector<int> dp(n + 1, -1);
    int dpAns = d(n , x , y , z , dp);
    if(dpAns < 0) {
        cout << "No valid segments can be cut using DP." << endl;
    } else {
        cout << "Maximum number of segments that can be cut using DP: " << dpAns << endl;
    }

    // tabulation way
    int tabAns = SolveTab(n , x , y , z);
    if(tabAns < 0) {
        cout << "No valid segments can be cut using Tabulation." << endl;
    } else {
        cout << "Maximum number of segments that can be cut using Tabulation: " << tabAns << endl;
    }

 return 0;
}