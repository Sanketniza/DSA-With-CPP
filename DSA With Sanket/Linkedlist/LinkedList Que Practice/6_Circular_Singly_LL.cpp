
#include<iostream>
using namespace std;
 
class Node{

    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node ()  {
        int val = this -> data;

        if(next != NULL) {
            delete next;
            next = NULL;
        }

        cout << "Memory is free for node with data " << val << endl;
    }
  
}; 

void insertAtHead(Node *&head , Node *&tail , int data) {

    if(head == NULL) {
        Node *temp = new Node(data);
        head = temp;
        tail = head;
        cout << "Node with tail " << tail -> data << endl;
    } 

    else {
        Node *temp = new Node (data);
        temp -> next = head;
        head = temp;
        cout << "tail inserting asd : " << temp -> data << endl;
        tail  = temp -> next;
        cout << "tail inserting : " << temp -> data << endl;
    }
}

void insertAtTail(Node *&head , Node *&tail , int data) {

    if(tail == NULL) {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }

    else {
        Node *temp = new Node(data);
        tail -> next = temp;
        tail = temp;
        cout << "head inserting : " << head -> data << endl;
        cout << "tail inserting : " << tail -> data << endl;
        tail = head -> next;
        cout << "head inserting : " << head -> data << endl;
        cout << "tail inserting : " << tail -> data << endl;
    }
}

void print(Node *head) {

    Node *temp = head;

    while (temp != NULL) {
        cout << " " << temp -> data << " -> ";
        temp = temp -> next;

        if(temp == NULL) {
            cout << head -> data  << endl;
        }
    }
}

int main() { 

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 1);
    // print(head);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 22);
    insertAtHead(head, tail, 12);
    print(head);

    cout << endl;
    cout << "head : " << head -> data << endl;
    cout << "tail : " << tail -> data << endl;

    // insertAtTail(head, tail, 3);
    // print(head);
    // cout << endl;
    // cout << "head : " << head -> data << endl;
    // cout << "tail : " << tail -> data << endl;
    // cout << "tail -> next : " << tail -> next -> data << endl;


    return 0;
}