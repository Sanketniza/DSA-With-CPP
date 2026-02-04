#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:

    int data;
    Node *next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

};

void insertArHead(Node *&tail , int d , int position) {

    // if no node is present , empty csll
    if(tail == NULL) {
        Node *temp = new Node(d);
        tail = temp;
        tail -> next = tail;
    }
    else {

        int cnt = 1;
        Node *temp = tail;

        while (temp => data != position) {
            temp = temp -> next;
        }

        Node *curr = new Node (d);

    }
}

void print (Node *tail) {

    if(tail == NULL) {
        cout << "list is empty" << endl;
    }

    Node *temp = tail;

    do{
        cout << tail -> data;
        tail = tail -> next;

    }while(tail != temp )

    cout << "tail " << endl;
}

int main() {

    Node *tail = NULL

    insertArHead(tail , 2 , 0);
 return 0;
}