
/*
  Problem: Reverse Stack Using Recursion
  ? link - https://www.naukri.com/code360/problems/reverse-stack-using-recursion_631875?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM

  Problem statement
  Reverse a given stack of 'N' integers using recursion. You are required to make   changes in the input parameter itself.



  Note: You are not allowed to use any extra space other than the internal stack   space used due to recursion.



  Example:
  Input: [1,2,3,4,5]
  Output: [5,4,3,2,1]

*/

#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int topElement = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(topElement);
}

void reverseStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int topElement = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, topElement);
}

int main()
{

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "Before reversing the stack: " << endl;

    stack<int> temp = s;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    reverseStack(s);

    cout << "After reversing the stack: " << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
