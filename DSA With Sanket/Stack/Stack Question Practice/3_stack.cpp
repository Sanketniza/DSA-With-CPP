#include<iostream>
#include<stack>
using namespace std;

class stack {

    public:
        int size;
        int *arr;
        int top;

        stack(int s) {
            this -> size = s;
            top = -1;
            arr = new int[size];
        }


        void push(int data) {

            if(size - top > 1) {
                top++;
                arr[top] = data;
            }

            else {
                cout << "stack is overflow " << endl;
            }
        }

        void pop() {

            if(top == -1) {
                cout << "stack is underflow" << endl;
            }

            else {
                cout << "Popped element is :" << arr[top] << endl;
                top--;
            }
        }

        void peck() {

            if(top == -1) {
                cout << "stack is empty" << endl;
            }

            cout << "Top element is : " << arr[top] << endl;
        }

        void isEmpty() {

            if(top == -1) {
               cout << "stack is empty" << endl;
            }

            else {
                cout << "stack is not empty" << endl;
            }
        }

};

int main() {

     stack st(5);
    //? Stack stack_name(size);

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    
 return 0;
}