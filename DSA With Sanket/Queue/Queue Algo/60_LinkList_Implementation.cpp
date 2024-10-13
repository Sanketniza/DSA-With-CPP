#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;       // Data part of the node
    Node* next;     // Pointer to the next node

    Node(int value) : data(value), next(nullptr) {} // Constructor
};

// Queue class using singly linked list
class Queue {
private:
    Node* front;    // Pointer to the front node
    Node* rear;     // Pointer to the rear node
    int count;      // Current size of the queue

public:
    Queue() : front(nullptr), rear(nullptr), count(0) {} // Constructor

    ~Queue() {
        while (!isEmpty()) {
            dequeue(); // Deallocate all nodes
        }
    }

    void enqueue(int item) {
        Node* newNode = new Node(item); // Create a new node
        if (rear) {
            rear->next = newNode; // Link the new node at the end
        }
        rear = newNode; // Update the rear pointer
        if (!front) {
            front = newNode; // If the queue was empty, set front to the new node
        }
        count++; // Increase the count
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front; // Store the front node
        front = front->next; // Move front to the next node
        delete temp; // Deallocate the old front node
        count--; // Decrease the count
        if (isEmpty()) {
            rear = nullptr; // If the queue is empty, set rear to nullptr
        }
    }

    bool isEmpty() {
        return (count == 0);
    }

    int size() {
        return count;
    }

    void print() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        Node* current = front; // Start from the front
        while (current) {
            cout << current->data << " --> "; // Print each element
            current = current->next; // Move to the next node
        }
        cout << "NULL" << endl;
    }
};

// Example usage
int main() {
    Queue q; // Create a queue

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.print(); // Output: Queue elements: 10 20 30

    cout << "Size: " << q.size() << endl; // Output: Size: 3

    q.dequeue();
    q.print(); // Output: Queue elements: 20 30

    cout << "Is empty: " << (q.isEmpty() ? "Yes" : "No") << endl; // Output: Is empty: No

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.print(); // Output: Queue is empty!

    if(q.isEmpty()) {
        cout << "Are Bhai Queue to empty ho gaya !" << endl;
        cout << "Size: " << q.size() << endl;
        cout << "mene bola thik hai to thik hai !" << endl;
    }
    else {
        cout << "Are Bhai Queue to empty nahi hua !" << endl;
    }

    q.dequeue();

    return 0;
}