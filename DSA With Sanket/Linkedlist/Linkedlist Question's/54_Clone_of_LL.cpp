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

void print(Node* &head) {

    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" <<endl;
}

int main() {

    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    print(head);
    cout << "------------------------------" << endl;

    Node *newHead = new Node(head->data);
    cout << "newHead : "; print(newHead);

    Node *temp = head->next;
    Node *newTemp = newHead;
    cout << "new temp data : " << newTemp -> data << endl;
    print(newTemp);

    while (temp != NULL) {
        Node *newNode = new Node(temp -> data);
        newTemp -> next = newNode;
        newTemp = newTemp -> next;
        temp = temp -> next;
    }

    cout << "New temp data  : " << newTemp -> data << endl;
    print(newTemp);

    print(newHead);
    cout << "------------------------------" << endl;

 return 0;
}