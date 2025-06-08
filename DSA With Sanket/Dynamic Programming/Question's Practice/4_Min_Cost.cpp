#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &cost , int n) {

    // base case
    if(n == 0) return cost[0];

    if(n == 1) return   cost[1];

    int ans = cost[n] + min(solve(cost , n - 1) , solve(cost , n - 2));
    return ans;
}

int main() {

    int m;
    cout << "Enter the number of steps: ";
    cin >> m;

    vector<int> cost(m);
    cout << "Enter the cost of each step: " << endl;
    for(int i = 0; i < m; i++) {
        cin >> cost[i];
    }

    int n = cost.size();

    // recursive only
    int a = min(solve(cost , n - 1) , solve(cost , n - 2));
    cout << "ans is : " << a << endl;

    // Approach 1: Top-Down (Recursive + Memoization)

 return 0;
}