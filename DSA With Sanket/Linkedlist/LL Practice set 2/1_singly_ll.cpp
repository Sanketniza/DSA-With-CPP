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

    ~Node(){
        int value = this -> data;

        if(this -> next != NULL) {
            delete next;
            this -> next = NULL;
        }

        cout << "Memory is free for node with data " << value << endl;
    }

};

void insertAtHead(Node *&head , int data) {

    Node *temp = new Node (data);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node *&head , Node *&tail , int data) {
    
    Node *temp = new Node (data);
    tail -> next = temp;
    tail = temp;
}

void insertAtPosition(Node *&head , Node *&tail , int position , int data) {

    if(position == 1) {
        insertAtHead(head , data);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while(cnt < position - 1) {
        temp = temp -> next;
        cnt++;
    }

    if(temp -> next == NULL) {
        insertAtTail(head , tail , data);
        return;
    }

    Node *insert = new Node (data);
    insert -> next = temp -> next;
    temp -> next = insert;

}

void deleteAtPostition(Node *&head , Node *&tail , int position) {

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

        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

void print(Node *root) {

    cout << "print the the singly LL data" << endl;
    Node *temp = root;

    while(temp != NULL) {
        cout << temp -> data << " -> "; ;
        temp = temp -> next;
    } 

    if(temp == NULL) {
        cout << "NULL" << endl;
    }
    cout << endl;
}

int main() {

    Node *node1 = new Node(1);

    Node *head = node1;
    Node *tail = node1;

    print(head);

    insertAtHead(head , 2);
    insertAtHead(head , 3);
    print(head);

    insertAtTail(head , tail , 5);
    insertAtTail(head , tail , 6);
    print(head);

    cout << "Head " << head -> data << endl;
    cout << "Tail " << tail -> data << endl;

    insertAtPosition(head , tail , 2 , 22);
    print(head);

    deleteAtPostition(head , tail , 3);
    print(head);

 return 0;
}