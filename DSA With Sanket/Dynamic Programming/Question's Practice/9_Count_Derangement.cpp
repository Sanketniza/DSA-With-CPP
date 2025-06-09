#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve( int n) {

    // base case
    if(n == 0) return 0;

    if(n == 1) return 0;

    if(n == 2) return 1;

    int ans = (n - 1) * (solve(n - 1) + solve(n - 2));

    return ans;
    
}

int main() {

    int n = 3;

    // first way 
    int a = solve(n);
    cout << "Count of derangements using recursion: " << a << endl;

 return 0;
}