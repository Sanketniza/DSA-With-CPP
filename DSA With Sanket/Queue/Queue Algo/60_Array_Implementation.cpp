#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;        // Array to store queue elements
    int capacity;    // Maximum number of elements in the queue
    int front;       // Index of the front element
    int rear;        // Index of the rear element
    int count;       // Current size of the queue

public:
    Queue(int size) {
        arr = new int[size]; // Allocate memory for the queue
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }
 
    ~Queue() {
        delete[] arr; // Free allocated memory
    }

    void push(int item) {
        if (count == capacity) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % capacity; // Circular increment
        arr[rear] = item;
        count++;
    }

    void pop() {
        if (empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        front = (front + 1) % capacity; // Circular increment
        count--;
    }

    bool empty() {
        return (count == 0);
    }

    int size() {
        return count;
    }

    void print() {
        if (empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

// Example usage
int main() {

    Queue q(5); // Create a queue of capacity 5

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    q.print(); // Output: Queue elements: 10 20 30

    cout << "Size: " << q.size() << endl; // Output: Size: 3

    q.pop();
    q.print(); // Output: Queue elements: 20 30

    cout << "Is empty: " << (q.empty() ? "Yes" : "No") << endl; // Output: Is empty: No
    q.pop();
    q.push(60);
    q.print(); // Output: Queue elements: 30 60

    return 0;
}