#include <iostream>
using namespace std;

// todo: Stack Array Implementation

class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack(int s)
    {
        this->size = s;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            cout << "Popped value is " << arr[top] << endl;
            top--;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if(top == -1) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main()
{

    Stack st(5);
    //? Stack stack_name(size);

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    cout << "Top element of stack is " << st.peek() << endl;
    cout << "Size of stack is " << st.size << endl;

    st.pop();
    cout << "Top element of stack is " << st.peek() << endl;

    st.pop();
    cout << "Top element of stack is " << st.peek() << endl;

    st.pop();
    st.pop();
    st.pop();
    cout << "Top element of stack is " << st.peek() << endl;

    if (st.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }

    else
    {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}