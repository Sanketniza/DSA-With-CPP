#include <iostream>
#include <stack>
using namespace std;

// Stack is a container adapter that gives the interface of a stack (LIFO) to a sequence container (we usually use deque or list).
// Stack is a non-standard container and not a part of container base class.
// Stack is a simple container that stores elements in a LIFO manner.
// Stack is a non-STL container and not a part of STL.
// Stack is a non-STL container and not a part of STL.
// Stack is a non-STL container and not a part of STL.
// Stack is a non-STL container and not a part of STL.
// Stack is a non-STL container and not a part of STL.

// todo: stack STL Implementation

int main() {

    stack<int> st1, st2;

    // Push operation
    st1.push(10);
    st1.push(20);
    st1.push(30);
    st1.push(40);
    st1.push(50);

    //pop operation
    st1.pop();
    st1.pop();

    //top operation
    cout<<"Top element of stack is "<<st1.top()<<endl;

    //size operation
    cout<<"Size of stack is "<<st1.size()<<endl;

    //empty operation
    cout<<"Is stack empty? "<<(st1.empty()?"Yes":"No")<<endl;

    // print the stack
    cout<<"Printing the stack"<<endl;
    while(!st1.empty()){
        cout<<st1.top()<<" ";
        st1.pop();
    }
    cout<<endl;

    // Emplace operation
    st1.emplace(40);

    cout << "Stack 1: ";
    while (!st1.empty()) {
        cout << st1.top() << " ";
        st1.pop();
    }
    cout << endl;

    // Push some elements to stack 2
    st2.push(50);
    st2.push(60);

    cout << "Size of stack 2: " << st2.size() << endl;

    // Swap operation
    st1.swap(st2);

    cout << "After swap, Stack 1: ";
    while (!st1.empty()) {
        cout << st1.top() << " ";
        st1.pop();
    }
    cout << endl;

    // Check if stack is empty
    cout << "Is stack 1 empty? " << (st1.empty() ? "Yes" : "No") << endl;
    cout << "Is stack 2 empty? " << (st2.empty() ? "Yes" : "No") << endl;

    return 0;
}