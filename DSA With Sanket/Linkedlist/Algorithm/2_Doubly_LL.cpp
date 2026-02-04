 #include<iostream>
using namespace std;
 
class Node{
  
     public:
        int data;
        Node* prev;
        Node* next;

    //constructor
    Node(int d ) {
        this-> data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node() {  //* destructor call to delete node , or to free the memory.
        int val = this -> data;
        
        if(next != NULL) {
            delete next;
            next = NULL;
        }

        cout << "memory free for node with data "<< val << endl;
    }
}; 

// Traversing the doubly linked list
void print(Node  *head , Node *tail) {

    Node *temp = head;

    while (temp != NULL) {

        cout << "<- " << temp -> data << " -> " ;
        temp = temp -> next;
    }
    cout << "Next NULL" << endl;

    cout << "Head : " << head -> data << endl;
    cout << "Tail : " << tail -> data << endl << endl;
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

void insertAtHead(Node *&tail,Node *&head ,int data) {

 //todo: initially no node is present .
    if(head == NULL) {  //^  if list is empty . no any before node is present
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else {    //^  if list is not empty . mean at least one node is present
        Node *temp = new Node(data);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&tail , Node* &head ,int data) {

    if ( tail == NULL)  // empty list , no any before node is present
    {
        Node *temp = new Node(data);
        tail = temp;
        head = temp;
    }

    else {  // if list is not empty . mean at least one node is present
        Node *temp = new Node(data);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
    
    
}

void insertAtPosition(Node* & tail, Node* &head, int position, int d) {
    
    //insert at Start
    if(position == 1) {
        insertAtHead(tail ,head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp -> next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,head ,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert ->next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

void deleteNode(int position, Node* & head , Node * & tail)  { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        if(curr == tail) {
            tail = prev;
        }

        delete curr;

    }
}

int main() { 

// dynamic allocation
  /* 
// first node
    Node *node1 = new Node(12);

// pointer of nodes
    Node *head = node1;
    Node *tail = node1;
    // Node *prev = node1;
 */

   Node *head = NULL;  // empty list
   Node *tail = NULL;  // empty list

// inserting at head or beginning
    insertAtHead(tail ,head, 11);
    insertAtHead(tail ,head, 10);
    print(head , tail);


// inserting at tail or end
    insertAtTail(tail,head , 14);
    insertAtTail(tail,head , 15);
    print(head , tail);

// inserting at position
    insertAtPosition(tail , head, 1, 103);   //* insert at start
    print(head , tail); 
    insertAtPosition(tail , head, 3, 153);    //* insert at middle
    print(head , tail); 
    insertAtPosition(tail , head, 7, 3);     //* insert at end
    print(head , tail); 


// delete node
    deleteNode( 1 , head , tail);  //* delete at start
    print(head , tail); 
    deleteNode( 4 , head , tail);  //* delete at middle
    print(head , tail); 
    deleteNode(5 , head , tail);  //* delete at end
    print(head , tail);

// Length of doubly linked list
    cout << "Length : " << getLength(head) << endl;

    return 0;
}