/* 
    ? 131: Buy and Sell Stock
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/1547371593/

    You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int index , int buy , vector<int> price) {

    // base case
    if(index >= price.size()) {
        return 0;
    }

    // recursive case
    int profit = 0;

    if(buy){
        int buyKiya = -price[index] + solve(index + 1 , 0 , price);
        int nahiKiya = solve(index + 1 , 1 , price);
        profit = max(buyKiya , nahiKiya);
    }

    else {
        int sellKiya = price[index] + solve(index + 1 , 1 , price);
        int nahiKiya = solve(index + 1 , 0 , price);
        profit = max(sellKiya , nahiKiya);
    }

    return profit;
}

int main() {

    vector<int> prices = {7,1,5,3,6,4};
    int n = prices.size();

    //todo: Recursive Approach
    int a = solve(0 , 1 , prices); //  1 -> allowed to buy , 0 - > not allowed to buy 
    cout << "Max Profit is : " << a << endl;

 return 0;
} 