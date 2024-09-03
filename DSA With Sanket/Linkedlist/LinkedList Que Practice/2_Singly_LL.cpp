
#include<iostream>
using namespace std;
 
class Node{
  
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

void print(Node *&head ) {
    
    Node *temp = head;

    while (temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << endl << endl;
}

void insertAtHead(Node *&head , int data) {

    Node *temp = new Node(data);
     temp -> next = head;
     head = temp;
     
}

void insertAtTail (Node *&tail , int data) {

    Node *temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

void insertAtPosition(Node *&head , Node *&tail , int position , int data) {

    // only one node
    if(position == 1) {
        insertAtHead(head, data);
        return;
    }

    // if(tail -> next == NULL) {
    //     insertAtTail(tail, data);
    //     return;
    // }

    Node *temp = head;
    int cnt = 1;

    while(cnt < position - 1) {
        temp = temp -> next;
        cnt++;
    }

     if(temp -> next == NULL) {
        insertAtTail(tail, data);
        return;
    }

    Node *nodeTOInsert = new Node(data);
    nodeTOInsert -> next = temp -> next;
    temp -> next = nodeTOInsert;
     
}


int length(Node *&head) {

    Node *temp = head;
    int len = 0;

    while (temp != NULL){
        len++;
        temp = temp -> next;
    }

    return len;
}

void deleteNode(Node *&head , Node *&tail , int position) {

    if(position == 1) {
        Node *temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }

    else {
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;

        while (cnt < position -1 ) {

            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;

        if(curr == tail) {
            tail = prev;
        }

        delete curr;
    }
}

int main() { 
 
    // Create a new Node
    Node * node1 = new Node (12);
    Node* head = node1;
    Node * tail = node1;

    print(head);

    //insert node

    insertAtHead(head, 11);
    print(head);
    insertAtHead(head, 10);
    print(head);
    insertAtTail(tail, 13);
    print(head);
    insertAtTail(tail, 14);
    print(head);
    insertAtTail(tail, 15);
    print(head);


    // insert at position

    insertAtPosition( head , tail , 1 , 9 );
    print(head);
    insertAtPosition( head , tail , 1 , 8 );
    print(head);
    insertAtPosition( head , tail , 3 , 128 );
    print(head);
    insertAtPosition( head , tail , 10 , 18 );
    print(head);
 

 // delete operation

    deleteNode(head , tail , 1);
    print(head);
    deleteNode(head , tail , 1);
    print(head);
    deleteNode(head , tail , 4);
    print(head);
    deleteNode(head , tail , 8);
    print(head);


    // pointer 
    cout << "head at : " << head -> data << endl;
    cout << "tail at : " << tail -> data << endl;


    // length of ll
    cout << "length of ll : " << length(head) << endl;
    

    return 0;
}