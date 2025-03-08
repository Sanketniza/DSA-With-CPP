#include <iostream>
using namespace std;

class Node {

    public:
        int data;
        Node* prev;
        Node* next;

        Node(int data) {
            this -> data = data;
            this -> prev = NULL;
            this -> next = NULL;
        }

        ~Node() {
            int val = this -> data;

            if(next != NULL) {
                delete next;
                next = NULL; 
            }

            cout << "Memory free for node with data " << val << endl;

        }
};

void insertAtHead (Node *&head , Node *&tail , int data) {

    if(head == NULL) {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }

    else {
        Node *temp = new Node(data);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

void insertAtTail (Node *&tail , int data) {

    Node *temp = new Node(data);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
}

void insertAtPosition (Node *&head , Node *&tail , int position , int data) {
    
    if(position == 1) {
        insertAtHead(head, tail, data);
        return;
    }

    Node *curr = head;
    // Node *prev = NULL;
    int cnt = 1;

    while (cnt < position - 1) {
        curr = curr -> next;
        cnt++;
    }

    if(curr -> next == NULL) {
        insertAtTail(tail, data);
        return;
    }

    Node *nodeToInsert = new Node (data);
    nodeToInsert -> next = curr -> next;
    curr -> next -> prev = nodeToInsert;
    curr -> next = nodeToInsert;
    nodeToInsert -> prev = curr;

}

void length(Node *head) {

    int count = 0;

    Node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp -> next;
    }

    cout << "length of linked list is " << count << endl;
}

void deleteAtHead(Node *&head) {

    Node *temp = head;
    head = head -> next;
    temp -> next = NULL;
    delete temp;
}

void deleteAtTail(Node *&head , Node *&tail) {

    Node *temp = tail;
    Node *curr = head;

    while (curr -> next != NULL) {
        curr = curr -> next;
    }

    tail = curr -> prev;
    tail -> next = NULL;
    curr -> prev = NULL;
    delete temp;
}

void deleteAtPosition(Node *&head , Node *&tail , int position) {

    if(position == 1) {
        deleteAtHead(head);
        return;
    }

    Node *curr = head;
    // Node *prev = NULL;
    int cnt = 1;

    while (cnt < position) {
        // prev = curr;
        curr = curr -> next;
        cnt++;
    }

    curr -> prev -> next = curr -> next;
    curr -> next -> prev = curr -> prev;
    curr -> next = NULL;
    curr -> prev = NULL;
    delete curr;
}



void print(Node *head ) {

    Node *temp = head;

    while (temp != NULL) {
        cout << " " << temp -> data << " -> ";
        temp = temp -> next;

        if(temp == NULL) {
            cout << " NULL " << endl;
        }
    }
}


int main() {

    // Node *node1 = new Node(1);

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head,tail, 1);
    print(head);
    insertAtHead(head,tail, 2);
    insertAtHead(head,tail, 3);
    insertAtHead(head,tail, 4);
    print(head);

    insertAtTail(tail,5);
    print(head);
    insertAtTail(tail,6);
    insertAtTail(tail,7);
    print(head);

    insertAtPosition(head, tail, 1, 9);
    print(head);
    insertAtPosition(head, tail, 1, 8);
    insertAtPosition(head, tail, 3, 128);
    insertAtPosition(head, tail, 7, 129);
    print(head);

    length(head);

    insertAtPosition(head, tail, 12, 130);
    print(head);

// deletion of node
    deleteAtHead(head);
    print(head);

    deleteAtTail(head , tail);
    print(head);

    cout << "Head : " << head -> data << endl;
    cout << "Tail : " << tail -> data << endl;
    length(head);

    deleteAtPosition(head , tail , 3); 
    print(head);

    return 0;
}

