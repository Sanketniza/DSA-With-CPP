#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    queue<int> temp = q;
    cout << "Original Queue: ";
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }

    stack<int> s;
    while (!q.empty()) {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while (!s.empty()) {
        int element = s.top();
        s.pop();
        q.push(element);
    }

    cout << endl << "Reversed Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

 return 0;
}