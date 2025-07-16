#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int n , vector<int> &dp) {

    // base case
    if(n <= 1) return 1;
    if(dp[n] != -1) return dp[n];

    int ans = 0;

    // each node as root(i);
    // left subtree (i - 1) * right subtree (n - i)
    for(int i = 1; i <= n; i++) {
        ans += solve(i - 1 , dp) * solve(n - i , dp);
    }

    dp[n] = ans;
    return dp[n];
}

int solveTab(int n) {

    vector<int> dp(n + 1, 0);
    dp[0] = 1; // 0 nodes, 1 unique BST (empty tree)

    dp[1] = 1; // 1 node, 1 unique BST (the node itself)

    // i -> number of nodes
    for(int i = 2; i <= n; i++) {
        // j -> root node
        for(int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }

    return dp[n ]; // return the number of unique BSTs with n nodes
}

int main() {

    int n = 3;

    vector<int> dp(n + 1, -1);
    int ans = solve(n , dp);
    cout << "Number of unique BSTs with " << n << " nodes: " << ans << endl;

    // Time Complexity: O(n^2)
    // Space Complexity: O(n) for the dp array

    int ans1 = solveTab(n);
    cout << "Number of unique BSTs with " << n << " nodes: " << ans1 << endl;

 return 0;
}