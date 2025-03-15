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

void sortLL(Node* &head) {

    // base condition
    if(head == NULL) {
        return;
    }

    Node *curr = head;
    Node *index = NULL;

    while (curr != NULL) {

        index = curr -> next;

        while (index != NULL) {

            if(curr -> data > index -> data) {
                swap(curr -> data , index -> data);
            }

            index = index -> next;
        }

        curr = curr -> next;
    }
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

    Node* head = new Node(10);
    Node* second = new Node(2);
    Node* third = new Node(30);
    Node* fourth = new Node(4);
    Node* fifth = new Node(50);
    Node* sixth = new Node(6);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

    print(head);

    sortLL(head);

    print(head);


 return 0;
}