#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    stack<int> s;

    s.push(1);
    s.push(2);

    s.pop();

    s.push(3);
    s.push(4);
    s.push(5);

    cout<<"Top element of stack is "<<s.top()<<endl;
    cout << "size of the stack is ; " << s.size() << endl;

    if(s.empty()) {
        cout << "Stack is empty" << endl;
    }

    else {
        cout << "Stack is not empty" << endl;
    }

    for(int i = 0; i < s.top(); i++) {
        cout << s.top() << " ";
        s.pop();
    }
 return 0;
}