/* 
    ? House Robber
    ? https://leetcode.com/problems/house-robber/?envType=problem-list-v2&envId=dynamic-programming

    You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int index , vector<int> &arr) {

    // base case
    if(index >= arr.size()) return 0;

    int include = 0;
    include = arr[index] + solve(index + 2 , arr);

    int exclude = 0 + solve(index + 1 , arr);

    int ans = max(include , exclude);
    return ans;
    // return max(include , exclude);
}

int solveM(int index , vector<int> &arr , vector<int> &dp) {

    // base case
    if(index >= arr.size()) return 0;

    if(dp[index] != -1) return dp[index];

    int include = 0;
    include = arr[index] + solveM(index + 2 , arr , dp);

    int exclude = 0 + solveM(index + 1 , arr , dp);

    int ans = max(include , exclude);
    dp[index] = ans;
    return dp[index];
    // return max(include , exclude);
}

int solveTab( vector<int> &arr) {

    int n = arr.size();

    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return arr[0];
    }

    // crate dp
    vector<int> dp(arr.size() + 1 , 0);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for(int i = 2; i < arr.size(); i++) {
        int include = arr[i] + dp[i - 2];
        int exclude = dp[i - 1];
        dp[i] = max(include , exclude);
        // dp[i] = max(arr[i] + dp[i - 2] + dp[i - 1]);
    }

    return dp[n - 1];
}

int main() {

    vector<int> nums = {1, 2, 3, 1};

    int n = nums.size();

        //> Recursion
        // int ans = solve(0 , nums);
        // return ans;
        // return solve(0 , nums);

        //> Memorization 
        // vector<int> dp(n + 1 , -1);
        // int ans = solveM(0 , nums , dp);
        // return ans;

        //> Tabulation
        cout << "ans is : " << solveTab(nums);

 return 0;
}