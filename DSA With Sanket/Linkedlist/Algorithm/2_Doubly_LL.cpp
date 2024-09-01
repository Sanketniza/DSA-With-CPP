#include<iostream>
using namespace std;
 
class Node{
  

    public:
     int data;
     Node *next;
     Node *prev;

     // constructor creating first  node with value 12
     Node (int d) {
         this -> data = d;
         this -> next = NULL;
         this -> prev = NULL;
    }
}; 

// Traversing the doubly linked list
void print(Node *head) {

    Node *temp = head;

    while (temp != NULL) {

        cout << "<- " << temp -> data << " -> " ;
        temp = temp -> next;
    }
    cout << "Next NULL" << endl;
}

int getLength(Node *head) {
    
    Node *temp = head;
    int len = 0;

    while (temp != NULL) 
    {
        len++;
        temp = temp -> next;
    }

    return len;
    
}

void insertAtHead(Node *&head ,int data) {

    Node *temp = new Node(data);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

void insertAtTail(Node *&tail ,int data) {
    
    Node *temp = new Node(data);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
}

void insertAtPosition(Node* & tail, Node* &head, int position, int d) {
    
    //insert at Start
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert ->next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}


int main() { 

// dynamic allocation
   // first node
    Node *node1 = new Node(12);

// pointer of nodes
    Node *head = node1;
    Node *tail = node1;
    // Node *prev = node1;


    print(head);

// inserting at head or beginning
    insertAtHead(head, 11);
    insertAtHead(head, 10);
    print(head);


// inserting at tail or end
    insertAtTail(tail, 14);
    insertAtTail(tail, 15);
    print(head);

// inserting at position
    insertAtPosition(tail , head, 1, 103);   
    print(head); 
    insertAtPosition(tail , head, 7, 153);   
    print(head); 
    insertAtPosition(tail , head, 4, 3);   
    print(head); 


// Length of doubly linked list
    cout << "Length : " << getLength(head) << endl;

    return 0;
}