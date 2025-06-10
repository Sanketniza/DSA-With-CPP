#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve( vector<int> &num , int tar) {
    
    // base case
    if(tar == 0) return 1;

    if(tar < 0) return 0;

    int ans = 0; 

    for(int i = 0; i < num.size(); i++) {
        ans += solve( num , tar - num[i]);
    }

    return ans;
}

int solve(vector<int> &num , int tar , vector<int> &dp) {

    // base case
    if( tar == 0) return 1;
    if(tar < 0) return 0;

    if(dp[tar] != - 1) return dp[tar];

    int ans = 0;

    for(int i = 0; i < num.size(); i++) {
        ans += solve(num, tar - num[i], dp);
    }

    dp[tar] = ans;
    return dp[tar];
}

int tab(vector<int> &num , int tar) {

    vector<int> dp(tar + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <=tar; i++) {
        for(int j = 0; j < num.size(); j++) {
            if(i - num[j] >= 0) {
                dp[i] += dp[i - num[j]];
            }
        }
    }

    return dp[tar];
}

int main() {

    vector<int> num = {1, 2, 3};
    int tar = 4;

    // Recursive approach 1
    int a = solve(num, tar);
    cout << "Recursive approach 1: " << a << endl;

    // Recursive approach 2, using memoization
    vector<int> dp(tar + 1 , -1);
    int b = solve(num, tar, dp);
    cout << "Recursive approach 2: " << b << endl;

 return 0;
}