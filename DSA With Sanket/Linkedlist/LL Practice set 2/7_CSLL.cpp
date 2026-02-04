#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:

    int data;
    Node *next;
    Node *prev;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }

};

void print(Node *tail) {

    Node *temp = tail;

    if(tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    do{
        cout << "<- " << temp -> data << " -> ";
        temp = temp -> next;
    }while(tail != temp);

    cout << "Tail" << endl;

}

void insertAtHead(Node *&head , int data) {

    if(head == NULL) {
        Node *temp = new Node(data);
        head = temp;
        temp -> next = temp;
        temp -> prev = temp;
    }

    else {
        Node *temp = new Node (data);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }

}



int main() {

    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;

    insertAtHead(head , 2);
    insertAtHead(head , 3);

    print(head);


    
 return 0;
}