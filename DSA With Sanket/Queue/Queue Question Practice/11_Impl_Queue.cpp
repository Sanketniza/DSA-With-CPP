#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class q {
    public:
        int *arr;
        int size;
        int front;
        int rear;
        int capacity;
        int cout;

        q(int s) {
            arr = new int[s];
            front = 0;
            rear = -1;
            capacity = size;
            count = 0;
        }

        void push(int data) {

            if(count == capacity) {
                cout << "Queue is full" << endl;
                return;
            }

            rear++;
            arr[rear] = data;
            count++;
        }

        void pop() {
            
            if(count == 0) {
                cout << "Queue is empty" << endl;
                return;
            }

            else if(front == rear) {
                front = 0;
                rear = -1;
            }

            front++;
            count--;
        }

        int getFront() {
            if(count == 0) {
                cout << "Queue is empty" << endl;
                return -1;
            }
            return arr[front];
        }

        bool isEmpty() {
            return count == 0;
        }

        bool isFull() {
            return count == capacity;
        }

};

int main() {

    q q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << q.getFront() << endl;
    q.pop();
    q.pop();
    




 return 0;
}