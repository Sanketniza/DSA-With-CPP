#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Queue {

    int *arr;
    int  front;
    int rear;
    int size;

public:
    Queue(int size) {
        this -> size = size;
        front = 0;
        rear = -1;
        arr = new int[size];
    }

    void push(int x) {

        if(rear < size) {
            rear++;
            arr[rear] = x;
        }

        else if (rear == size) {
            cout << "Queue is full" << endl;
        }
    }

    void pop(){



        if(front == rear) {
            front = 0;
            rear = -1;
            cout << "Queue is empty" << endl;
        }

        else if(front == size) {
            cout << "Queue is empty" << endl;
        }

        else {
            front++;
        }
    }

    int getFront() {

        if(front == rear) {
            cout << "Queue is empty" << endl;
        }

        else {
            return arr[front];
        }
    }

    int getRear() {

        if(front != size) {
            return arr[rear];
        }

        else {
            cout << "Queue is empty" << endl;
        }
    }

    bool isEmpty() {

        if(front == rear) {
            return true;
        }

        else {
            return false;
        }
    }

    int getMin() {

        if(front == rear) {
            cout << "Queue is empty" << endl;
        }

        else {
            int min = arr[front];
            for(int i = front; i <= rear; i++) {
                if(arr[i] < min) {
                    min = arr[i];
                }
            }
            return min;
        }
    }

    void print() {
        cout << "Queue elements: ";
        if(front == rear) {
            cout << "Queue is empty" << endl;
        }

        else {
            for(int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};


int main() {

    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.print();

    cout << q.getMin() << endl;
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;

    q.pop();
    q.print();

    cout << q.getMin() << endl;
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;

    if(q.isEmpty()) {
        cout << "Queue is empty" << endl;
    }

    else {
        cout << "Queue is not empty" << endl;
    }

    q.pop();
    q.pop();

    if(q.isEmpty()) {
        cout << "Queue is empty" << endl;
    }

    else {
        cout << "Queue is not empty" << endl;
    }

    q.push(4);
    q.push(5);
    q.push(6);
    q.push(6);
    q.push(6);
    q.push(6);
    q.push(6);
    q.print();

    q.push(7);
    q.push(7);
    q.push(7);
    q.push(7);
    q.push(7);
   
    // q.pop();
    // q.pop();
    // q.pop();
    q.print();
    q.pop();
    q.pop();
    q.print();




 return 0;
}