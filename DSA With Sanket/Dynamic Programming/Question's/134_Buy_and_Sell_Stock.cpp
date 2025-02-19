/* 
    ? 134: Buy and Sell Stock
    ? https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

    You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

    Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

    Note:

    You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
    The transaction fee is only charged once for each stock purchase and sale.
    

    Example 1:

    Input: prices = [1,3,2,8,4,9], fee = 2
    Output: 8
    Explanation: The maximum profit can be achieved by:
    - Buying at prices[0] = 1
    - Selling at prices[3] = 8
    - Buying at prices[4] = 4
    - Selling at prices[5] = 9
    The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
    Example 2:

    Input: prices = [1,3,7,5,10,3], fee = 3
    Output: 6

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int index , int buy , vector<int> &price , int fee) {

    // base case
    if(index == price.size())
        return 0;

    int profit = 0;

    if(buy) {
        int buyKiya = -price[index] + solve(index + 1 , 0 , price , fee);
        int skipKiya = 0 + solve(index + 1 , 1 , price , fee);
        profit = max(buyKiya , skipKiya);
    }

    else {
        int sellKiya = price[index] - fee + solve(index + 1 , 1 , price , fee);
        int skipKiya = 0 + solve(index + 1 , 0 , price , fee);
        profit = max(sellKiya , skipKiya);
    }

    return profit;
}

int solveM(int index , int buy , vector<int> &price , int fee , vector<vector<int>> &dp) {

    // base case
    if(index == price.size())
        return 0;

    if(dp[index][buy] != -1)
        return dp[index][buy];

    int profit = 0;

    if(buy) {
        int buyKiya = -price[index] + solveM(index + 1 , 0 , price , fee , dp);
        int skipKiya = 0 + solveM(index + 1 , 1 , price , fee , dp);
        profit = max(buyKiya , skipKiya);
    }

    else {
        int sellKiya = price[index] - fee + solveM(index + 1 , 1 , price , fee , dp);
        int skipKiya = 0 + solveM(index + 1 , 0 , price , fee , dp);
        profit = max(sellKiya , skipKiya);
    }

    return dp[index][buy] = profit;
}

int solveTab(vector<int> &price , int fee) {

    int n = price.size();
    vector<vector<int>> dp(n + 1 , vector<int> (2 + 1 , 0));

    for(int index = n - 1; index >= 0; index--) {
        for(int buy = 0; buy <= 1; buy++) {

            int profit = 0;

            if(buy) {
                int buyKiya = -price[index] + dp[index + 1][0];
                int skipKiya = 0 + dp[index + 1][1];
                profit = max(buyKiya , skipKiya);
            }

            else {
                int sellKiya = price[index] - fee + dp[index + 1][1];
                int skipKiya = 0 + dp[index + 1][0];
                profit = max(sellKiya , skipKiya);
            }

            dp[index][buy] = profit;
        }
    }
    return dp[0][1];
}

int solveTabulationSpaceOptimized(vector<int> &price , int fee) {

    int n = price.size();
    vector<int> curr(2 , 0);
    vector<int> next(2 , 0);

    for(int index = n - 1; index >= 0; index--) {
        for(int buy = 0; buy <= 1; buy++) {

            int profit = 0;

            if(buy) {
                int buyKiya = -price[index] + next[0];
                int skipKiya = 0 + next[1];
                profit = max(buyKiya , skipKiya);
            }

            else {
                int sellKiya = price[index] - fee + next[1];
                int skipKiya = 0 + next[0];
                profit = max(sellKiya , skipKiya);
            }

            curr[buy] = profit;
        }
        next = curr;
    }

    return next[1];
}
int main() {

    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
    int n = prices.size();

    //! HINT: use the same approach as 131_Buy_and_Sell_Stock.cpp with a slight modification

    //todo: Recursive Approach
        int a = solve(0 , 1 , prices , fee); 
        // 0 -> starting index ,  1 -> allowed to buy , 0 -> not allowed to buy (sell only)
        cout << "ans is : " << a << endl;

    //todo: Memoization
        vector<vector<int>> dp(n , vector<int> (2 , -1));
        // n -> size of the prices vector , 2 -> 2 states (buy or sell)
        int b = solveM(0 , 1 , prices , fee , dp);
        cout << "ans is : " << b << endl;

    //todo: Tabulation
        int c = solveTab(prices , fee);
        cout << "ans is : " << c << endl;

    //todo: Space Optimized Tabulation
         int d = solveTabulationSpaceOptimized(prices , fee);
         cout << "ans is : " << d << endl;

    

 return 0;
} 