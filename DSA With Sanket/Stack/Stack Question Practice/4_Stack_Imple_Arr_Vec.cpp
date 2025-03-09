#include<iostream>
using namespace std;

class stack {

    public:
        int *arr;
        int top;
        int size;

        stack(int data) {
            this -> size = data; // size of the stack
            arr = new int[size]; // dynamic memory allocation for the stack , where size is the size of the stack
            top = -1; // initially the stack is empty
        }

        void push(int data) {

            if(size - top > 1) {
                top++;
                arr[top] = data;
            }

            else {
                cout << "Stack Overflow" << endl;
            }
        }

        void pop() {
            if(top >= 0) {
                cout << "Popped value is " << arr[top] << endl;
                top--;
            }

            else {
                cout << "Stack Underflow" << endl;
            }
        }

        int peek() {
            if(top >= 0) {
                return arr[top];
            }

            else {
                cout << "Stack is empty" << endl;
                return -1;
            }
        }

        bool isEmpty() {
            if(top == -1) {
                return true;
            }

            else {
                return false;
            }
        }

        void print() {

            cout << "Stack is: ";
            for(int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }


};

int main() {

    stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);
    st.print();

    st.pop();
    st.print();

    cout << "top element is : " << st.peek() << endl;

    cout << "stack is : " << st.isEmpty() << endl;

    if(st.isEmpty()) {
        cout << "Stack is empty" << endl;
    }

    else {
        cout << "Stack is not empty" << endl;
    }

    st.pop();
    st.pop();

    if(st.isEmpty()) {
        cout << "Stack is empty" << endl;
    }

    else {
        cout << "Stack is not empty" << endl;
    }

 return 0;
 
}