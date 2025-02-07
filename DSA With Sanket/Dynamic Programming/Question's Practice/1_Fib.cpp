#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int num , vector<int> &dp) {
    if(num <= 1) {
        return num;
    }
    
    if(dp[num] != -1) {
        return dp[num];
    }

    dp[num] = solve(num - 1, dp) + solve(num - 2, dp); // Corrected function calls
    return dp[num];
}

int main() {
    int num = 16;
    vector<int> dp(num + 1 , -1);
    cout << "ans is : " << solve (num , dp) << endl;

    // 
    int a = 0;
    int b = 1;
    int c;

    for(int i = 0; i < num; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    cout << "ans is : " << a << endl;

    return 0;
}