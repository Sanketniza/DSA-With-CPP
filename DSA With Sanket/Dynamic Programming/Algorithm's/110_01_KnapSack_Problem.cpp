/* 
    110: 0/1 KnapSack Problem
    https://www.naukri.com/code360/problems/0-1-knapsack_920542?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

    Problem statement
    A thief is robbing a store and can carry a maximal weight of W into his knapsack. There     are N items and the ith item weighs wi and is of value vi. Considering the constraints  of the maximum weight that a knapsack can carry, you have to find and return the     maximum value that a thief can generate by stealing items.

    Detailed explanation ( Input/output format, Notes, Images )
    Constraints:
    1 <= T <= 10
    1 <= N <= 10^2
    1<= wi <= 50
    1 <= vi <= 10^2
    1 <= W <= 10^3

    Time Limit: 1 second
    Sample Input:
    1 
    4
    1 2 4 5
    5 4 8 6


    5
    Sample Output:
    13

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &weight , vector<int> &value , int capacity , int index) {

    // base case
    // if only one item to steel , then just compare it's weight with the knapsack capacity

    if(index == 0 ) {
       if(weight[0] <= capacity) {
          return value[0];
       } 
       
       else {
           return 0;
       }
    }

    // if the weight of the item is greater than the capacity of the knapsack
    // then we can't steel that item

    int include = 0;

    if(weight[index] <= capacity) {
        include = value[index] + solve(weight , value , capacity - weight[index] , index - 1);
    }

    int exclude = 0 + solve(weight , value , capacity , index - 1);

    return max(include , exclude);

}

int knapsack(vector<int> &weight , vector<int> &value , int W , int n) {

   //todo: recursive approach
    int ans = solve(weight , value , W , n - 1  );
    cout << "ans is : " << ans << endl;

    // todo: DP approach
    vector<vector<int>> dp(n + 1 , vector<int>(W + 1 , -1));
    int ans1 = solveM(weight , value , W , n , dp);
    cout << "ans1 is : " << ans1 << endl;

    // todo: Tabulation approach
    int ans2 = solveTab(weight , value , W , n);
}


int main() {

    vector<int> weight = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};

    int n = weight.size();
    int W = 5;

    int result = knapsack(weight, value, W, n);
    
 return 0;
}