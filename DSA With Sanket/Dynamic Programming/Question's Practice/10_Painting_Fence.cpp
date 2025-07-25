#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int add(int a , int b) {
    return (a % MOD + b % MOD) % MOD;
}

int mul(int a , int b) {
    return ((a % MOD) * 1LL * (b % MOD)) % MOD;
}

int solve(int n , int k) {

    if(n == 0) return 0;
    if(n == 1) return k;

    int same = k;
    int diff = k * (k - 1);
    int total = same + diff;

    for(int i = 3; i <= n; i++) {
        same = diff;
        diff = total * (k - 1);
        total = same + diff;
    }

    return total;
}

int s(int n , int k) {

    // base case
    if(n == 1) return k;
    if(n == 2) return add(k, mul(k, k - 1));

    int ans = solve(n - 2, k) * (k - 1) + solve(n - 1, k) * (k - 1);
    return ans;
}

int tab(int n , int k) {

    vector<int> dp(n + 1, 0);
    dp[1] = k; // base case
    dp[2] = add(k, mul(k, k - 1)); // base case

    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i - 2] * (k - 1) + dp[i - 1] * (k - 1);
        dp[i] = dp[i] % MOD; // to avoid overflow

    }

    return dp[n];
}

int main() {

    int n = 2 , k = 4;

    // recursive way

    int a = solve(n, k);
    cout << "Number of ways: " << a << endl;

    int b = s(n , k);
    cout << "Number of ways: " << b << endl;

    int c = tab(n , k);
    cout << "Number of ways: " << c << endl;

 return 0;
}