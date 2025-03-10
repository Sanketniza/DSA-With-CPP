#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(stack<int> &s , int x ) {
    
    // base case
    if(s.empty()) {
        s.push(x);
        return;
    }

    // store the top element
    int temp = s.top();
    s.pop();

    solve(s, x);

    // backtracking
    s.push(temp);



}

int main() {

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "Original stack is: " << endl;
    stack<int> temp1 = s;
    for(int i = 0; i < s.size(); i++) {
        cout << temp1.top() << " ";
        temp1.pop();
    }
    cout << endl;

    int x = 23;
    solve(s, x );

    cout << "Stack after inserting element at top is: " << endl;
    stack<int> temp = s;
    for(int i = 0; i < s.size(); i++) {
        cout << temp.top() << " ";
        temp.pop();
    }

    cout << endl;

    cout << "top element is: " << s.top() << endl;


 return 0;
}