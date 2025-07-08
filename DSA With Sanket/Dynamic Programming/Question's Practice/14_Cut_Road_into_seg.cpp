#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveRec(int n , int x , int y , int z) {

    if(n == 0) return 0;

    if(n < 0) return INT_MIN;

    int a = solveRec(n - x , x , y , z) + 1;
    int b = solveRec(n - y , x , y , z) + 1;
    int c = solveRec(n - z , x , y , z) + 1;

    return max(a , max(b , c));
}

int main() {


    int n = 7;
    int x = 5;
    int y = 2;
    int z = 2;

    int ans = solveRec(n , x , y , z);

    if(ans < 0) {
        cout << "Not Possible" << endl;
    }
    else {
        cout << ans << endl;
    }


 return 0;
}