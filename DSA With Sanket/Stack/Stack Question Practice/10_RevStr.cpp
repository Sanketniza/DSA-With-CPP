#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s , int x) {

    if(s.empty()) {
        s.push(x);
        return;
    }

    int topElement = s.top();
    s.pop();

    insertAtBottom(s, x);
}

void reverse(stack<int> &s) {

    if(s.empty()) {
        return;
    }

    int element = s.top();
    s.pop();

    reverse(s);

    insertAtBottom(s, element);
}

int main() {

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    stack<int> temp = s;
    int n = temp.size();
    cout << "Size of stack: " << n << endl;
    cout << "Before reversing the stack: " << endl;
    for(int i = 0; i < n; i++) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;


    reverse(s);

    cout << "After reversing the stack: " << endl;
    stack<int> temp2 = s;
    for(int i = 0; i < temp2.size(); i++) {
        cout << temp2.top() << " ";
        temp2.pop();
    }



 return 0;
}