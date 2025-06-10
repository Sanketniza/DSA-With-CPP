/* 
   ? 110: 0/1 KnapSack Problem
   ? https://www.naukri.com/code360/problems/0-1-knapsack_920542?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

    Problem statement
    A thief is robbing a store and can carry a maximal weight of W into his knapsack. There     are N items and the ith item weighs wi and is of value vi. Considering the constraints  of the maximum weight that a knapsack can carry, you have to find and return the  maximum value that a thief can generate by stealing items.


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


int solve (vector<int> weight, vector<int> value, int index, int capacity) {

	// base case
		// if only one item to steel , then just compare it's weight with the knapsack capacity

		if(index == 0) {
			if(weight[0] <= capacity ) {
				return value[0];
			}

			else {
				return 0;
			}
		}

		int include = 0;
		// int exclude = 0;

		if(weight[index] <= capacity) {
			include = value[index] + solve(weight , value , index - 1 , capacity - weight[index]);
		}
		
		int exclude = 0 + solve(weight , value , index - 1 , capacity);

		int ans = max(include , exclude);

		return ans;
}

int solveRM(vector<int> weight, vector<int> value, int index, int capacity, vector<vector<int>>& dp) {
    // base case
    if (index == 0) {
        if (weight[0] <= capacity) {
            return value[0];
        } else {
            return 0;
        }
    }

    if (dp[index][capacity] != -1) {
        return dp[index][capacity];
    }

    int include = 0;
    if (weight[index] <= capacity) {
        include = value[index] + solveRM(weight, value, index - 1, capacity - weight[index], dp);
    }

    int exclude = 0 + solveRM(weight, value, index - 1, capacity, dp);

    dp[index][capacity] = max(include, exclude);

    return dp[index][capacity];
}

int solveT(vector<int> weight, vector<int> value, int n, int capacity ) {

	vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

	// base case
	for(int w = weight[0]; w <= capacity; w++) {
		if (weight[0] <= capacity) {
            dp[0][w] = value[0];
        } else {
            dp[0][w] = 0;
        }
	}

	for(int index = 1; index < n; index++) {
		for(int w = 0; w <= capacity; w++) {

			int include = 0;

			if(weight[index]  <= w) {
				
				dp[index][w] = value[index] + dp[index - 1][ w - weight[index]];
			}

			int exclude = 0 + dp[index - 1][w];
			dp[index][w] = max(include , exclude);
		}
	}

	return dp[n - 1][capacity];
}

int solveS(vector<int> weight, vector<int> value, int n, int capacity ) {

	vector<int> prev(capacity + 1);
	vector<int> curr(capacity - 1);

	// base case
	for(int w = weight[0]; w <= capacity; w++) {
		if (weight[0] <= capacity) {
           prev[w] = value[0];
        } else {
            prev[w] = 0;
        }
	}

	for(int index = 1; index < n; index++) {
		for(int w = 0; w <= capacity; w++) {

			int include = 0;

			if(weight[index]  <= w) {
				
				prev[w] = value[index] + prev[ w - weight[index]];
			}

			int exclude = 0 + prev[w];
			curr[w] = max(include , exclude);
		}
		prev = curr;
	}

	return prev[capacity];
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	//R , way 1
		int one =  solve (weight , value , n - 1 , maxWeight);
        cout << "ans is : " << one << endl;

	// R + M
	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
   	int ans = solveRM(weight, value, n - 1, maxWeight, dp);
    cout << "ans is : " << ans << endl;

	// T , way 3

	int ans1 = solveT(weight , value , n  , maxWeight);   
    cout << "ans is : " << ans1 << endl;

	// S , way 4
	int ans2 = solveS(weight , value , n , maxWeight);
    cout << "ans is : " << ans2 << endl;
}


int main() {

    vector<int> weight = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};

    int n = weight.size();
    int W = 5;

    int result = knapsack(weight, value, n, W);
    
 return 0;
}