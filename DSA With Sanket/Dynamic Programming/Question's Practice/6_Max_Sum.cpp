#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &v , int n) {

    // base case
    // if(n == 0) {
    //     return v[0];
    // }

    // if(n < 0) return 0;
    if(n > v.size() - 1) {
        return 0;
    }

    // recursive call

    int include = solve( v , n + 2) + v[n];
    // if we include the current element, we skip the next one
    int exclude = solve( v , n + 1) + 0;

    return max(include , exclude);
}

int b (vector<int> &v , int n , vector<int> &dp) {
    

    // base case
    if( n < 0) {
        return 0;
    }

    if(n == 0) {
        return v[0];
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    cout << "hello " << n << endl;
    cout << "v[n] is 1 " << v[n] << endl;

    int include = b(v , n - 2 , dp) + v[n];
    cout << "v[n] is 2 " << v[n] << endl;

    int exclude = b(v , n - 1 , dp) + 0;
    cout << "v[n] is 3 " << v[n] << endl;

    dp[n] = max(include , exclude);
    return dp[n];
}

int e(vector<int> &v) {

    int n = v.size();
    vector<int> dp(n , 0);

    // base case
    dp[0] = v[0];

    // fill up the dp array
    for(int i = 1; i < n; i++) {
        int inclu = (i-2 >= 0) ? dp[i - 2] + v[i] : 0;
        int exclu = dp[i - 1];
        dp[i] = max(inclu , exclu);
    }

    return dp[n - 1]; // return the last element which contains the maximum sum
    
}
int main() {

    vector<int> num = {1 ,2 ,4};
    int n = num.size();

    // recursive call
    // int a = solve(num , 0);
    // cout << "Maximum Sum of Non-Adjacent Elements: " << a << endl;

    //way 2
    // vector<int> dp(n + 1 , -1);
    // int c = b(num , n - 1 , dp); // n - 1 is the last index
    // cout << "Maximum Sum of Non-Adjacent Elements with Memoization: " << c << endl;

    //wat 3
    int d = e(num);
    cout << "Maximum Sum of Non-Adjacent Elements with Tabulation: " << d << endl;

 return 0;
}