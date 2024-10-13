/* 
    ? lecture 61: Reverse First K ele Queue
    ? link: https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

    Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.
 */

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class One {
    public:
    

};

int main() {

    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    int k = 3;

    cout << "Original Queue: " << endl;
    queue<int> temp = q; // Create a temporary queue to hold the original queue elements
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }

    stack<int> s;
    
    // step 1: push the first k elements of the queue to the stack
    for(int i = 0; i < k; i++) {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    // step 2: push the remaining elements of the queue to the stack
    while (!s.empty()) {
        int element = s.top();
        s.pop();
        q.push(element);
    }

    // step 3: push the elements of the stack to the queue
    int t = q.size() - k;
    while (!q.empty() && t--) {
        int element = q.front();
        q.pop();
        q.push(element);
    }
    
    cout << endl << "Reversed Queue: " << endl;
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

 return 0;
}