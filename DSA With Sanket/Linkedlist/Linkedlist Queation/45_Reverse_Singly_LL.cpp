#include<iostream>
using namespace std;


/* 

    Problem statement
    ^ Given a singly linked list of integers. Your task is to return the head of the reversed linked list.
    ^ 
    ^ For example:
    ^ The given linked list is 1 -> 2 -> 3 -> 4-> NULL. Then the reverse linked list is 4 -> 3 -> 2 -> 1 -> NULL and the head of the reversed linked list will be 4.
    ^ Follow Up :
    ^ Can you solve this problem in O(N) time and O(1) space complexity?
    ^ Detailed explanation ( Input/output format, Notes, Images )
    ^ Constraints :
    ^ 1 <= T <= 5
    ^ 0 <= L <= 10^5
    ^ 1 <= data <= 10^9 and data != -1
    ^ 
    ^ Time Limit: 1 sec
    ^ Sample Input 1 :
    ^ 1
    ^ 1 2 3 4 5 6 -1
    ^ Sample Output 1 :
    ^ 6 5 4 3 2 1 -1
    ^ Explanation For Sample Input 1 :
    ^ For the first test case,  After changing the next pointer of each node to the previous node, The given linked list is reversed.
    ^ Sample Input 2 :
    ^ 1
    ^ 10 21 3 2 4 -1
    ^ Sample Output 2 :
    ^ 4 2 3 21 10 -1
 */
 
class Node{
    
    public:
        int data;
        Node* next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }

}; 

void insertAtHead(Node *&tail,Node *&head ,int data) {

    if(head == NULL) {  //^  if list is empty . no any before node is present
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else {    //^  if list is not empty . mean at least one node is present
        Node *temp = new Node(data);
        temp -> next = head;
        head = temp;
    }
}

void insertAtTail(Node *&tail,Node *&head ,int d) {

      if ( tail == NULL)  // empty list , no any before node is present
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }

    else {  // if list is not empty . mean at least one node is present
        Node *temp = new Node(d);
        tail -> next = temp;
        tail = temp;
    }
}


void insertAtPosition(Node* &tail, Node *&head , int d , int position) {

    if(position == 1) {
        insertAtHead(tail , head , d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1){
        temp = temp -> next;
        cnt++;
    }

    if(temp -> next == NULL) {
        insertAtTail(tail , head , d);
        return;
    }

    Node *nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next; 
    temp -> next = nodeToInsert;
}



int reverse(Node *&head) {

    Node *curr = head;
    Node *prev = NULL;
    Node *forword = NULL;

      while (curr != NULL) {
            forword = curr -> next;
            curr -> next = prev;
            prev = curr ;
            curr = forword;
        }
        
        return prev -> data;
}

void print(Node *head) {
    Node *temp = head;
    
    while (temp != NULL) {
        cout << temp -> data << " -> " ;
        temp = temp -> next ;
    }

    cout << endl;

    // cout << "hello";
}

int main() { 

    // Node *node1 = new Node(10);
    // Node *head = node1;  // empty list
    // Node *tail = NULL;  // empty list


    Node *head = NULL;  // empty list
    Node *tail = NULL;  // empty list

    insertAtHead(tail ,head , 10);
    insertAtHead(tail ,head , 9);
    insertAtHead(tail ,head , 8);
    print(head);

    insertAtPosition(tail , head , 103 , 3);
    insertAtPosition(tail , head , 23 , 1);
    insertAtPosition(tail , head , 100 , 6);
    print(head);


     reverse(head);
    print(head);



   cout << "head is at :" << head -> data << endl;
   cout << "tail is at :" << tail -> data << endl;

    return 0;
}