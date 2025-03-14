#include<iostream>
using namespace std;

class  Node{
    public:
    int data;
    Node* next;

    Node(int d) {
        this -> data = d;
        this -> next = NULL;
    }

};

bool isCircular(Node *head) {

    // * empty list
    if(head == NULL) {
        return true;
    }

    // * non-empty list
    Node *temp = head -> next;

    while(temp != NULL  && temp != head) {
        temp = temp -> next;
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
    // fifth->next = head;
    fifth->next = NULL;

    if(isCircular(head)) {
        cout << "Yes, it is a circular linked list" << endl;
    } else {
        cout << "No, it is not a circular linked list" << endl;
    }

 return 0;
}