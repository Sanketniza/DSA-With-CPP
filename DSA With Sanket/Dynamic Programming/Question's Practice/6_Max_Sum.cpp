#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &v , int n) {

    // base case
    if(n == 0) {
        return v[0];
    }

    if(n < 0) return 0;

    // recursive call

    int include = solve( v , n - 2) + v[n];
    int exclude = solve( v , n - 1) + 0;

    return max(include , exclude);
}

int main() {

    vector<int> num = {1 ,2 ,4};
    int n = num.size();

    // recursive call
    int a = solve(num , n - 1);
    cout << "Maximum Sum of Non-Adjacent Elements: " << a << endl;

 return 0;
}