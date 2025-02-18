/*  
    ? 132: Buy and Sell Stock
    ? https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

    You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 


 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    int solve(int index , int buy , vector<int> &prices , int limit) {

        // base case
        if(index == prices.size())
            return 0;

        if(limit == 0)
            return 0;

        int profit = 0;

        // if we can buy the stock
        if(buy) {
            // we can either buy the stock or skip it
            int buyKiya = -prices[index] + solve(index + 1 , 0 , prices , limit);
            int skipKiya = 0 + solve(index + 1, 1 , prices , limit);
            profit = max(buyKiya , skipKiya);
        } 
        // if we can sell the stock
        else {
            // we can either sell the stock or skip it
            int sellKiya = prices[index] + solve(index + 1 , 1 , prices , limit - 1);
            int skipKiya = 0 + solve(index + 1 , 0 , prices , limit);
            profit = max(sellKiya , skipKiya);
        } 

        return profit;      
    }


    int solveM(int index , int buy , vector<int> &prices, int limit ,  vector<vector<vector<int>>> &dp) {

            // base case
        if(index == prices.size())
            return 0;

        if(limit == 0)
            return 0;

        if(dp[index][buy][limit] != -1) 
            return dp[index][buy][limit];    

        int profit = 0;

        // if we can buy the stock
        if(buy) {
            // either we buy the stock or we skip
            int buyKiya = -prices[index] + solveM(index + 1 , 0 , prices , limit , dp);
            int skipKiya = 0 + solveM(index + 1, 1 , prices , limit, dp);
            profit = max(buyKiya , skipKiya);
        } 
        // if we can sell the stock
        else {
            // either we sell the stock or we skip
            int sellKiya = prices[index] + solveM(index + 1 , 1 , prices ,limit - 1 , dp );
            int skipKiya = 0 + solveM(index + 1 , 0 , prices , limit , dp);
            profit = max(sellKiya , skipKiya);
        } 

        return dp[index][buy][limit] = profit; 

    }

    int solveT(vector<int> &prices) {

        int n = prices.size();    
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2 , vector<int> (3 , 0) ) );

        for(int index = n - 1; index >= 0; index--) {
            for(int buy = 0; buy <=1 ; buy++ ) {
                for(int limit = 1; limit <= 2; limit++) {

                     int profit = 0;

                    if(buy) {
                        int buyKiya = -prices[index] + dp[index + 1][0][limit];
                        int skipKiya = 0 + dp[index + 1][1][limit];
                        profit = max(buyKiya , skipKiya);
                    } 
                    else {
                        int sellKiya = prices[index] + dp[index + 1][1][limit - 1];
                        int skipKiya = 0 + dp[index + 1][0][limit];
                        profit = max(sellKiya , skipKiya);
                    } 

                   dp[index][buy][limit] = profit; 

                }  
            }
        }

        return dp[0][1][2];
    }

    int solveS(vector<int> &prices) {

        int n = prices.size();    
        vector<vector<int>> curr(2 , vector<int> (3 , 0));
        vector<vector<int>> next(2 , vector<int> (3 , 0));

        for(int index = n - 1; index >= 0; index--) {
            for(int buy = 0; buy <=1 ; buy++ ) {
                for(int limit = 1; limit <= 2; limit++) {

                     int profit = 0;

                    if(buy) {
                        int buyKiya = -prices[index] + next[0][limit];
                        int skipKiya = 0 + next[1][limit];
                        profit = max(buyKiya , skipKiya);
                    } 
                    else {
                        int sellKiya = prices[index] + next[1][limit - 1];
                        int skipKiya = 0 + next[0][limit];
                        profit = max(sellKiya , skipKiya);
                    } 

                   curr[buy][limit] = profit; 

                }  

            }
                next = curr;
                
        }

        return next[1][2];
    }

int main() {

    vector<int> prices = {3,3,5,0,0,3,1,4};
    int n = prices.size();

    //todo: Recursive Approach
    int a = solve(0 , 1 , prices , 2); // 2 is the number of transactions(limit)
    cout << "Max Profit is : " << a << endl;

    //todo: Memoization Approach
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2 , vector<int> (3 , -1) ) );
    int b = solveM(0 , 1 , prices , 2 , dp);
    cout << "Max Profit is : " << b << endl;

    //todo: Tabulation Approach
    int c = solveT(prices);
    cout << "Max Profit is : " << c << endl;

    //todo: Space Optimized Approach
    int d = solveS(prices);
    cout << "Max Profit is : " << d << endl;


 return 0;
} 