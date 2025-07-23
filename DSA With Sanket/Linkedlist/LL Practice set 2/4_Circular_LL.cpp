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

bool solve(Node *head) {
    
    // base case

    if(head == NULL) {
        return true;
    }

    if( head -> next == NULL) {
        return false;
    }

    Node *temp = head -> next;

    while(temp != NULL && temp != head) {
        temp = temp -> next;
    }

    if(temp == head) {
        return true;
    }

    return false;
}

int main() {

    Node *node1 = new Node (1);
    Node *node2 = new Node (2);
    Node *node3 = new Node (3);
    Node *node4 = new Node (4);
    Node *node5 = new Node (5);

    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
    node5 -> next = node1;

    Node *head = node1;

    solve(head);
    if(solve) {
        cout << "Circular Linked List" << endl;
    }

    else {
        cout << "Not Circular Linked List" << endl;
    }

 return 0;
}