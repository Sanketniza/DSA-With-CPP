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

    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }

};

void removeDuplicates(Node* &head) {

    //base condition
    if(head == NULL) {
        return;
    }

    Node *curr = head;
    Node *prev = NULL;

    while(curr != NULL) {

        if(prev != NULL && prev -> data == curr -> data) {
            Node* nodeToDelete = curr;
            curr = curr -> next;
            prev -> next = curr;
            // delete nodeToDelete;
        }

        else {
            prev = curr;
            curr = curr -> next;
        }
    }

}

void print(Node* head) {
    
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {

    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(20);
    Node* fourth = new Node(40);
    Node* fifth = new Node(40);
    Node* sixth = new Node(60);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

    cout << "original LL" << endl;
    print(head);

    // ------------------------
    
    
    removeDuplicates(head);

    cout << "After removing duplicates" << endl;
    print(head);

 return 0;
}