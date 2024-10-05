#include<iostream>
#include<queue>
using namespace std;

int main() {

// todo: STL  Implementation

    queue<int> s;

    s.push(23);
    cout << "The front elelemnt in queue is : " << s.front() << endl;

    s.push(21);
    s.push(20);
    s.push(29);
    cout << "The front elelemnt in queue is : " << s.front() << endl;
    cout << "The size of queue is : " << s.size() << endl;

    s.pop();
    cout << "The size of queue is : " << s.size() << endl;

    s.pop();
    s.pop();
    cout << "The size of queue is : " << s.size() << endl;

    if(s.empty()) {
        cout << "queue is empty" << endl;
    }

    else {
        cout << "queue is not empty " << endl;
    }

    s.pop();
    cout << "The front element is queue is : " << s.front() << endl;
    cout << "THe size of queue is : " << s.size() << endl;

    if(s.empty()) {
        cout << "The is queue empty" << endl;
    }

    else {
        cout << "queue is not empty" << endl;
    }


 return 0;
}