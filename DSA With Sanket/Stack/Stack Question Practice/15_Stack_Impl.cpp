#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class myStack {

    public:

        int *arr;
        int size;
        int top;

        myStack(int s) {
            this -> size = s;
            arr = new int [size];
            top = -1;
        }

        void push(int data) {

            if(size > top - 1) { // size - top > 1
                top++;
                arr[top] = data;
            }

            else { // size - top < 1
                cout << "stack is overflow" << endl;
            }

        }

        void pop() {

            if(top == -1) {
                cout << "stack is underflow" << endl;
            }

            else { // top >= 0
                cout << "Popped element is: " << arr[top] << endl;
                top--;
            }
        }

        int peek() {

            if(top >= 0) {
                return arr[top];
            }

            else {
                cout << "stack is empty" << endl;
                return -1;
            }
        }

        bool isEmpty() {
            if(top == -1) {
                return true;
            }

            else { // top >= 0;
                return false;
            }
        }

        void print() {
            for(int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

};

int main() {

    myStack st(5);

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    st.print();

    st.pop();
    
    st.print();

    int a = st.peek();
    cout << "top element is: " << a << endl;

    if(st.isEmpty()) {
        cout << "Stack is empty" << endl;
    }

    else {
        cout << "Stack is not empty" << endl;
    }


 return 0;
}