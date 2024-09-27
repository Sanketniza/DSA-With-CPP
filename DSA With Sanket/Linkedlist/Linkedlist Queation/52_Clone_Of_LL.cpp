#include<iostream>

using namespace std;

class  Node{
    public:
    int data;
    Node* next;
    Node* random;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }

};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
}



int main() {

    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    print(head);


 return 0;
}