#include<iostream>
using namespace std;
 
class Sanket{
  

     public:
       int data;
       Sanket *next = NULL;
       Sanket *prev = NULL;

       Sanket (int data) {

        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
       }

}; 

void insertAtHead (Sanket * &tail , Sanket * &head , int d) {
    
    if(head == NULL) {

        Sanket *temp = new Sanket(d);
        head = temp;
        tail = temp;
    }
    
    else{

        Sanket *temp = new Sanket(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}


void insertAtTail (Sanket * &tail , Sanket * &head , int d) {
    
    if(tail == NULL) {

        Sanket *temp = new Sanket(d);
        tail = temp;
        head = temp;
    }

    else {

        Sanket *temp = new Sanket(d);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

void insertAtPosition (Sanket * &tail , Sanket * &head , int position , int d) {

       //insert at Start
    if(position == 1) {
        insertAtHead(tail ,head, d);
        return;
    }

    Sanket* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,head ,d);
        return ;
    }

    //creating a node for d
    Sanket* nodeToInsert = new Sanket(d);

    nodeToInsert ->next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

void print (Sanket *head , Sanket *tail) {
    
    Sanket *temp = head;

    while (temp != NULL) {

        cout << "<- " << temp -> data << " -> " ;
        temp = temp -> next;
    }

    cout << endl << endl;
}


void deleteAtPosition (Sanket * &tail , Sanket * &head , int position) {

    if(position == 1) {
        Sanket* temp = head;
        temp -> next -> prev = NULL;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }

    else {
        
        Sanket* temp = head;
        Sanket* prev = NULL;
        int cnt = 1;

        while (cnt < position - 1) {

            prev = temp;
            temp = temp -> next;
            cnt++;
        }

        if(temp == tail) {
            tail = prev;
        }

        prev -> next = temp -> next;
        temp -> next -> prev = prev;
        temp -> next = NULL;
        temp -> prev = NULL;
        delete temp;
    }
}

int main() { 

    Sanket *head = NULL;
    Sanket *tail = NULL;

// inserting at head or beginning
    insertAtHead(tail , head , 12);
    print(head , tail);
    insertAtHead(tail , head , 11);
    insertAtHead(tail , head , 10);
    print(head , tail);

// inserting at tail or end
    insertAtTail(tail , head , 15);
    print(head , tail);
    insertAtTail(tail , head , 16);
    print(head , tail);


// inserting at position
    insertAtPosition(tail , head , 1 , 9);
    print(head , tail);

    insertAtPosition(tail , head , 1 , 8);
    print(head , tail);   
    insertAtPosition(tail , head , 4 ,120 );
    print(head , tail);   
    insertAtPosition(tail , head , 9 ,100 );
    print(head , tail);   


// deletion operation..

     deleteAtPosition(tail , head , 1);
     print(head , tail);


    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;

    return 0;
}