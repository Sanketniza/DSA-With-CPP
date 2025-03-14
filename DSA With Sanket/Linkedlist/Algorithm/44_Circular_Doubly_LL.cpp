#include<iostream>
using namespace std;

class  Node{
    public:
        int data;
        Node *prev;
        Node *next;

        Node(int d) {
            this -> data = d;
            this -> prev = NULL;
            this -> next = NULL;
        }

        ~Node() {

            int value = this -> data;

            if(this -> next != NULL) {
                delete next;
                this -> next = NULL;
            }

            cout << "Memory is free for node with data " << value << endl;
        }

};

void insert(Node *&tail, int ele, int d) {

    if(tail == NULL) {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } 
    
    else {
        // non-empty DLL
        // assuming at least one node is present in the list

        Node *curr = tail;

        while(curr->data != ele) {
            curr = curr->next;
        }

        Node *temp = new Node(d);

        temp->next = curr->next;
        curr->next->prev = temp;
        curr->next = temp;
        temp->prev = curr;

        // Update tail if we're inserting after the current tail
        if (curr == tail) {
            tail = temp;
        }
    }

}

void DeleteNode(Node *&tail, int value) {

    if(tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node *Prevv = tail;
    Node *curr = Prevv -> next;

    while(curr -> data != value) {
        Prevv = curr;
        curr = curr -> next;
    }

    Prevv -> next = curr -> next;

    if(curr == tail) {
        tail = Prevv;
    }

    if(tail == curr) {
        tail = NULL;
    }
    
    curr -> next = NULL;
    curr -> prev = NULL;

    delete curr;
}

void print(Node *tail) {

    Node *temp = tail;

    if(tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    do{
        cout << "<- " << temp -> data << " -> ";
        temp = temp -> next;
    }while(tail != temp);

    cout << "Tail" << endl;
}

int main() {

    Node *tail = NULL;

    print(tail);
    // --------------------------------------------
    // Inserting at head

    insert(tail, 1 , 1);
    print(tail);
    cout << "tail : " << tail -> data << endl;

    insert(tail, 1 , 2);
    print(tail);
    cout << "tail : " << tail -> data << endl;

    insert(tail, 2 , 3);
    print(tail);
    cout << "tail : " << tail -> data << endl;

    insert(tail, 1 , 4);
    print(tail);
    cout << "tail : " << tail -> data << endl;

    insert(tail, 3 , 15);
    print(tail);
    cout << "tail : " << tail -> data << endl;

    insert(tail, 15 , 16);
    print(tail);
    cout << "tail : " << tail -> data << endl;

    // --------------------------------------------
    // deleting node on the basis of value not position.

    DeleteNode(tail , 15);
    print(tail);
    cout << "tail : " << tail -> data << endl;

    DeleteNode(tail , 16);
    print(tail);
    cout << "tail : " << tail -> data << endl;

    DeleteNode(tail , 1);
    print(tail);
    cout << "tail : " << tail -> data << endl;

 return 0;
}