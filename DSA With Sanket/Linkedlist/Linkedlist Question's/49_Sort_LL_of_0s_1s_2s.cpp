/* 

 * lecture 49 :- Sort linked list of 0s 1s 2s
 * link:- https://www.naukri.com/code360/problems/sort-linked-list-of-0s-1s-2s_1071937?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_Lovebabbar31stJan2021&leftPanelTabValue=PROBLEM

        Problem statement
    Given a linked list of 'N' nodes, where each node has an integer value that can be 0, 1, or 2. You need to sort the linked list in non-decreasing order and the return the head of the sorted list.
    
    
    
    Example:
    Given linked list is 1 -> 0 -> 2 -> 1 -> 2. 
    The sorted list for the given linked list will be 0 -> 1 -> 1 -> 2 -> 2.
    
    
    Detailed explanation ( Input/output format, Notes, Images )
    Sample Input 1:
    7
    1 0 2 1 0 2 1
    
    
    Sample Output 1:
    0 0 1 1 1 2 2
    
    
    Explanation Of Sample Input 1:
    Input: 1 -> 0 -> 2 -> 1 -> 0 -> 2 -> 1
    
    Output: 0 -> 0 -> 1 -> 1 -> 1 -> 2 -> 2
    
    Explanation: 
    In this example, the original linked list contains two 0s, three 1s, and two 2s. The sorted linked list has all the 0s at the beginning, followed by all the 1s, and finally, all the 2s at the end.
    
    
    Sample Input 2:
    8
    2 1 0 2 1 0 0 2
    
    
    Sample Output 2:
    0 0 0 1 1 2 2 2
    
    
    Follow Up:
    Can you solve this without updating the Nodes of the given linked list?
    
    
    Constraints :
    1 <= N <= 10^3
    0 <= data <= 2 
    
    Where 'N' is the length of the linked list.
    
    Time Limit: 1 sec
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

/* 
    todo: Approach 1:-
    Count the number of 0s, 1s and 2s and then update the linked list
*/

void sort(Node* &head) {

    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    Node* temp = head;

    while (temp != NULL) {

        if (temp->data == 0) {
            count0++;
        }
        else if (temp->data == 1) {
            count1++;
        }
        else {
            count2++;
        }

        temp = temp->next;
    }

    temp = head;

    while (temp != NULL) {
        if(count0 != 0) {
            temp->data = 0;
            count0--;
        }
        else if(count1 != 0) {
            temp->data = 1;
            count1--;
        }
        else {
            temp->data = 2;
            count2--;
        }

        temp = temp->next;
    }
}

/* 
    todo: Approach 2:-
    Create 3 dummy nodes and then update the linked list
*/

void insertAtTail(Node* &tail, int data) {

    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

void dummyNode(Node* &head) {

    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    Node* temp = head;

    while (temp != NULL) {

        if (temp->data == 0) {
            insertAtTail(zeroTail, temp->data);
        }
        else if (temp->data == 1) {
            insertAtTail(oneTail, temp->data);
        }
        else {
            insertAtTail(twoTail, temp->data);
        }

        temp = temp->next;
    }

    if (oneHead->next != NULL) {
        zeroTail->next = oneHead->next;
    }
    else {
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    
    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

}

//********************************************************* */

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;

        if(temp == NULL) {
            cout << "NULL" << endl;
        }
    }
    cout << endl;
}



int main() {



    Node* head = new Node(1);
    Node* second = new Node(0);
    Node* third = new Node(2);
    Node* fourth = new Node(1);
    Node* fifth = new Node(0);
    Node* sixth = new Node(2);
    Node* seventh = new Node(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = NULL;

   print(head);
   cout << "--------------------------------" << endl;

   // todo: first approach
   sort(head);
   print(head);
   cout << "--------------------------------" << endl;

   // todo: second approach

   dummyNode(head);
   print(head);
   cout << "--------------------------------" << endl;

 return 0;
}