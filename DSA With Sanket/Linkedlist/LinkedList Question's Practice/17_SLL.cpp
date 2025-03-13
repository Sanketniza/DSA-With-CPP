#include<iostream>
using namespace std;

class Node {


    public:

    int data;
    Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }

        ~Node() {
            int value = this -> data;

            if(this -> next != NULL) {
                delete next;
                this -> next = NULL;
            }

            cout << "Memory is free for node with data " << value << endl;
        }
};

void insertAtHead(Node *&head ,int data) {
    
    Node *temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node *&head , Node *&tail , int data) {

    Node *temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

void print(Node *head) {

    Node *temp = head;

    while (temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next;

        if(temp == NULL) {
            cout << "NULL";
        }
    }

    cout << endl;
}

int main() {
    
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;

    print(head);

    insertAtHead(head, 2);
    print(head);

    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    print(head);
    cout << "Tail is " << tail -> data << endl;
    cout << "Head is " << head -> data << endl;

    // ----------------------------

    insertAtTail(head, tail, 6);
    print(head);

 return 0;
}