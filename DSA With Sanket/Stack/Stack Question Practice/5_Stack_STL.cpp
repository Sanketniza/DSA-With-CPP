#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element is : " << s.top() << endl;
    s.pop();
    cout << "Top element is : " << s.top() << endl;

    cout << "Size of stack is : " << s.size() << endl;

    if(s.empty()) {
        cout << "Stack is empty" << endl;
    }

    else {
        cout << "Stack is not empty" << endl;
    }

    cout << "Stack is: ";
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    } cout << endl;

    stack<int> s2;
    s2.push(40);
    s2.push(50);

    s.swap(s2);

    cout << "After swap, Stack is: ";
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }


    return 0;
}