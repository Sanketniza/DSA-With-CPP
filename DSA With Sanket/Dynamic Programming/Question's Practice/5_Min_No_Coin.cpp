#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> cost, int sum) {
    

    // base case
    if(sum == 0) return 0;

    if( sum < 0) return INT_MAX;

    int mini = INT_MAX;

    for(int i = 0; i < cost.size(); i++) {

        int ans = solve(cost , sum - cost[i]);

        if(ans != INT_MAX) {
            mini = min(mini , 1 + ans);
        }
    }

    return mini;
}

int Memoization(vector<int> cost , int sum , vector<int> &dp) {
    
    // base case
    if(sum == 0) return 0;

    if(sum < 0 ) return INT_MAX;

    if(dp[sum] != -1) return dp[sum];

    int mini = INT_MAX;

    for(int i = 0; i < cost.size(); i++) {
        
        int ans = Memoization(cost, sum - cost[i], dp);

        if(ans != INT_MAX) {
            mini = min(mini , 1 + ans);
        }
    }

    dp[sum] = mini;
    // return dp[sum];
    return mini;
}

int main() {

    vector<int> cost = {10, 15, 20, 25, 30};
    int sum = 65;

    // int ans = solve(cost, sum);
    // if(ans == INT_MAX) {
    //     cout << "Not Possible" << endl;
    // } else {
    //     cout << "Minimum number of coins required: " << ans << endl;
    // }

    //* dp
    vector<int> dp(sum + 1, -1);
    int ans = Memoization(cost, sum , dp);

    if(ans == INT_MAX) {
        cout << "Not Possible" << endl;
    } else {
        cout << "Minimum number of coins required: " << ans << endl;
    }

 return 0;
}