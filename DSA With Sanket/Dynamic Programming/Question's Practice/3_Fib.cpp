#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int fib(int n , vector<int> &dp) {
    
    // base case
    if(n <= 1) {
        return n;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    // recursive case
    int x = fib(n - 1, dp) + fib(n - 2, dp);
    dp[n] = x; // store the result in dp array

    // dp[n] = fib(n - 1, dp) + fib(n - 2, dp); // alternative way to write
    return dp[n];
}

int fib2(int n) {

    // base case
    if(n <= 1) {
        return n;
    }

    // create dp array
    vector<int> dp(n + 1, 0);

    dp[0] = 0; // fib(0)
    dp[1] = 1; // fib(1)

    // fill the dp array
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2]; // fib(n) = fib(n-1) + fib(n-2)
    }

    return dp[n]; // return the nth Fibonacci number

}

int main() {

    int n = 10;

    // top - down approach

    // create dp array with -1 val
    vector<int> dp(n + 1, -1);

    int ans = fib(n, dp);
    cout << "ans is : " << ans << endl;

    // bottom - up approach

   
    int ans2 = fib2(n);
    cout << "ans2 is : " << ans2 << endl;

    // space optimization
    int a = 0;
    int b = 1;

    // if(n == 0) {
    //     cout << "ans is : " << a << endl;
    //     return 0;
    // }

    for(int i = 2; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }

    cout << "ans is : " << b << endl;

 return 0;
}