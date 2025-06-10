#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> weighs , vector<int> value , int index , int capacity) {

    // base case
    if(index == 0) {
        if(weighs[0] <= capacity) {
            return value[0];
        }

        else {
            return 0;
        }
    }

    // if(dp[index][capacity] != -1) {
    //     return dp[index][capacity];
    // }

    int include = 0;

    if(weighs[index] <= capacity) {
        include = value[index] + solve(weighs , value , index - 1, capacity - weighs[index]);
    }

    int exclude = 0 + solve(weighs , value , index - 1, capacity);

    int ans = max(include , exclude);

    // return dp[index][capacity];
    return ans;
}

int newsolve(vector<int> weighs , vector<int> value , int index , int capacity) {

   // base case
    if(index == weighs.size() - 1) {
        if(weighs[index] <= capacity) {
            return value[index];
        }

        else {
            return 0;
        }
    }

    int include = 0;
    if(weighs[index] <= capacity) {
        include = value[index] + newsolve(weighs , value , index + 1, capacity - weighs[index]);
    }

    int exclude = 0 + newsolve(weighs , value , index + 1, capacity);

    int ans = max(include , exclude);

    return ans;
}

int main() {

    vector<int> weight = {1, 2, 3};
    vector<int> value = {10, 5, 4};

    int capacity = 5;
    int n = weight.size();

    // Normal Recursion
    int a = solve(weight, value, n - 1, capacity);
    cout << "Maximum value (Recursion): " << a << endl;

    int b = newsolve(weight, value, 0, capacity);
    cout << "Maximum value (Memoization): " << b << endl;

 return 0;
}