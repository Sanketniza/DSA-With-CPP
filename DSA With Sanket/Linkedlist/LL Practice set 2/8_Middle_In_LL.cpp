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

void FindMiddle(Node *&head) {

    // first count the nodes
    int len = 0;
    Node *temp = head;

    while(temp != NULL) {
        len++;
        temp = temp -> next;
    }

   cout << "Length is : "<< len << endl;
   
   int mid = len / 2;

   cout << "Middle is : " << mid << endl;

   temp  = head;
   int cnt = 0;

   while(cnt < mid) {
    temp = temp -> next;
    cnt++;
   }

   cout << "Middle element is : " << temp -> data << endl;

   head = temp;

}

int main() {

    Node *node1 = new Node (1);
    Node *node2 = new Node (2);
    Node *node3 = new Node (3);
    Node *node4 = new Node (4);
    Node *node5 = new Node (5);
    Node *node6 = new Node (6);

    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
    node5 -> next = node6;
    node6 -> next = NULL;

    Node *head = node1;

    print(head);

    FindMiddle(head);

    print(head);

 return 0;
}