
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

            int value = this -> data;

            if(this -> next == NULL ) {
                delete next;
                this -> next = NULL;
            }

            cout << "Memory is free for node with data " << value << endl;
        }

};

void Head(Node *&tail , int element ,int data) {

    if(tail == NULL) {
        Node *newNode = new Node(data);
        tail = newNode;
        newNode -> next = newNode;
    }

    else {
        Node *curr = tail;

        while(curr -> data != element) {
            curr = curr -> next;
        }

        Node *temp = new Node(data);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}

void deleteNode(Node *&tail , int element) {

    if(tail == NULL) {
       cout << "List is empty" << endl;
       return;
    }

    Node *prev = tail;
    Node *curr = prev -> next;

    while(curr -> data != element) {
        prev = curr;
        curr = curr -> next;
    }

    prev -> next = curr -> next;

    // single node is present in LL
    if(curr == prev) {
        tail = NULL;
    }

    // more than 1 node is present in LL
    if(tail == curr) {
        tail = prev;
    }

    curr -> next = NULL;
    delete curr;

}

void print(Node *tail) {

    Node *temp = tail;

    if(tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    do{
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }while (tail != temp);
    
    cout << "Tail" << endl;
}

int main() {


    Node *tail = NULL;

    //==============
    Head(tail ,1 , 13);
    print(tail);
    cout << "tail : " << tail -> data << endl;

    Head(tail ,13 , 14);
    print(tail);
    cout << "tail : " << tail -> data << endl;

    Head(tail ,14 , 15);
    print(tail);
    cout << "tail : " << tail -> data << endl;

    Head(tail ,13 , 16);
    print(tail);
    cout << "tail : " << tail -> data << endl;

    // ------------------

    deleteNode(tail , 15);
    print(tail);
    cout << "tail : " << tail -> data << endl;


 return 0;
}