#include<iostream>
using namespace std;

class  Node{
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void removeDuplicates(Node* &head) {

    // base condition
    if(head == NULL) {
        return;
    }

    Node *curr = head;
    Node *back = NULL;

    while (curr != NULL) {

        if(back != NULL && back -> data == curr -> data) {
            Node *nodeToDelete = curr;
            curr = curr -> next;
            back -> next = curr;
            curr -> prev = back;
            nodeToDelete -> next = NULL;
            nodeToDelete -> prev = NULL;
        }

        else {
            back = curr;
            curr = curr -> next;
        }

    }



}

void print(Node* head) {
    
    Node* temp = head;
    
    cout << "NULL <- ";
    do{
        cout << temp->data << " -> ";
        temp = temp->next;
    }while(temp != NULL);
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

    head->prev = NULL;
    second->prev = head;
    third->prev = second;
    fourth->prev = third;
    fifth->prev = fourth;
    sixth->prev = fifth;

    print(head);
    removeDuplicates(head);
    print(head);


 return 0;
}