/* 
    ?: Design a stack that supports getMin() in O(1) time and O(1) extra space.
    ?: https://www.naukri.com/code360/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465?topList=love-babbar-dsa-sheet-problems%3Fsource%3Dyoutube&campaign=Codestudio_Lovebabbar


    roblem statement
Create a stack data structure that allows operations such as push (adding an element), pop (removing the top element), top (retrieving the top element), and also provides a way to retrieve the minimum element in constant time.



Implement the following public functions :

1. push(data) :
This function should take one argument of type integer. It pushes the element into the stack and returns nothing.

2. pop() :
It pops the element from the top of the stack and returns nothing.

3. top() :
It returns the element being kept at the top of the stack.

4.  getMin() :
It returns the smallest element present in the stack.
Operations Performed on the Stack:
Query-1(Denoted by an integer 1): Pushes integer data to the stack. (push function)

Query-2(Denoted by an integer 2): Pops the data kept at the top of the stack. (pop function)

Query-3(Denoted by an integer 3): Fetches and returns the data being kept at the top of the stack. (top function)

Query-4(Denoted by an integer 4): Returns the smallest element present in the stack. (getMin() function)
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
6
1 13
1 47
3
1 8
2
4
Sample Output 1:
47
13
Explanation of Input 1:
Here we have six queries in total.
 */

#include<iostream>
#include<stack>
using namespace std;

class SpecialStack {
    public:
        stack<int> s;
        int mini;

        void push(int data) {

            if(s.empty()) {  // initial case when on any element is not present , so we will push the element and make it minimum , means this step is only for the first element , it excute only one time.
                s.push(data);
                mini = data;
            }

            else {

                if( data < mini) {  // if the data is less than mini , we will push the data in the stack and make it minimum , means this step is for the all the element except the first element.
                    int val = 2*data - mini;
                    s.push(val);
                    mini = data;
                }

                else {  // if the data is not less than mini , we will push the data in the stack.
                    s.push(data);
                }
            }
        }

        int pop() {

            if(s.empty()) {  // if the stack is empty , we will return -1.
                return -1;
            }

            int curr = s.top();
            s.pop();

            if(curr > mini) {  // if the curr is greater than mini , we will return the curr.
                return curr;
            }

            else {  // if the curr is less than mini , we will return the mini.
                int prevMin = mini;
                int val = 2*mini - curr;
                mini = val;
                return prevMin;
            }

        }

        int top() {
            if(s.empty()) {  // if the stack is empty , we will return -1.
                return -1;
            }

            int curr = s.top();
            if(curr < mini) {  // if the curr is less than mini , we will return the mini.
                return mini;
            }

            else {  // if the curr is greater than mini , we will return the curr.
                return curr;
            }
        }

        int getMin() {
            if(s.empty()) {  // if the stack is empty , we will return -1.
                return -1;
            }
            
            else {  // if the stack is not empty , we will return the mini.
                return mini;
            }
            
        }
};

int main() {

    SpecialStack s;

    s.push(5);
    cout  <<"Minimum element in the stack is: " << s.getMin() << endl;

    s.push(3);
    cout  <<"Minimum element in the stack is: " << s.getMin() << endl;

    s.push(8);
    cout  <<"Minimum element in the stack is: " << s.getMin() << endl;

    s.push(2);
    cout  <<"Minimum element in the stack is: " << s.getMin() << endl;

    s.push(4);
    cout  <<"Minimum element in the stack is: " << s.getMin() << endl;

    cout << "----------------------------------------" << endl;
    
    cout  <<"Top element in the stack is: " << s.top() << endl;
    s.pop();
    cout  <<"Top element in the stack is: " << s.top() << endl;

    s.pop();
    cout  <<"Top element in the stack is: " << s.top() << endl;

    s.pop();
    cout  <<"Top element in the stack is: " << s.top() << endl;

    s.pop();
    cout  <<"Top element in the stack is: " << s.top() << endl;
    
    

 return 0;
}