// todo: sort the singly linked list

#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to merge two sorted linked lists
Node* mergeSortedLists(Node* a, Node* b) {
    Node* result = NULL;
    
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    
    if (a->data <= b->data) {
        result = a;
        result->next = mergeSortedLists(a->next, b);
    } else {
        result = b;
        result->next = mergeSortedLists(a, b->next);
    }
    
    return result;
}

// Function to get the middle of the linked list
Node* getMiddle(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;
    
    Node* slow = head;
    Node* fast = head->next;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

// Function to sort the linked list using merge sort
Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;
    
    Node* middle = getMiddle(head);
    Node* nextOfMiddle = middle->next;
    
    middle->next = NULL;
    
    Node* left = mergeSort(head);
    Node* right = mergeSort(nextOfMiddle);
    
    Node* sortedList = mergeSortedLists(left, right);
    
    return sortedList;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to insert a new node at the end of the list
void insertAtEnd(Node* &head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    Node* head = NULL;

    // Insert some elements
    insertAtEnd(head, 64);
    insertAtEnd(head, 34);
    insertAtEnd(head, 25);
    insertAtEnd(head, 12);
    insertAtEnd(head, 22);
    insertAtEnd(head, 11);
    insertAtEnd(head, 90);

    cout << "Original list: ";
    printList(head);

    // Sort the list
    head = mergeSort(head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
