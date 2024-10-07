
/* 
  ? link: https://www.naukri.com/code360/problems/deque_1170059?leftPanelTab=0%3Fsource%3Dyoutube&campaign=LoveBabbar_Codestudio&leftPanelTabValue=PROBLEM

  roblem statement
Design a data structure to implement deque of size ‘N’. It should support the following operations:

pushFront(X): Inserts an element X in the front of the deque. Returns true if the element is inserted, otherwise false.

pushRear(X): Inserts an element X in the back of the deque. Returns true if the element is inserted, otherwise false.

popFront(): Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.

popRear(): Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.

getFront(): Returns the first element of the deque. If the deque is empty, it returns -1.

getRear(): Returns the last element of the deque. If the deque is empty, it returns -1.

isEmpty(): Returns true if the deque is empty, otherwise false.

isFull(): Returns true if the deque is full, otherwise false.
Following types of queries denote these operations:

Type 1: for pushFront(X) operation.
Type 2: for pushRear(X) operation.
Type 3: for popFront() operation.
Type 4: for popRear() operation.
Type 5: for getFront() operation.
Type 6: for getRear() operation.
Type 7: for isEmpty() operation.
Type 8: for isFull() operation.
 */

#include<iostream>
#include<queue>
using namespace std;

class Deque {
    int *arr;
    int front;
    int rear;
    int size;

public:
    Deque(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void pushFront(int x) {
        if (isFull()) {
            cout << "Deque is full" << endl;
            return; // Prevent further execution
        }

        if (front == -1) { // If deque is empty
            front = 0;
            rear = 0; // Initialize rear as well
        } else {
            front = (front - 1 + size) % size; // Move front back
        }
        arr[front] = x;
        cout << "Pushed element in front: " << arr[front] << endl; // Output
    }

    void pushRear(int x) {
        if (isFull()) {
            cout << "Deque is full" << endl;
            return; // Prevent further execution
        }

        if (rear == -1) { // If deque is empty
            front = 0; // Initialize front as well
            rear = 0;
        } else {
            rear = (rear + 1) % size; // Move rear forward
        }
        arr[rear] = x;
        cout << "Pushed element in rear: " << arr[rear] << endl; // Output
    }

    int popFront() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl; // Message for empty deque
            return -1;
        }

        int x = arr[front];
        cout << "Popped element in front: " << x << endl; // Output
        if (front == rear) { // If deque becomes empty after pop
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size; // Move front forward
        }
        return x; // Return the popped value
    }

    int popRear() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl; // Message for empty deque
            return -1;
        }

        int x = arr[rear];
        cout << "Popped element in rear: " << x << endl; // Output
        if (front == rear) { // If deque becomes empty after pop
            front = -1;
            rear = -1;
        } else {
            rear = (rear - 1 + size) % size; // Move rear back
        }
        return x; // Return the popped value
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl; // Message for empty deque
            return -1;
        }
        cout << "Front element is: " << arr[front] << endl; // Output
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl; // Message for empty deque
            return -1;
        }
        cout << "Rear element is: " << arr[rear] << endl; // Output
        return arr[rear];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (front == rear + 1) || (front == 0 && rear == size - 1);
    }
};

int main() {
    Deque *deq = new Deque(3);

    deq->pushFront(15);
    deq->pushFront(22);

    cout << endl << "------------" << endl;

    deq->getFront();

    cout << endl << "------------" << endl;

    deq->pushRear(10);
    deq->pushRear(20);

    cout << endl << "------------" << endl;

    deq->getRear();

    cout << endl << "------------" << endl;

    deq->popFront();
    deq->popRear();

    cout << endl << "------------" << endl;

    deq->getFront();
    deq->getRear();

    cout << endl << "------------" << endl;

    deq->pushFront(15);
    deq->pushFront(22);
    deq->popFront();
    deq->popFront();
    deq->popFront();

    if (deq->isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}