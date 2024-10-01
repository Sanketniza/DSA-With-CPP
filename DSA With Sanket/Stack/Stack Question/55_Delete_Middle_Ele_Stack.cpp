/* 
   ? lecture 55: Delete Middle Element of Stack
   ? Link - https://www.naukri.com/code360/problems/delete-middle-element-from-stack_985246?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&leftPanelTabValue=SUBMISSION

   Problem Statement:
You are having a stack "ARR" of size 'N+1', your task is to delete the middlemost element so that the size of resulting stack is 'N'.

A stack is a linear data structure where both insertion and deletion of elements take place at the top. It follows FILO (First In Last Out) or LIFO (Last In First Out) approaches. Books piled on top of each other is an example of a stack, where you can only remove a single book at a time, which is at the top of the stack. Likewise, you can only add a single book at a time, on the top of the stack only.

Example :-
INPUT : ARR [ ] = [ 1 , 2 , 3 , 4 , 5 ] , N = 4
OUTPUT: ARR [ ] = [ 1 , 2 , 4,  5 ]

The above example contains an odd number of elements, hence the middle element is clearly the (N+1) / 2th element, which is removed from the stack in the output.

INPUT : ARR [ ] = [ 5, 6, 7, 8 ] , N = 3
OUTPUT: ARR [ ] = [ 5, 7, 8 ]

The above example contains an even number of elements, so out of the two middle elements, we consider the one which occurs first. Hence, the middle element would be ((N+1) / 2 - 1) element, which is 6 and is removed from the stack in the output.
 */

#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &s, int count, int size) {

    // base case
    if(count == size / 2) {
        s.pop();
        return;
    }

    // store the top element
    int temp = s.top();
    s.pop();

    // recursive call
    solve(s, count + 1, size);

    // backtracking
    s.push(temp);
}

int main() {

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "Original stack is: " << endl;
    stack<int> temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    int n = s.size();
    int count = 0;

    solve(s, count, n);

    cout << "Stack after deleting middle element is: " << endl;
    stack<int> temp2 = s;
    while (!temp2.empty()) {
        cout << temp2.top() << " ";
        temp2.pop();
    }
    cout << endl;
    return 0;
}