#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<vector<int>> mat = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    int n = mat.size();

    // Create a stack and push elements
    stack<int> s;
    for(int i = 0 ; i < n; i++) {
        s.push(i);
    }

    // Find potential celebrity 

    while (s.size() > 1) {

        int a = s.top();
        s.pop();

        int b = s.top(); 
        s.pop();

        if(mat[a][b] == 1) {
            s.push(b);
        }
        else {
            s.push(a);
        }
    }

    int ans = s.top();

    // Verify if the potential celebrity is actually a celebrity
    
    
    // check row 
    bool rowCheck = false;
    int zeroCount = 0;

    for(int i = 0; i < n; i++) {
        if(mat[ans][i] == 0) {
            zeroCount++;
        }
    }

    if(zeroCount == n) {
        rowCheck = true;
    }

    // check column

    bool colCheck = true;
    int oneCount = 0;

    for(int i = 0; i < n; i++) {
        if(mat[i][ans] == 1) {
            oneCount++;
        }
    }

    if(oneCount == n - 1) {
        colCheck = true;
    }

    if(rowCheck && colCheck) {
        cout << "The celebrity is " << ans << endl;
    }
    else {
        cout << "There is no celebrity" << endl;
    }
    
    
    
 return 0;
}