#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Two_Stack {
    public:
        int *arr;
        int size;
        int top1;
        int top2;

        Two_Stack(int size) {
            this -> size = size;
            top1 = -1;
            top2 = size;
            arr = new int[size];
        }

        void push1(int data) {
            if(top2 - top1 > 1) {
                top1++;
                arr[top1] = data;
            }

            else {
                cout << "Stack Overflow" << endl;
            }
        }

        void push2(int data) {
            if(top2 - top1 > 1) {
                top2--;
                arr[top2] = data;
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

    Two_Stack st(5);

    st.push1(1);
    st.push1(2);
    
    st.push2(4);
    st.push2(5);

    cout << "Top element of stack 1 is " << st.pop1() << endl;
    cout << "Top element of stack 2 is " << st.pop2() << endl;

 return 0;
}