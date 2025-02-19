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

    //todo: Tabulation

    //todo: Space Optimized Tabulation

    

 return 0;
} 