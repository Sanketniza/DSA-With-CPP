#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        node *next;

        node(int d) {
            this -> data = d;
            this -> next = NULL;
        }

};

void print(node *head) {

    cout << "The linked list is " << endl;

    node* temp = head;

    while(temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }

    if(temp == NULL) {
        cout << "NULL" << endl;
    }

    cout << endl << endl;
}

void midofLL(node *&head) {

    node *curr = head;
    node *forward = head;

    int cnt = 0;

    node *temp = head;

    while (temp != NULL) {
        cnt++;
        temp = temp -> next;
    }

    int mid = cnt / 2;

    while (cnt < mid) {
        curr = curr -> next;
        cnt++;
    }

    forward = curr -> next;
    curr -> next = NULL;
    // cout << forward -> data <<" is this " << endl;
    forward = forward -> next;
    head = forward;
}


int main() {
    // Create 5 nodes
    node* head = new node(1);
    node* second = new node(2);
    node* third = new node(3);
    node* fourth = new node(4);
    // node* fifth = new node(5);

    // Link the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth -> next = NULL;
    // fourth->next = fifth;
    // fifth->next = NULL;

    print(head);

    midofLL(head);

    print(head);

    return 0;
}