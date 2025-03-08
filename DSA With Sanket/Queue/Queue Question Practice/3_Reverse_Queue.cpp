
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main() {

    queue<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);

    stack<int> s;

    cout << "Original Queue: " << endl;
    queue<int> temp = a;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    while (!a.empty()) {
       int val = a.front();
       s.push(val);
       a.pop();
    }

    while (!s.empty()) {
        int val = s.top();
        a.push(val);
        s.pop();
    }

    cout << "Reversed Queue: " << endl;
    while (!a.empty()) {
        cout << a.front() << " ";
        a.pop();
    }

 return 0;
}