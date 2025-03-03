#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(int n ) {

    // base case

    if(n == 0) {
        return;
    }

    // recursive case


    solve(n - 1);

    cout << n << " ";
}

int main() {

    int n ;
    cout << "Enter the number of elements : ";
    cin >> n;

    solve(n);


 return 0;
}