#include<iostream>
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

Node *merge(Node* &head1, Node* &head2) {
    

    // base case
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node* mergedHead = NULL;

    if(head1 -> data <= head2 -> data) {
        mergedHead = head1;
        mergedHead -> next = merge(head1 -> next, head2);
    } 
    
    else {
        mergedHead = head2;
        mergedHead -> next = merge(head1, head2 -> next);
    }

    return mergedHead;
}

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" <<endl;
}

int main() {

    Node *head1 = new Node(1);
    Node *temp1 = new Node(3);
    Node *temp2 = new Node(5);
    Node *temp3 = new Node(17);
    head1->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = NULL;

    Node *head2 = new Node(2);
    Node *temp7 = new Node(4);
    Node *temp8 = new Node(6);
    Node *temp9 = new Node(8);
    Node *temp10 = new Node(10);
    Node *temp11 = new Node(12);
    Node *temp12 = new Node(14);
    head2->next = temp7;
    temp7->next = temp8;
    temp8->next = temp9;
    temp9->next = temp10;
    temp10->next = temp11;
    temp11->next = temp12;
    temp12->next = NULL;

    print(head1);
    cout << "------------------------------" << endl;
    print(head2);
    cout << "------------------------------" << endl;

    Node *head = merge(head1, head2);
    print(head);


 return 0;
}