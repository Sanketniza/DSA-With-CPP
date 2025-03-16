/* 
  * lecture 49 :- Merge two sorted linked list
  * link:-https://www.naukri.com/code360/problems/merge-two-sorted-linked-lists_800332?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_Lovebabbar31stJan2021&leftPanelTabValue=PROBLEM

   Problem statement
You are given two sorted linked lists. You have to merge them to produce a combined sorted linked list. You need to return the head of the final linked list.

Note:

The given linked lists may or may not be null.
For example:

If the first list is: 1 -> 4 -> 5 -> NULL and the second list is: 2 -> 3 -> 5 -> NULL

The final list would be: 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> NULL
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= L <= 10^5
1 ≤ data ≤ 10^6 and data != -1

Where L is the number of nodes in either of the two Linked List.

Time Limit: 1 sec 
Follow-up:

Try to solve this problem in linear time complexity and constant space complexity.
Sample Input 1:
7 8 -1
1 3 4 6 -1
Sample Output 1:
1 3 4 6 7 8 -1
Explanation of Input 1:
In this testcase, the first list is: 7 -> 8 -> NULL
The second list is: 1 -> 3 -> 4 -> 6 -> NULL
The final list would be: 1 -> 3 -> 4 -> 6 -> 7 -> 8 -> NULL
Sample Input 2:
5 -1
1 3 6 10 -1
Sample Output 2
1 3 5 6 10 -1
 */

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;

        if (temp != NULL) {
            cout << "-> ";
        } else {
            cout << " NULL";
        }
    }
    cout << endl;
}

Node* merge(Node* head1, Node* head2) {


    // base case
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node* mergedHead = NULL;

    // recursive case

    if (head1 -> data <= head2 -> data) {
        mergedHead = head1;
        mergedHead -> next = merge( head1 -> next, head2);
    } 

    else {
        mergedHead = head2;
        mergedHead -> next = merge(head1, head2 -> next);
    }

    return mergedHead;
}

int main() {
    
    Node *head1 = new Node(1);
    Node *temp1 = new Node(3);
    Node *temp2 = new Node(5);
    Node *temp3 = new Node(17);
    head1->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = NULL;

    Node *head2 = new Node(2);
    Node *temp7 = new Node(4);
    Node *temp8 = new Node(6);
    Node *temp9 = new Node(8);
    Node *temp10 = new Node(10);
    Node *temp11 = new Node(12);
    Node *temp12 = new Node(14);
    head2->next = temp7;
    temp7->next = temp8;
    temp8->next = temp9;
    temp9->next = temp10;
    temp10->next = temp11;
    temp11->next = temp12;
    temp12->next = NULL;

    print(head1);
    cout << "------------------------------" << endl;
    print(head2);
    cout << "------------------------------" << endl;

    Node *head = merge(head1, head2);
    print(head);

    return 0;
}