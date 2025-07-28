#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    priority_queue<int> maxHeap; // max heap;
    priority_queue<int , vector<int> , greater<int>> minHeap; // min heap;

    // max heap implementation
    cout << "Max Heap: " << endl;
    maxHeap.push(3);
    maxHeap.push(23);
    maxHeap.push(2);
    maxHeap.push(1);
    maxHeap.push(5);

    cout << "size of maxHeap is " << maxHeap.size() << endl;
    cout << "top element of maxHeap is " << maxHeap.top() << endl;
    maxHeap.pop();
    cout << "top element of maxHeap after pop is " << maxHeap.top() << endl;
    cout << "size of maxHeap after pop is " << maxHeap.size() << endl;

    cout << "Element of maxHeap: " << endl;
    while(!maxHeap.empty()) {
        cout << maxHeap.top() << " " ;
        maxHeap.pop();
    }

    // min heap implementation
    cout << endl << "Min Heap: " << endl;
    minHeap.push(3);
    minHeap.push(23);
    minHeap.push(2);
    minHeap.push(1);
    minHeap.push(5);

    cout << "size of minHeap is " << minHeap.size() << endl;
    cout << "top element of minHeap is " << minHeap.top() << endl;
    minHeap.pop();
    cout << "top element of minHeap after pop is " << minHeap.top() << endl;
    cout << "size of minHeap after pop is " << minHeap.size() << endl;

    cout << "Element of minHeap: " << endl;
    while(!minHeap.empty()) {
        cout << minHeap.top() << " " ;
        minHeap.pop();
    }
 return 0;
}