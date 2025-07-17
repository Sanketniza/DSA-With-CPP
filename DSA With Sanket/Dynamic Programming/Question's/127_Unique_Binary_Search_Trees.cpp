/* 
    ? 127: Unique Binary Search Trees
    ? https://leetcode.com/problems/unique-binary-search-trees/description/?source=submission-ac

    Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 

    Example 1:


    Input: n = 3
    Output: 5
    Example 2:

    Input: n = 1
    Output: 1
    
 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int n ) {

    if(n <= 1)
        return 1;

    int ans = 0;

    //* for each node as root
    //* left subtree * right subtree
    //* i -> root node  , n - i - 1 -> right subtree , n - i - 1 -> left subtree

    for(int i = 1; i <= n; i++) {
        ans += solve(i - 1) * solve(n - i);
    }a

    return ans;
} 

int solveM(int n , vector<int> &dp ) {

    if(n <= 1)
        return 1;

    if(dp[n] != -1)
        return dp[n];

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += solveM(i - 1 , dp) * solveM(n - i , dp);
    }

    return dp[n] = ans;
}

int solveT(int n) {

    vector<int> dp(n + 1 , 0);

    dp[0] = 1;
    dp[1] = 1;

    // i -> number of nodes

    for(int i = 2; i <= n; i++) {

        // j -> root node

        for(int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }

    }
    return dp[n];
}
int main() {

    int n = 3;

    //todo: recursive approach
    int a = solve(n);
    cout << "ans is : " << a << endl;

    //todo: dp approach( bottom up)
    vector<int> dp(n + 1 , -1);
    int b = solveM(n , dp);
    cout << "ans is : " << b << endl;

    //todo: dp approach( top down)( optimized)
    int c = solveT(n);
    cout << "ans is : " << c << endl;

 return 0;
} 