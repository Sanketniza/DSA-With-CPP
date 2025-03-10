#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(stack<int> &s , int count , int size) {

    // base case
    if(count == size / 2) {
        s.pop();
        return;
    }

    // store the top element
    int temp = s.top();
    s.pop();

    // recursive call
    solve(s , count + 1 , size);

    // backtracking
    s.push(temp);
}

int main() {

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    int n = s.size();
    int count = 0;

    solve(s, count, n);

    cout << "Stack after deleting middle element is: " << endl;
    for(int i = 0; i < n; i++) {
        cout << s.top() << " ";
        s.pop();
    }

 return 0;
}