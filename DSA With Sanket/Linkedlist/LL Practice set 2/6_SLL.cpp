#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:

    int data;
    Node *next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

};

void insertArHead(Node *&head , int d) {

    // create new node
    Node *temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertArTail( Node *&tail , int d) {

    // create new node
    Node *temp = new Node(d);
    tail -> next = temp;
    tail = temp;

}

void insertAtPosition(Node *&head , Node *&tail , int position , int d) {

    // if position is first , its mean's insertAtHead
    if(position == 1) {
        insertArHead(head , d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1) {
        temp = temp -> next ;
        cnt++;
    }

    // if temp is at last node (temp -> next == null) , it's mean's insertAtTail
    if(temp -> next == NULL) {
        insertArTail(tail , d);
        return;
    }

    // Otherwise create new node 
    Node *newNode = new Node(d);
    newNode -> next = temp -> next;
    temp -> next = newNode;
    
}

void deleteHead(Node *&head) {

    Node *temp = head;
    head = head -> next;
    temp -> next = NULL;
}

void deleteTail(Node *&head , Node *&tail) {
    Node *temp = head;

    while (temp -> next != tail) {
        temp = temp -> next;
    }

    tail = temp;
    tail -> next = NULL;

}



void print(Node *head) {
    if(head == NULL) return;

    // create temp node
    Node *temp = head;
    while (temp != NULL) {
        cout << temp -> data << " -> " ;
        temp = temp -> next;

        if(temp == NULL) {
            cout << "NULL";
        }
    }

    cout << endl;
}

int main() {
    Node *root = new Node(21);
    Node *head = root;
    Node *tail = root;

    // Insert into sll
    insertArHead(head , 23);

    insertArTail(tail , 34);

    insertAtPosition(head , tail , 2 , 344);
    print(head);

    // delete node
    // deleteHead(head);
    // deleteTail(head , tail);
    deleteAtPosition(head , tail , 2)

    // print sll
    print(head);


 return 0;
}