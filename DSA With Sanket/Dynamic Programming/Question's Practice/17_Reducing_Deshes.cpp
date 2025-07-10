#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &s , int index , int time) {

    if(index == s.size()) {
        return 0;
    }

    int include = s[index] * (time * 1) + solve(s , index + 1 , time + 1);
    int exclude = 0 + solve(s , index + 1 , time);

    return max(include , exclude);
}

int solveM(vector<int> &s , int index , int time , vector<vector<int>> &dp) {
    
    // base case
    if(index == s.size()) return 0;

    if(dp[index][time] != -1) return dp[index][time];

    // recursive case

    int include = s[index] * (time + 1) + solveM(s , index + 1 , time + 1 , dp);
    int exlude = 0 + solveM(s , index + 1 , time , dp);

    dp[index][time] = max(include , exlude);
    return dp[index][time];
}

int main() {

    vector<int> s = {-1, -8, 0, 5, -9};
    sort(s.begin() , s.end());
    int n = s.size();

    // Recursive approach
    int a = solve(s , 0 , 0);
    cout << "Recursive approach: " << a << endl;

    // Memoization approach
    vector<vector<int>> dp(n  , vector<int> (n + 1 , -1));
    int b = solveM(s , 0 , 0 , dp);
    cout << "Memoization approach: " << b << endl;

 return 0;
}