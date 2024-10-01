/* 
    todo: lecture 54 - Two Stack
    ? Implement 2 stack in an array
    *link:- https://www.naukri.com/code360/problems/two-stacks_983634?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_CodestudioLovebabbar5thfeb&leftPanelTabValue=PROBLEM

    Problem statement
    Design a data structure, which represents two stacks using only one array common for    both stacks. The data structure should support the following operations:

    push1(NUM) - Push ‘NUM’ into stack1.
    push2(NUM) - Push ‘NUM’ into stack2.
    pop1() - Pop out a top element from stack1 and return popped element, in case of    underflow return -1.
    pop2() - Pop out a top element from stack2 and return popped element, in case of    underflow return -1.
    There are 2 types of queries in the input

    Type 1 - These queries correspond to Push operation.
    Type 2 - These queries correspond to Pop operation.
    Note:

    1. You are given the size of the array.

    2. You need to perform push and pop operations in such a way that we are able to push   elements in the stack until there is some empty space available in the array.

    3. While performing Push operations, do nothing in the situation of the overflow of the  stack.
 */

#include<iostream>
using namespace std;

class TwoStack {

    int *arr;
    int top1;
    int top2;
    int size;

    public:

    TwoStack(int size) {
        this->size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }

    void push1(int num) {
        if(top2 - top1 > 1) {
            top1++;
            arr[top1] = num;
        }
        else {
            cout << "Stack Overflow" << endl;
        }
    }

    void push2(int num) {
        if(top2 - top1 > 1) {
            top2--;
            arr[top2] = num;
        }
        else {
            cout << "Stack Overflow" << endl;
        }
    }

    int pop1() {
        if(top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else {
            return -1;
        }
    }

    int pop2() {
        if(top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else {
            return -1;
        }
    }
};

int main() {

    TwoStack st(5);

    st.push1(1);
    st.push1(2);
 
    
    st.push2(10);
    st.push2(20);
    st.push2(30);

    cout << st.pop1() << endl;
    cout << st.pop2() << endl;


 return 0;
}