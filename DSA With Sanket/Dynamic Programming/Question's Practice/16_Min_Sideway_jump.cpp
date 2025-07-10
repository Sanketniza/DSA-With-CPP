#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , int currLane , int currPos) {

    // base case
    if(currPos >= arr.size() - 1) return 0;

    // condition
    if(arr[currPos + 1] != currLane) {
        return solve(arr , currLane , currPos + 1);
    }

    else {
        int ans = INT_MIN;
        for(int i = 1; i <= 3; i++) {
            if(currLane != i && arr[currPos] != i) {
                ans = max(ans , 1 + solve(arr , i , currPos));
            }
        }
        return ans;
    }

    
}

int solveM(vector<int> &arr , int currLane , int currPos , vector<vector<int>> &dp) {

    // base case
    if(currPos >= arr.size() - 1) return 0;

    if(dp[currLane][currPos] != -1) {
        return dp[currLane][currPos];
    }

    // condition
    if(arr[currPos + 1] != currLane) return solveM(arr , currLane , currPos + 1 , dp);

    else {
        int ans = INT_MAX;
        for(int i = 1; i <= 3; i++) {
            if(currLane != i && arr[currPos] != i) {
                ans = min(ans , 1 + solveM(arr , i , currPos , dp));
            }
        }
        dp[currLane][currPos] = ans;
        return dp[currLane][currPos];
    }
}

int main() {

    vector<int> arr = {0,2,1,0,3,0};
    int size = arr.size();

    // normal way
    int ans = solve(arr , 2 , 0);
    cout << "Minimum Sideways Jump: " << ans << endl;

    // using memoization
    vector<vector<int>> dp(4 , vector<int>(size , -1));
    // (size of lanes + 1) x (size of arr)
    int a = solveM(arr , 2 , 0 , dp);
    cout << "Minimum Sideways Jump using Memoization: " << a << endl;

 return 0;
}