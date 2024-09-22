#include<iostream>
using namespace std;
 
class Node{
  
    public:
        int data;
        Node *next;

        // constructor creating first  node with value 12
        Node (int d) {
            this -> data = d;
            this -> next = NULL;
        }

        ~Node() {  //* destructor to delete node , memory free
            int value = this -> data;
            if(this -> next != NULL) {
                delete next;
                this -> next = NULL;
            }

            cout << "Memory is free for node with data " << value << endl;

        }
}; 

void insertArHead (Node* &head, int d) {
    
     Node *temp = new Node(d); // creating new node with value d 
     temp -> next = head;  // joining new node with first node 
     head = temp;
}

void insertArTail (Node* &tail, int d) {

    Node *temp = new Node(d); // creating new node with value d
    tail -> next = temp; // joining new node after first node or tail or end
    tail = temp;
}

void insertAtPosition (Node *&tail , Node* &head, int position , int d) {

// inset at head or first
    if (position == 1) {
        insertArHead(head, d);
        return;
    }
 
   Node *temp = head;
   int cnt = 1;

    while (cnt < position -1)
    {
        temp = temp -> next;
        cnt++;
    }

    // insert at tail
    if(temp -> next == NULL) {
        insertArTail(tail, d);
        return;
    }

    // creating node for d
    Node *nodeTOInsert = new Node(d);
    nodeTOInsert -> next = temp -> next;
    temp -> next = nodeTOInsert;
}

//deleting the node
 void deleteNode (Node* &head,Node * &tail, int position) {
     
     //^ deleting first node or start
     if(position ==  1) {
        Node *temp = head;
        head = head -> next;
         //^ memory free of starting node
        temp -> next = NULL;
        delete temp;  

    }

    else {  //^ deleting any middle node or last

     Node *curr = head;
     Node *prev = NULL;
     int cnt  = 1;

        while (cnt < position) {

            prev = curr;
            curr = curr -> next;
            cnt ++; // riced the position of node which is to be deleted
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        if(curr == tail){
            tail = prev;
        }
        
        // tail = prev;

        delete curr;
    }
}

void print(Node *head) {
    Node *temp = head;
    
    while (temp != NULL) {
        cout << temp -> data << " -> " ;
        temp = temp -> next ;
    }

    cout << endl;
}


int main() { 

    //? dynamic allocation
    Node *node1 = new Node(12); // creating initial (first) node with value 12
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    Node *head = node1;
    Node *tail = node1;

// inserting at head or beginning
    print(head);
    insertArHead(head, 11);
    print(head);
    insertArHead(head, 10);
    insertArHead(head, 9);
    insertArHead(head, 8);
    print(head);


// inserting at tail or end
    insertArTail(tail, 14);
    insertArTail(tail, 15);
    print(head);



// inserting at position
    insertAtPosition(tail , head, 3, 103);
    print(head);
    insertAtPosition(tail , head, 5, 104);
    print(head);
    insertAtPosition(tail , head, 1, 105);
    print(head);
    cout << endl;

// value at head and tail
    cout << "value at head : " << head -> data << endl << "value at tail : " << tail -> data << endl;

// deleting node

    deleteNode(head,tail , 8); //* deleting middle any  node
    print(head);
    cout << endl;

    deleteNode(head,tail , 9); //* deleting last node
    print(head);
    cout << endl;

    deleteNode(head,tail , 1);  //* deleting first node
    print(head);
    cout << endl;

// value at head and tail
    cout << "value at head : " << head -> data << endl << "value at tail : " << tail -> data << endl;  
    cout << endl;

    return 0;

}