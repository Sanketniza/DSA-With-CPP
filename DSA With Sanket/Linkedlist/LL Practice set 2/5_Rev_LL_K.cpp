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

void print(Node *head) {

    Node *temp = head;

    while(temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }

    cout << "NULL" << endl; 
}

Node *solve(Node *head , int k) {

    // base case
    if(head == NULL) {
        return NULL;
    }

    
    // check k element are presend in LL
    Node *temp = head;
    for(int i = 0; i < k; i++) {
        if(temp == NULL) {
            return head;
        }
        temp = temp -> next;
    }

    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    int cnt = 0;

    while (curr != NULL && cnt < k) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }

    if(curr != NULL) {
        head -> next = solve(curr , k);
    }

    return prev;
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

    int k = 3;
    print(head);

    Node *ans = solve(head , k);
    print(ans);
    
 return 0;
}