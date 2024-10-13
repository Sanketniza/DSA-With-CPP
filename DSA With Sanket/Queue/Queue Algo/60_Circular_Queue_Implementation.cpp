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
        rear++; // Increment rear
        arr[rear] = item; // Add item to the rear
        count++; // Increase the count
    }

    void pop() {
        if (empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        front++; // Increment front to remove the element
        count--; // Decrease the count
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
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " "; // Print elements from front to rear
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
    q.print(); // Output: Queue elements: 10 20 30

    cout << "Size: " << q.size() << endl; // Output: Size: 3

    q.pop();
    q.print(); // Output: Queue elements: 20 30

    cout << "Is empty: " << (q.empty() ? "Yes" : "No") << endl; // Output: Is empty: No

    return 0;
}