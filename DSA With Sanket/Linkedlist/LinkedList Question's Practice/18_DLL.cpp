#include<iostream>
using namespace std;

class  Node{
    public:
        int data;
        Node *prev;
        Node *next;

        Node(int d) {
            this -> data = d;
            this -> prev = NULL;
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

void insertAtHead(Node *&head , int data) {

    Node *temp = new Node(data);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

void insertAtTail(Node *&tail , int data) {

    Node *temp = new Node(data);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
}

void print (Node *head) {

    Node *temp = head;

    while (temp != NULL) {
        cout << " <- " << temp -> data << " ->";
        temp = temp -> next;

        // if(temp -> next != NULL) {
        //     cout << " <-> ";
        // }
    }
    cout << endl;
}

int main() {

    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;

    print(head);

    //---------------------------------------------

    insertAtHead(head, 2);
    print(head);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    print(head);

    cout << "Head : " << head -> data << endl;
    cout << "Tail : " << tail -> data << endl;

    // --------------------------------------------

    insertAtTail(tail, 6);
    print(head);
    insertAtTail(tail, 7);
    insertAtTail(tail, 8);
    insertAtTail(tail, 9);
    print(head);

    cout << "Head : " << head -> data << endl;
    cout << "Tail : " << tail -> data << endl;

    // ----------------------------------------------

 return 0;
}