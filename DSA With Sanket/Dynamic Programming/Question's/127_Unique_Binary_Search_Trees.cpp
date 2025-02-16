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

    // for each node as root
    // left subtree * right subtree
    // i -> root node  , n - i - 1 -> right subtree , n - i - 1 -> left subtree

    for(int i = 1; i <= n; i++) {
        ans += solve(i - 1) * solve(n - i);
    }

    return ans;
} 

int main() {

    int n = 3;

    //todo: recursive approach
    int a = solve(n);
    cout << "ans is : " << a << endl;
 return 0;
} 