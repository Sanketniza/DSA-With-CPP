#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , int curr , int prev) {

    // base case
    if(curr == arr.size()) {
        return 0;
    }

    // include
    int take = 0;
    if(prev == -1 || arr[prev] < arr[curr]) {
        take = 1 + solve(arr , curr + 1 , curr);
    }

    // exclude
    int notTake = 0 + solve(arr , curr + 1 , prev);
    // return the maximum of both choices

    return max(take , notTake);
}

int solveM(vector<int> &arr , int curr , int prev , vector<vector<int>> &dp) {
    
    // base case
    if(curr == arr.size()) return 0;

    if(dp[curr][prev + 1] != -1 ) return dp[curr][prev +1];

    //include 
    int take = 0;
    if(prev == -1 || arr[prev] < arr[curr]) {
        take = 1 + solveM(arr , curr + 1 , curr , dp);
    } 

    // exclude
    int notTake = 0 + solveM(arr , curr + 1 , prev , dp);
    dp[curr][prev] = max(take , notTake);

    return dp[curr][prev];
}

int main() {

    vector<int> arr = {5, 8, 3, 7, 9, 1};
    int n = arr.size();

    // Recursive approach
    int a = solve(arr , 0 , -1);
    cout << "a is : " << a << "" << endl;

    // Memoization approach
    vector<vector<int>> dp(n + 1 , vector<int>(n + 1, -1));
    int b = solveM(arr , 0 , -1 , dp);
    cout << "b is : " << b << endl;

 return 0;
}