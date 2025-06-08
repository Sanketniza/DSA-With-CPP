#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &cost , int n) {

    // base case
    if(n == 0) return cost[0];

    if(n == 1) return   cost[1];

    int ans = cost[n] + min(solve(cost , n - 1) , solve(cost , n - 2));
    return ans;
}

int solve1(vector<int> &cost , int n , vector<int> &dp) {
    
    // base case
    if(n == 0) return cost[0];
    if(n == 1) return cost[1];

    if(dp[n] != -1) return dp[n];

    int ans = cost[n] + min(solve1(cost , n - 1 , dp) , solve1(cost , n - 2 , dp));
    dp[n] = ans;
    return dp[n];
    // return dp[n] = ans; // This line can also be used directly
}

int main() {

    int m;
    cout << "Enter the number of steps: ";
    cin >> m;

    vector<int> cost(m);
    cout << "Enter the cost of each step: " << endl;
    for(int i = 0; i < m; i++) {
        cin >> cost[i];
    }

    int n = cost.size();

    // recursive only
    int a = min(solve(cost , n - 1) , solve(cost , n - 2));
    cout << "ans is : " << a << endl;

    // Approach 1: Top-Down (Recursive + Memoization)
    vector<int> dp(n + 1 , -1);
    int b = min(solve1(cost , n - 1 , dp) , solve1(cost , n - 2 , dp));
    cout << "ans is : " << b << endl;

 return 0;
}