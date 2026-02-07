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

bool isCircular(Node *head) {

    // base candition
    if(!head || !head->next) {
        return true;
    }

    Node *temp = head->next;

    while (temp != NULL && temp != head) {
        temp = temp->next;
    }

    if(temp == head) {
        return true;
    }

    return false;
}

int main() {

    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = head;
    // fifth->next = NULL;

    if(isCircular(head)) {
        cout << "Linked list is circular" << endl;
    }
    else {
        cout << "Linked list is not circular" << endl;
    }

 return 0;
}