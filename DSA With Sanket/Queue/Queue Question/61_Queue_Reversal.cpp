/* 
    ? lecture 61: Queue Reversal
    ? link: https://www.geeksforgeeks.org/problems/queue-reversal/1

    Given a Queue Q containing N elements. The task is to reverse the Queue. Your task is to complete the function rev(), that reverses the N elements of the queue.

Example 1:

Input:
6
4 3 1 10 2 6
Output: 
6 2 10 1 3 4
 */

#include<iostream>
#include<queue>
#include<stack>

using namespace std;

int main() {

    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);

    cout << "Original Queue: " << endl;
    queue<int> temp = q; // Create a temporary queue to hold the original queue elements
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }

    stack<int> s;
    while (!q.empty()) {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while (!s.empty()) {
        int element = s.top();
        s.pop();
        q.push(element);
    }


    cout << endl << "Reversed Queue: " << endl;
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    

    

 return 0;
}