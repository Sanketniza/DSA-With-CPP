/* 
    113: Minimum Cost for Tickets
    https://www.naukri.com/code360/problems/minimum-coins_2180776?leftPanelTab=0

     Ninja's Trip

    Problem statement
    Ninja is willing to take some time off from his training and planning a year-long tour. You are given a DAYS array     consisting of ‘N’ days when Ninjas will be traveling during the year. Each Day is an integer between 1 to 365 (both     inclusive). Train tickets are sold in three different ways:
    A 1-day pass is sold for 'COST'[0] coins,
    A 7-day pass is sold for 'COST'[1] coins, and
    A 30-day  pass is sold for 'COST'[2] coins.
    The passes allow for many days of consecutive travel.
    Your task is to help the Ninja to find the minimum number of coins required to complete his tour. For example,
    If Ninja gets a 7-day pass on day 2, then he can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
    Detailed explanation ( Input/output format, Notes, Images )
    Constraints:
    1 <= T <= 10
    1 <= N <= 365
    1 <= DAYS[i] <= 365
    
    Time Limit: 1 sec
    Sample Input 1:
    2
    2 
    2 5
    1 4 25    
    7
    1 3 4 5 7 8 10
    2 7 20
    Sample Output 1:
    2
    11
    Explanation For sample input 1:
    For the first test case, 
    On Day 2, Ninja will buy a 1-day pass with 1 coin.
    On Day 5, Ninja will buy a 1-day pass with 1 coin.
    In total, Ninja will spend 2 coins. Hence the answer is 2.
    
    For the second test case,
    On Day 1, Ninja will buy a 1-day pass with 2 coins.
    On Day 3, Ninja will buy a 7-day pass with 7 coins valid for days 3,4,5...9.
    On Day 10, Ninja will buy a 1-day pass with 2 coins.
    In total, Ninja will spend 11 coins. Hence the answer is 11.
    Sample Input 2:
    2
    6
    1 4 6 7 8 20
    2 7 15
    12
    1 2 3 4 5 6 7 8 9 10 30 31
    2 7 15 
    Sample Output 2:
    11
    17

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve (int n , vector<int> &days , vector<int> &cost) {

    int index = 0;

    // base case
    if(index >= n) {
        return 0;
    }

    // recursive case

    //! 1 day pass
    int op1 = cost[0] + solve(n - 1 , days , cost);

    int j = 0;
    for(j = index; j < n && days[j] < days[index] + 7; j++) ;
    // ! 7 day pass
    int op2 = cost[1] + solve(n - j , days , cost);

    for(j = index; j < n && days[j] < days[index] + 30; j++) ;
    // ! 30 day pass
    int op3 = cost[2] + solve(n - j , days , cost);

    return min(op1 , min(op2 , op3));
}

int solveRM(int n , vector<int> &days , vector<int> &cost , vector<int> &dp) {

    int index = 0;

    // base case
    if(index >= n) {
        return 0;
    }

    if(dp[index] != 0) {
        return dp[index];
    }

    // recursive case

    //! 1 day pass
    int op1 = cost[0] + solveRM(n - 1 , days , cost , dp);

    int j = 0;
    for(j = index; j < n && days[j] < days[index] + 7; j++) ;
    // ! 7 day pass
    int op2 = cost[1] + solveRM(n - j , days , cost , dp);

    for(j = index; j < n && days[j] < days[index] + 30; j++) ;
    // ! 30 day pass
    int op3 = cost[2] + solveRM(n - j , days , cost , dp);


    dp[index] = min(op1 , min(op2 , op3));
    return dp[index];
}

int solveIterative(int n , vector<int> &days , vector<int> &cost) {

    vector<int> dp(n + 1 , 0);
    dp[n] = 0;

    for(int i = n - 1; i >= 0; i--) {
        int op1 = cost[0] + dp[i + 1];

        int j = 0;
        for(j = i; j < n && days[j] < days[i] + 7; j++) ;
        int op2 = cost[1] + dp[j];

        for(j = i; j < n && days[j] < days[i] + 30; j++) ;
        int op3 = cost[2] + dp[j];

        dp[i] = min(op1 , min(op2 , op3));
    }

    return dp[0];
}

int main() {

    vector<int> days = {1, 3, 4, 5, 7, 8, 10};
    vector<int> cost = {2, 7, 20};
    int n = days.size();

    //todo: Recursive approach 
    int ans = solve(n , days , cost);
    cout << "ans is : " << ans << endl;


    //todo: DP approach
    vector<int> dp(n + 1 , 0);
    int ans1 = solveRM(n , days , cost , dp);
    cout << "ans is : " << ans1 << endl;

    // todo: Iterative approach
    int ans2 = solveIterative(n , days , cost);
    cout << "ans is : " << ans2 << endl;



 return 0;
} 