
#include<iostream>
using namespace std;
 
class Node {

    public:
        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;

        }

        ~Node() {
            int temp = this -> data;
            if(this -> next != NULL) {
                delete next;
                this -> next = NULL;
            }

            cout << " Memory is free for node with data " << temp << endl;
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

void insertAtPosition(Node *&head , Node *&tail ,int data , int pos) {

    if(pos == 1) {
        insertAtHead(head, data);
        return;
    }

    Node *curr = head;
    // Node *prev = NULL;

    int cnt = 1;

    while(cnt < pos - 1 && curr != NULL) {
        // prev = curr;
        curr = curr->next;
        cnt++;
    }

    if(curr == NULL) {
        insertAtTail(tail, data);
        return;
    }

    Node *nodeToInsert = new Node(data);
    nodeToInsert -> next = curr->next;
    curr -> next = nodeToInsert;

}


void deleteAtHead(Node *&head) {
    Node *temp = head;
    head = head -> next;
    temp -> next = NULL;
    delete temp; // delete the
}

void deleteAtTail(Node *&head , Node *&tail) {

    Node *temp = tail;
    Node *prev = head;

    while(prev -> next != tail) {
        prev = prev -> next;
    }

    prev -> next = NULL;
    tail = prev;
    delete temp;

}

void print(Node *head) {

    Node *temp = head;

    while (temp != NULL) {
        cout << " " << temp->data << " -> " ;
        temp = temp -> next;

        if(temp == NULL) {
            cout << " NULL " << endl;
        }
    }

    cout << endl;
}

void deleteAtPosition(Node *&head , int pos) {

    if(pos == 1) {
        deleteAtHead(head);
        return;
    }

    Node *curr = head;
    Node *prev = NULL;

    int cnt = 1;

    while (curr != NULL && cnt < pos) {
        prev = curr;
        curr = curr -> next;
        cnt++;
    }

    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;
}

int main() { 

    Node *node1 = new Node(1);

    Node *head = node1;
    Node *tail = node1;
    print(head);

    // Insert node

    insertAtHead(head, 2);
    print(head);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    print(head);

    insertAtTail(tail, 5);
    print(head);
    insertAtTail(tail, 6);
    insertAtTail(tail, 7);
    print(head);

    insertAtPosition(head , tail ,10, 2); 
    print(head);
    insertAtPosition(head , tail ,11, 1);
    print(head);
    insertAtPosition(head , tail ,12, 8);
    print(head);
    insertAtPosition(head , tail ,13, 5);
    print(head);

    // delete the 

    deleteAtHead(head);
    print(head);
    deleteAtHead(head);
    print(head);


    cout << "head : " << head -> data << endl;
    cout << "tail : " << tail -> data << endl;

    deleteAtTail(head , tail);
    print(head);

    cout << "head : " << head -> data << endl;
    cout << "tail : " << tail -> data << endl;

    deleteAtPosition(head , 3);
    print(head);

    cout << "head : " << head -> data << endl;
    cout << "tail : " << tail -> data << endl;

    return 0;
}