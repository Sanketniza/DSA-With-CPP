/* 
    ? 133: Buy and Sell Stock
    ? https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

    You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

    Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

    Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

    

    Example 1:

    Input: k = 2, prices = [2,4,1]
    Output: 2
    Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
    Example 2:

    Input: k = 2, prices = [3,2,6,5,0,3]
    Output: 7
    Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveTabulation(vector<int> &prices , int k) {

    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1 , vector<vector<int>> (2 , vector<int> (k + 1 , 0)));

    for(int index = n - 1; index >= 0; index--) {
        for(int buy = 0; buy <=1 ; buy++ ) {
            for(int limit = 1; limit <= k; limit++) {

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

    return dp[0][1][k];
}

int solveTabulationSpaceOptimized(vector<int> &prices , int k) {

    // Get the size of the prices vector
    int n = prices.size();
    // Create two 2D vectors to store the current and next states
    vector<vector<int>> curr(2 , vector<int> (k + 1 , 0));
    vector<vector<int>> next(2 , vector<int> (k + 1 , 0));

    // Iterate through the prices vector from the end to the beginning
    for(int index = n - 1; index >= 0; index--) {
        // Iterate through the buy state
        for(int buy = 0; buy <=1 ; buy++ ) {
            // Iterate through the limit
            for(int limit = 1; limit <= k; limit++) {

                // Initialize the profit to 0
                int profit = 0;

                // If the current state is buy
                if(buy) {
                    // Calculate the profit if we buy the stock
                    int buyKiya = -prices[index] + next[0][limit];
                    // Calculate the profit if we skip buying the stock
                    int skipKiya = 0 + next[1][limit];
                    // Take the maximum of the two profits
                    profit = max(buyKiya , skipKiya);
                } 
                // If the current state is sell
                else {
                    // Calculate the profit if we sell the stock
                    int sellKiya = prices[index] + next[1][limit - 1];
                    // Calculate the profit if we skip selling the stock
                    int skipKiya = 0 + next[0][limit];
                    // Take the maximum of the two profits
                    profit = max(sellKiya , skipKiya);
                } 

                // Store the profit in the current state
                curr[buy][limit] = profit;

            }  
        }
        // Update the next state with the current state
        next = curr;
    }

    return next[1][k];
}

    // ------------ 2 -------------------------------------

    int solve(int index , int OperationNo , int k , vector<int> &price) {

        // base cases
        if(index == price.size() ) 
            return 0;

        if(OperationNo == 2*k) {
            return 0;
        }


        // recursive cases
        int profit = 0;

        if(OperationNo %2 == 0) {
            int buyKiya = -price[index] + solve(index + 1 , OperationNo + 1 , k , price);
            int skipKiya = 0 + solve(index + 1 , OperationNo , k , price);
            profit = max(buyKiya , skipKiya);
        }

        else {
            int sellKiya = price[index] + solve(index + 1 , OperationNo + 1 , k , price);
            int skipKiya = 0 + solve(index + 1 , OperationNo , k , price);
            profit = max(sellKiya , skipKiya);
        }

        return profit;
    }

int main() {

    vector<int> prices = {3,2,6,5,0,3};
    int n = prices.size();
    int k = 2;

    //^ Two way to solve this problem is by using the same approach as 132_Buy_and_Sell_Stock.cpp or by using the same approach as 132_Buy_and_Sell_Stock.cpp with a slight modification

    //* way 1: Using the same approach as 132_Buy_and_Sell_Stock.cpp

    //todo: Tabulation
        int a = solveTabulation(prices , k);
        cout << "ans is : " << a << endl;

    //todo: space optimized tabulation
        int b = solveTabulationSpaceOptimized(prices , k);
        cout << "ans is : " << b << endl;


    //* way 2:

    //todo: Recursive Approach
        int c = solve(0 , 0 , k , prices ); // 0 is the number of transactions(limit)
        cout << "Max Profit is : " << c << endl;

    //todo: Top Down Approach(Using Recursion + Memoization)

    //todo: Bottom Up Approach(Using Iterative + Tabulation)

    //todo: Optimized Bottom Up Approach(Using Iterative + Tabulation)

 return 0;
} 