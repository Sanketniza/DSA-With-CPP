#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int n , int x , int y , int z) {
    
    // base case
    if(n == 0) return 0;
    if(n < 0) return INT_MIN;

    // recursive call
    int a = solve( n - x , x , y , z) + 1;
    int b = solve( n - y , x , y , z) + 1;
    int c = solve( n - z , x , y , z) + 1;

    int ans = max(a , max(b , c));
    return ans;
}

int main() {

    int n = 7; // Length of the rod
    int x = 5; // Length of segment X
    int y = 2; // Length of segment Y
    int z = 2; // Length of segment Z

    // recursive way
    int ans = solve(n , x , y , z);

    if(ans < 0) {
        cout << "No valid segments can be cut." << endl;
    } else {
        cout << "Maximum number of segments that can be cut: " << ans << endl;
    }

 return 0;
}