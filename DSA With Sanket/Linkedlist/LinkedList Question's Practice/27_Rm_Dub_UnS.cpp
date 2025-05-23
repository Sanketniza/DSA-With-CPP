#include<iostream>
using namespace std;

class  Node{
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

};

void removeDuplicates(Node* &head) {
    
    // base condition
    if(head == NULL) {
        return;
    }

    Node* curr = head;
    Node* index = NULL;

    while (curr != NULL) {

        index = curr -> next;

        while (index != NULL) {

            if(curr -> data == index -> data) {

                Node *temp = index;
                index = index -> next;
                curr -> next = index;
                temp -> next = NULL;
            }

            else {
                index = index -> next;
            }
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
    Node* second = new Node(20);
    Node* third = new Node(3);
    Node* fourth = new Node(3);
    Node* fifth = new Node(20);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    print(head);

    // --------------------- Remove Duplicates ---------------------
    removeDuplicates(head);
    print(head);

   
    

    


 return 0;
}