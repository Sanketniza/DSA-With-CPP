
/* 
    lecture 48 : Remove Duplicates from Sorted Linked List
   todo : Remove Duplicates from Sorted Linked List

   todo : link :- https://www.naukri.com/code360/problems/unique-sorted-list_2420283?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_Lovebabbar29thJan&leftPanelTabValue=PROBLEM

   Problem statement
A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have reference to both the previous and the next nodes in the sequence of nodes.



You are given a sorted doubly linked list of size 'n'.



Remove all the duplicate nodes present in the linked list.



Example :
Input: Linked List: 1 <-> 2 <-> 2 <-> 2 <-> 3

Output: Modified Linked List: 1 <-> 2 <-> 3

Explanation: We will delete the duplicate values ‘2’ present in the linked list.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
5
1 2 2 2 3


Sample Output 1 :
1 2 3


Explanation For Sample Input 1 :
We will delete the duplicate values ‘2’ present in the linked list.


Sample Input 2 :
4
1 2 3 4


Sample Output 2 :
1 2 3 4


Explanation For Sample Input 2 :
The list contains no duplicates, so the final list is unchanged.


Expected time complexity :
The expected time complexity is O('n').


Constraints :
1 <= 'n' <= 10^5
1 <= 'data' in any node <= 10^6

Time limit: 1 sec

 */

#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void removeDuplicates(Node* &head) {

    // Empty LL
    if(head == NULL) {
        return;
    }

    // Non-Empty LL
    Node *curr = head ;

    while (curr != NULL) {

        if ( (curr -> next != NULL) && (curr -> data == curr -> next -> data)) {

            Node *next_next = curr -> next -> next;
            Node *nodeToDelete = curr -> next;
            delete(nodeToDelete);
            curr -> next = next_next;
        }
        else {
            curr = curr -> next;
        }
    }
    // return head;
}

// simple solution
void removeDuplicates2(Node* &head) {

    //base condition
    if(head == NULL) {
        return;
    }

    Node *curr = head;
    Node *prev = NULL;

    while(curr != NULL) {

        if(prev != NULL && prev -> data == curr -> data) {
            Node* nodeToDelete = curr;
            curr = curr -> next;
            prev -> next = curr;
            // delete nodeToDelete;
        }

        else {
            prev = curr;
            curr = curr -> next;
        }
    }

}


void print (Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" <<endl;
}

int main() {

// todo: only for sorted LL

    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(20);
    Node* fourth = new Node(40);
    Node* fifth = new Node(40);
    Node* sixth = new Node(60);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

    print(head);
    
    
    removeDuplicates(head);
    print(head);

    removeDuplicates2(head);
    print(head);




 return 0;
}