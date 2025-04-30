#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    priority_queue<int> max;

    max.push(2);
    max.push(3);
    max.push(1);
    max.push(5);
    max.push(4);

    cout << "size of priority queue is : " << max.size()  << endl;
    cout << "top element of priority queue is : " << max.top() << " " << endl;

    max.pop();
    cout << "top element of priority queue after pop is : " << max.top() << " " << endl;

    cout << "size of priority queue after pop is : " << max.size()  << endl;
    cout << "elements of priority queue are : " << endl;
    while(!max.empty()) {
        cout << max.top() << " ";
        max.pop();
    }

    cout << endl;

    priority_queue<int , vector<int> , greater<int> > min;
    min.push(2);
    min.push(3);
    min.push(1);
    min.push(34);
    min.push(4);

    cout << min.size() << endl;
    cout << min.top() << endl;
    min.pop();

    cout << min.top() << endl;
    cout << min.size() << endl;

    cout << "elements of priority queue are : " << endl;
    while(!min.empty()) {
        cout << min.top() << " ";
        min.pop();
    }

    cout << endl;

 return 0;
}