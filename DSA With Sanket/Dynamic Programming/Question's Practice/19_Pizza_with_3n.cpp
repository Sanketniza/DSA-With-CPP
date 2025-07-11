#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int index , int endPoint , vector<int> &arr , int k) {

    // base case
    if( k == 0 || index > endPoint) return 0;

    // recursive case
    // take
    int take = 0;
    take = arr[index] + solve(index + 2 , endPoint , arr , k - 1);

    // not take
    int notTake = 0 + solve(index + 1 , endPoint , arr , k);

    return max(take , notTake);
}

int solveM(int index ,int endPoint , vector<int> &arr , int k  , vector<vector<int>> &dp) {

    //base case
    if(k == 0 || index > endPoint) return 0;

    if(dp[index][k] != -1) return dp[index][k];

    //take 
    int take = 0;
    take = arr[index] + solveM(index + 2 , endPoint , arr , k - 1 , dp);

    // not take
    int notTake = 0 + solveM(index + 1 , endPoint , arr , k , dp);
    return dp[index][k] = max(take , notTake);

}

int main() {

    vector<int> arr = {8,9,8,6,1,1};
    int n = arr.size();

    // normal approach
    int case1 = solve(0 , n - 2 , arr , n /3);
    int case2 = solve(1 , n - 1 , arr , n /3);
    int ans = max(case1 , case2);
    cout << "Maximum sum of pizza slices is: " << ans << endl;

    // memoization approach
    vector<vector<int>> dp(n +1 , vector<int>(n + 1 , -1));
    int case1M = solveM(0 , n - 2 , arr , n /3 , dp);
    int case2M = solveM(1 , n - 1 , arr , n /3 , dp);
    int ansM = max(case1M , case2M);
    cout << "Maximum sum of pizza slices is: " << ansM << endl;

 return 0;
}