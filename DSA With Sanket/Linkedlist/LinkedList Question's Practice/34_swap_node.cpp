#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:

    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

};



void print(Node* head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {


    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    print(head);

    //* ------------------solution-------------------
   

    Node *dummy = new Node(0);
    dummy->next = head;
    Node *prev = dummy;
    Node *curr = head;

    while (curr || curr -> next) {

        Node *first = curr;
        Node *second = curr->next;

        prev->next = second;
        first->next = second->next;
        second->next = first;

        prev = first;
        curr = first->next;
    }

    curr = dummy->next;
    print(curr);


 return 0;
}