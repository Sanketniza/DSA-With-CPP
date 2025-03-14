#include<iostream>
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

void solve(Node *&head) {
    
    Node *prev = NULL;
    Node *curr = head;
    Node *forword = NULL;

    while (curr != NULL) {
        forword = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forword;
        // head = prev;
    }

    head = prev;
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

    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
    node5 -> next = NULL;

    Node *head = node1;

    cout << "Linked List is : ";
    print(head);
    cout << "head -> data : " << head -> data << endl;


    solve(head);

    cout << "Reversed Linked List is : ";
    print(head);
    cout << "head -> data : " << head -> data << endl;


 return 0;
}