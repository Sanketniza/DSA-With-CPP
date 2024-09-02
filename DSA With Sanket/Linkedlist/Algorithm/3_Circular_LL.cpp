
#include<iostream>
using namespace std;
 
class Node { 

    public:

    int data;
    Node *next;

    Node(int data ) {
        this -> data = data;
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

void InsertNode (Node *&tail , int element , int d) {
    
    // list is empty

    if( tail == NULL) {

        Node * newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
        // newNode -> next = tail;
    }

    else {

        //^ non empty list
        //^ assuming that the element is present in the list

        Node *curr = tail;

        while (curr -> data != element) {
            curr = curr -> next;
        }

        // element found -> curr is representing element wala node

        Node *temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }       
}

void print (Node *tail) {

    Node *temp = tail;

    if(tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    do
    {
        cout << tail -> data << " -> ";
        tail = tail -> next;

    } while (tail != temp);

    cout << endl;
}


void DeleteNode (Node * &tail , int value) {
    
    // empty list
    if (tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    else {
        // non empty list
        // assuming that the value is present in the list

        Node * prev = tail;
        Node * curr = prev -> next;

        while ( curr -> data != value ) {
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
}

int main() { 


    Node *tail = NULL;

    // inserting node on the basis of value .....

    InsertNode(tail , 5 , 3);
    print(tail);

    InsertNode(tail , 3 , 4);
    print(tail);

    InsertNode(tail , 4 , 6);
    print(tail);

    InsertNode(tail , 4 , 5);
    print(tail);

    InsertNode(tail , 3 , 15);
    print(tail);


    DeleteNode(tail , 15);
    print(tail);

    DeleteNode(tail , 3);
    print(tail);

 
    return 0;
}