/*

? Problem: Insert Element At Bottom Of Stack
? link- https://www.naukri.com/code360/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM


? Problem statement
You are given a stack/deque of integers 'MY-STACK' and an integer ‘X’. Your task is to insert ‘X’ to the bottom of ‘MY-STACK’ and return the updated stack/deque.

? Note :
If ‘MY_STACK’ = [7, 1, 4, 5], then the first element represents the element at the bottom of the stack and the last element represents the element at the top of the stack.
For Example :
Let ‘MY_STACK’ = [7, 1, 4, 5] and ‘X’ = 9. So, ‘MY_STACK’ after insertion becomes [9, 7, 1, 4, 5].

? Follow Up :
Try to do this without using any other data structure.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <=100
1 <= N <= 10^4
0 <= 'X’ and 'MY_STACK[i]’ <= 10^5

? Time limit: 1 second
Sample input 1 :
2
3 8
4 3 2
4 5
6 2 4 9
Sample Output 1 :
8 4 3 2
5 6 2 4 9
Explanation For Sample Input 1 :

*/

#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int x)
{

    //     // base case
    if (s.empty())
    {
        s.push(x);
        return;
    }

    //     // stored the top element
    int topElement = s.top();
    s.pop();

    //     // recursive call
    insertAtBottom(s, x);

    //     // backtrack
    s.push(topElement);
}

int main()
{

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    // take input from user
    int x;
    cout << "Enter the element to insert at bottom: " << endl;
    cin >> x;

    insertAtBottom(st, x);

    // print the stack
    cout << "Stack after inserting at bottom: " << endl;
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}