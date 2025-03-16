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

void sort(Node* &head) {

    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    Node* temp = head;

    while (temp != NULL) {

        if(temp -> data == 0) {
            count0++;
        }
        else if(temp -> data == 1) {
            count1++;
        }
        else {
            count2++;
        }

        temp = temp -> next;
    }

    temp = head;

    while(temp != NULL) {

        if(count0 != 0) {
            temp -> data = 0;
            count0--;
        }

        else if(count1 != 0) {
            temp -> data = 1;
            count1--;
        }

        else {
            temp -> data = 2;
            count2--;
        }

        temp = temp -> next;
    }
}

void print(Node* &head) {

    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;

        if(temp == NULL) {
            cout << "NULL";
        }
    }
    
    cout << endl;
}

int main() {

    Node* head = new Node(1);
    Node* second = new Node(0);
    Node* third = new Node(2);
    Node* fourth = new Node(1);
    Node* fifth = new Node(0);
    Node* sixth = new Node(2);
    Node* seventh = new Node(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = NULL;

   print(head);
   cout << "--------------------------------" << endl;

   // todo: first approach
   sort(head);
   print(head);
   cout << "--------------------------------" << endl;


 return 0;
}