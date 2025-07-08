#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveRec(int n ) {

    if(n == 1) return 0;
    if(n == 2) return 1;

    int ans = (n - 1) * (solveRec(n - 2) + solveRec(n - 1));
    return ans;
}

int main() {

    int n = 3;

    int ans = solveRec(n);

    if(ans < 0) {
        cout << "Not Possible" << endl;
    }
    else {
        cout << ans << endl;
    }
 return 0;
}