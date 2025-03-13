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
    int k = 3;

    queue<int> temp = q;
    cout << "Original Queue: ";
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    stack<int> s;
    for(int i = 0; i < k; i++) {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    while (!s.empty()) {
        int element = s.top();
        s.pop();
        q.push(element);
    }

    cout << "q.size(): " << q.size() << endl;

    int t = q.size() - k;
    cout << "t: " << t << endl;

    while(!q.empty() && t--) {
        int element = q.front();
        q.pop();
        q.push(element);
    }

    cout << "Reversed Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

 return 0;
}