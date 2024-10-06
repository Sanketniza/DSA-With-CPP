#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Initialize your data structure.
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool push(int value) {
        // Check whether the queue is full
        if ((rear + 1) % size == front) {
            cout << "Queue is full" << endl;
            return false; // Queue is full
        }
        else if (front == -1) { // First element to push
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % size; // Maintain cyclic nature
        }
        // Push inside the queue
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int pop() {
        if (front == -1) { // Check if the queue is empty
            return -1; // Queue is empty
        }
        int ans = arr[front];
        arr[front] = -1; // Optional: Clear the dequeued position
        if (front == rear) { // Single element is present
            front = rear = -1; // Reset the queue
        }
        else {
            front = (front + 1) % size; // Maintain cyclic nature
        }
        return ans; // Return the dequeued element
    }

    // Optional: Function to print the queue for debugging
    void print() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5); // Size of the queue is 5
    q.push(1);
    q.push(2);
    q.push(3);
    
    q.print(); // Print the queue

    q.pop();
    q.print(); // Print the queue after popping

    q.push(4);
    q.push(5);
    q.push(5);
 
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
 
    q.print(); // Print the queue

    return 0;
}