
/* 
    ? 121:  
    ? https://leetcode.com/problems/pizza-with-3n-slices/description/  

    There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:

You will pick any pizza slice.
Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
Your friend Bob will pick the next slice in the clockwise direction of your pick.
Repeat until there are no more slices of pizzas.
Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.

 

Example 1:


Input: slices = [1,2,3,4,5,6]
Output: 10
Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively. Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.
Example 2:


Input: slices = [8,9,8,6,1,1]
Output: 16
Explanation: Pick pizza slice of size 8 in each turn. If you pick slice with size 9 your partners will pick slices of size 8.


 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int index , int endPoint , vector<int> &slices , int k) {

    // base case
    if(k == 0 || index > endPoint) {
        return 0;
    }

    // recursive case

    // if we take the current slice
    int take = slices[index] + solve(index + 2 , endPoint , slices , k - 1);
    int nottake = 0 + solve(index + 1, endPoint , slices , k);

    return max(take , nottake);
}

int solveM(int index , int endPoint , vector<int> &slices , int k , vector<vector<int> > dp) {

    // base case
    if(k == 0 || index > endPoint) {
        return 0;
    }

    // recursive case
    if(dp[index][k] != -1) {
        return dp[index][k];
    }

    // if we take the current slice
    int take = slices[index] + solveM(index + 2 , endPoint , slices , k - 1 , dp);
    int nottake = 0 + solveM(index + 1, endPoint , slices , k , dp);

    return dp[index][k] = max(take , nottake);
}

 int solveTab(vector<int> &slices){

        int n = slices.size();

        vector<vector<int>> dp1(n + 2 ,vector<int> (n + 2 ,0));

        for(int index = n - 2 ; index >= 0; index--) {
            for(int k = 1; k <= n/3; k++) {

                int take = slices[index] + dp1[index + 2][k - 1];
                int nottake = 0 + dp1[index + 1][k];

                dp1[index][k] = max(take , nottake);
            }
        }

        int case1 = dp1[0][n/3];

        vector<vector<int>> dp2(n + 2 ,vector<int> (n + 2 ,0));

        for(int index = n - 1; index >= 1; index--) {
            for(int k = 1 ; k <= n/3; k++) {
                int take = slices[index] + dp2[index + 2][k - 1];
                int nottake = 0 + dp2[index + 1][k];

                dp2[index][k] = max(take , nottake);
            }
        }

        int case2 = dp2[1][n/3];

        return max(case1 , case2);
    }

int solveSpaceOpt(vector<int> &slices) {

    int n = slices.size();

    vector<int> prev1(n + 2 , 0);
    vector<int> curr1(n + 2 , 0);
    vector<int> next1(n + 2 , 0);

    for(int index = n - 2; index >= 0; index--) {
        for(int k = 1; k <= n/3; k++) {
            int take = slices[index] + next1[k - 1];
            int nottake = 0 + curr1[k];

            prev1[k] = max(take , nottake);
        }

        next1 = curr1;
        curr1 = prev1;
    }

    int case1 = curr1[n/3];

    vector<int> prev2(n + 2 , 0);
    vector<int> curr2(n + 2 , 0);
    vector<int> next2(n + 2 , 0);

    for(int index = n - 1; index >= 1; index--) {
        for(int k = 1; k <= n/3; k++) {
            int take = slices[index] + next2[k - 1];
            int nottake = 0 + curr2[k];

            prev2[k] = max(take , nottake);
        }

        next2 = curr2;
        curr2 = prev2;
    }

    int case2 = curr2[n/3];

    return max(case1 , case2);
}

int main() {

    vector<int> slices = {1,2,3,4,5,6};
    int n = slices.size();

    //todo: Recursive approach
    int case1 = solve(0 , n - 2 , slices , n / 3);
    int case2 = solve(1 , n - 1 , slices , n / 3);
    int ans = max(case1 , case2);
    cout << "ans is : " << ans << endl;

    //todo: DP approach (Top Down) (recursive + memoization)

    vector<vector<int>> dp1(n , vector<int>(n , -1));
    int case3 = solveM(0 , n - 2 , slices , n / 3 , dp1);

    vector<vector<int>> dp2(n , vector<int>(n , -1));
    int case4 = solveM(1 , n - 1 , slices , n / 3 , dp2);

    // int ans1 = max(case3 , case4);
    // cout << "ans is : " << ans1 << endl;
    cout << "ans is : " << max(case3 , case4) << endl;

    //todo: Tabulation approach (Bottom Up)
     
    int ans2 = solveTab(slices);
    cout << "ans is : " << ans2 << endl;

    //todo: space optimized approach
    int ans3 = solveSpaceOpt(slices);
    cout << "ans is : " << ans3 << endl; 


 return 0;
} 