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

     int solveM(int index , int operationNo , int k , vector<int> &prices , vector<vector<int>> &dp) {

        // base case
        if(index == prices.size())
            return 0;

        if(operationNo == 2 * k)
            return 0;

        if(dp[index][operationNo] != -1)
            return dp[index][operationNo];    

            int profit = 0;
            // if operationNo is even, we can buy the stock
            if(operationNo % 2 == 0) {
                 // if we buy the stock, we add the negative price of the stock to the profit and move to the next index and operationNo
                 int buyKiya = -prices[index] + solveM(index + 1 , operationNo + 1 , k , prices , dp);
                 // if we skip the stock, we add 0 to the profit and move to the next index and the same operationNo
                 int skipKiya = 0 + solveM(index + 1 , operationNo , k , prices , dp);
                 // we take the maximum of buying or skipping the stock
                 profit = max(buyKiya , skipKiya);
              } 

             // if operationNo is odd, we can sell the stock
             else {
                 // if we sell the stock, we add the price of the stock to the profit and move to the next index and operationNo
                 int sellKiya = prices[index] + solveM(index + 1 , operationNo + 1 , k , prices , dp);
                 // if we skip the stock, we add 0 to the profit and move to the next index and the same operationNo
                 int skipKiya = 0 + solveM(index + 1 , operationNo , k , prices , dp);
                 // we take the maximum of selling or skipping the stock
                 profit = max(sellKiya , skipKiya);
            } 

             // we store the profit in the dp array
             return dp[index][operationNo] =  profit;
    }  

    int solveTab(vector<int> &prices , int k) {       

        int n = prices.size();
        vector<vector<int>> dp(n + 1 , vector<int> (2 * k + 1 , 0));

        for(int index = n -1 ; index >= 0; index--) {
            for(int operationNo = 0; operationNo < 2*k; operationNo++) {

                int profit = 0;

                if(operationNo % 2 == 0) {
                    int buyKiya = -prices[index] + dp[index + 1][operationNo + 1];
                    int skipKiya = 0 + dp[index + 1][operationNo];
                    profit = max(buyKiya , skipKiya);
                } 

                else {
                   int sellKiya = prices[index] + dp[index + 1][operationNo + 1];
                   int skipKiya = 0 + dp[index + 1][operationNo];
                   profit = max(sellKiya , skipKiya);
                } 

                dp[index][operationNo] = profit;
            }
        }

        return dp[0][0];  // 0 is the operationNo , 0 is the index
        //  soveM(0,0 , k , prices , dp); // 0 is the index , 0 is the operationNo
    }

    int solveSpace(vector<int> &prices , int k) {

        // Initialize the size of the prices vector
        int n = prices.size();
        // Initialize the current and next vectors with size 2*k + 1 and all elements as 0
        vector<int> curr(2 * k + 1 , 0);
        vector<int> next(2 * k + 1 , 0);

        // Iterate through the prices vector from the end to the beginning
        for(int index = n - 1; index >= 0; index--) {
            // Iterate through the operationNo from 0 to 2*k
            for(int operationNo = 0; operationNo < 2*k; operationNo++) {

                // Initialize the profit as 0
                int profit = 0;

                // If the operationNo is even, calculate the profit by buying the stock or skipping the operation
                if(operationNo % 2 == 0) {
                    int buyKiya = -prices[index] + next[operationNo + 1];
                    int skipKiya = 0 + next[operationNo];
                    profit = max(buyKiya , skipKiya);
                } 

                // If the operationNo is odd, calculate the profit by selling the stock or skipping the operation
                else {
                   int sellKiya = prices[index] + next[operationNo + 1];
                   int skipKiya = 0 + next[operationNo];
                   profit = max(sellKiya , skipKiya);
                } 

                // Store the profit in the current vector
                curr[operationNo] = profit;
            }
            // Update the next vector with the current vector
            next = curr;
        }

        // Return the profit at operationNo 0 and index 0
        return next[0];  // 0 is the operationNo , 0 is the index
        //  soveM(0,0 , k , prices , dp); // 0 is the index , 0 is the operationNo
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
        vector<vector<int>> dp(n + 1 , vector<int> (2 * k + 1 , -1));
        int d = solveM(0 , 0 , k , prices , dp);
        cout << "Max Profit is : " << d << endl;

    //todo: Bottom Up Approach(Using Iterative + Tabulation)
        int e = solveTab(prices , k);
        cout << "Max Profit is : " << e << endl;

    //todo: Optimized Bottom Up Approach(Using Iterative + Tabulation)
        int f = solveSpace(prices , k);
        cout << "Max Profit is : " << f << endl;

 return 0;
} 