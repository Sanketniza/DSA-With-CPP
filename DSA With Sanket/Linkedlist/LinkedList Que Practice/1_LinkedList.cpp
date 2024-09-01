#include<iostream>
using namespace std;
 
class Node{
  
    public:
       int data;
       Node *next;

       Node(int data ) {
           this -> data = data;
           this -> next = NULL;
        }
}; 

void insertAtHead(Node *&head , int data) {

    Node *temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node *&tail , int data) {

    Node *temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

void insertAtPosition(Node *tail , Node  *head, int position , int d) {
    
    // if node or temp is at position first

    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

        while (cnt < position - 1) {
            temp = temp -> next;
            cnt ++;
        }


    if(tail -> next == NULL) {
        insertAtTail(tail, d);
        return;
    }

    // creating node for d
    Node *nodeTOInsert = new Node(d);
    nodeTOInsert ->next = temp -> next;
    temp -> next = nodeTOInsert;
}

void printNode (Node *head) {
    
    Node *temp = head;
    while (temp != NULL) {

        cout << temp -> data << " -> " ;
        temp = temp -> next;
    }
    cout << endl;
}

int main() { 

    Node *a = new Node(23);
    // cout << a->data << endl;

    Node *head = a;
    Node *tail = a;

    insertAtHead(head, 12);
    insertAtHead(head, 11);
    insertAtHead(head, 10);
    printNode(head);

    insertAtTail(tail, 14);
    insertAtTail(tail, 15);
    printNode(head);

    insertAtPosition(tail , head, 4, 105);
    printNode(head);

    cout << "head data " << head -> data << endl;
    cout << "tail data " << tail -> data << endl;

    return 0;
}