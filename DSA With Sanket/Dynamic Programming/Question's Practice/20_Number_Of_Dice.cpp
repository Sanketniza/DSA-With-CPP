#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int dice ,int face , int target) {

    // base cases
    if(target < 0) return 0;

    if(dice == 0 && target == 0) return 1;

    if(dice == 0 && target != 0) return 0;

    if(dice != 0 && target == 0) return 0;

    // recursive case
    int ans = 0;
    for(int i = 1; i <= face; i++) {

        ans += solve(dice - 1, face , target - i);
    }

    return ans;
}

int solveM(int dice ,int face ,int target , vector<vector<int>> &dp) {

    // base case
    if(target < 0) return 0;

    if(target == 0 && dice == 0) return 1;

    if(target == 0 && dice != 0) return 0;

    if(target != 0 && dice == 0 ) return 0;

    if(dp[dice][target] != -1) return dp[dice][target];

    int ans = 0;

    for(int i = 1; i <= face; i++) {

        ans += solveM(dice - 1 , face , target - i , dp);
    }

    dp[dice][target] = ans;

    return dp[dice][target];
}

int main() {

    int m = 6; int n = 3; int x = 12;

    int ans = solve(n , m , x);
    cout << "ans is : " << ans << endl;

    // todo: Memoization approach
    vector<vector<int>> dp(n + 1 , vector<int> (x + 1 , -1));
    int a = solveM(n , m , x , dp);
    cout << "ans is : " << a << endl;
     
     

    return 0;
}