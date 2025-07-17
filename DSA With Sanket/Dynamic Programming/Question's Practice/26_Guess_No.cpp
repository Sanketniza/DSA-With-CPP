#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int start , int end) {

    // base case
    if(start >= end) return 0;

    int ans = INT_MAX;

    for(int x = start; x <= end; x++ ) {
        ans = min(ans , x + max(solve(start , x - 1) , solve(x + 1 , end)));
    }

    return ans;
}

int main() {

    int n = 10;

    int ans = solve(1 , n);
    cout << "ans is : " << ans << endl;

 return 0;
}