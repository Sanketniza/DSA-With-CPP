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

Node *solve(Node *head , int left , int right) {

    // base case
    if(!head || left == right) {
        return head;
    }

    Node *dummy = new Node(0);
    dummy -> next = head;

    Node *prevL = dummy;
    
    for(int i = 1; i < left; i++) {
        prevL = prevL -> next;
    }


    Node *curr = prevL -> next; 
    Node *prev = NULL;
    Node *next = NULL;

    for(int i = left; i <= right; i++) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }

    prevL -> next -> next = curr;
    prevL -> next = prev;

    return dummy -> next;
}

void print(Node *head) {

    Node *temp = head;

    while(temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }

    cout << "NULL" << endl;
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
    node5 -> next = NULL;

    Node *head = node1;

    Node *ans = solve(head , 2 , 4);

    print(ans);

 return 0;
}