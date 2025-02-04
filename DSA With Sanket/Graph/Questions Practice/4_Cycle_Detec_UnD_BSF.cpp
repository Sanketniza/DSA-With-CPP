#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    int n = 5;
    vector<vector<int>> edge = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}};
    cout << solve(n, edge) << endl;

 return 0;
}