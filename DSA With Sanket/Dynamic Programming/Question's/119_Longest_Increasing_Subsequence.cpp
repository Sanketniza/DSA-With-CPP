/* 
    119: Longest Increasing Subsequence
    https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

    Given an array arr[] of integers, the task is to find the length of the Longest Strictly Increasing Subsequence (LIS).

A subsequence is strictly increasing if each element in the subsequence is strictly less than the next element.

Examples:

Input: arr[] = [5, 8, 3, 7, 9, 1]
Output: 3
Explanation: The longest strictly increasing subsequence could be [5, 7, 9], which has a length of 3.
Input: arr[] = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
Output: 6
Explanation: One of the possible longest strictly increasing subsequences is [0, 2, 6, 9, 13, 15], which has a length of 6.

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int n , vector<int> &a , int curr , int prev) {
        
        // base case
        if(curr == n){
            return 0;
        }
        
        // include
        int take = 0;
            if(prev == -1 || a[curr] > a[prev] ) {
                take = 1 + solve(n , a ,curr + 1 , curr);
            }
        
        // exclde
        int notTake = 0 + solve(n , a , curr + 1 , prev);
        
        return max(take , notTake);
    }

    int solve(int n , vector<int> &a , int curr , int prev , vector<vector<int>> &dp) {
        
        // base case
        if(curr == n){
            return 0;
        }
        
        if(dp[curr][prev + 1] != -1) {
            return dp[curr][prev + 1];
        }
        
        // include
        int take = 0;
            if(prev == -1 || a[curr] > a[prev] ) {
                take = 1 + solve(n , a ,curr + 1 , curr , dp);
            }
        
        // exclde
        int notTake = 0 + solve(n , a , curr + 1 , prev , dp);
        
        return dp[curr][prev + 1] = max(take , notTake);
    }


int main() {

    vector<int> arr = {5, 8, 3, 7, 9, 1};
    int n = arr.size();
    
    // recursive approach
    // Time Complexity: O(2^n)
    // Space Complexity: O(1)

    int ans = solve(n , arr , 0 , -1);
    cout << "ans is : " << ans << endl;

    // dp approach
    vector<vector<int>> dp(n + 1 , vector<int>(n + 1 , -1));
    int ans1 = solve(n , arr , 0 , -1);
    cout << "ans is : " << ans1 << endl;


 return 0;
} 