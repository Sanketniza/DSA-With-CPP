#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int d) {
            this -> data = d;
            this -> next = NULL;
        }



};

void solve(Node *head) {

    Node *temp = head;

    int len = 1;

    while(temp != NULL) {
        len++;
        temp = temp -> next;
    }

    temp = head;

    int mid = len / 2;

    int cnt = 1;

    while (cnt < mid) {
        temp = temp -> next;
        cnt++;
    }

    cout << "Middle is : " << temp -> data << endl;

    while(temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

void print(Node *head) {
    
    Node *temp = head;

    while (temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

int main() {

    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);

    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
    node5 -> next = node6;
    node6 -> next = NULL;

    Node *head = node1;

    cout << "Linked List is : ";
    print(head);

    // --------------------------------------------

    solve(head);


 return 0;
}