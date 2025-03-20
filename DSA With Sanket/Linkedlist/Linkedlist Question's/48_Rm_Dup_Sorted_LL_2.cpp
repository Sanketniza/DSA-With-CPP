/* 
    ? Remove Duplicates from Sorted 2
    ? https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/?envType=problem-list-v2&envId=linked-list

    Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

        Example 1:


        Input: head = [1,2,3,3,4,4,5]
        Output: [1,2,5]
        ex: 1 - 2 - 3 - 3 - 4 - 4 - 5
        Output: 1 - 2 - 5

        Example 2:
        Input: head = [1,1,1,2,3]
        Output: [2,3]
        ex: 1 - 1 - 1 - 2 - 3
        Output: 2 - 3
 */

#include<iostream>
#include<bits/stdc++.h>
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

Node *solve(Node *head) {
    
    Node *dummy = new Node(0);
    dummy->next = head;
    Node *prev = dummy;
    Node *curr = head;

    while (curr) { // (curr != NULL)

        if(curr -> next && curr -> data == curr -> next -> data) {
            while (curr -> next && curr -> data == curr -> next -> data) {
                curr = curr -> next;
            }
            prev -> next = curr -> next;
        }

        else {
            prev = prev -> next;
        }

        curr = curr -> next;
    }

    return dummy -> next;
}

void print (Node *head) {

    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {

    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(3);
    Node *fifth = new Node(4);
    Node *sixth = new Node(4);
    Node *seventh = new Node(5);

    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = sixth;
    sixth -> next = seventh;
    seventh -> next = NULL;

    print (head);
    cout << "---" << endl;

    Node *ans = solve(head);
    print (ans);


 return 0;
}

/* 

    You've hit upon a very important point that often causes confusion! Let's clarify how curr->next && curr->val == curr->next->val works:

    Understanding the Expression

    The expression curr->next && curr->val == curr->next->val can be broken down into two parts:

    curr->next:
    curr->next is indeed a pointer (an address).
    However, in C++, a pointer can be implicitly converted to a boolean value.
    If curr->next is NULL (meaning curr is the last node), it converts to false.
    If curr->next is a valid address (meaning curr has a next node), it converts to true.
    Therefore, curr->next acts as a check to ensure that curr is not the last node before proceeding.
    curr->val == curr->next->val:
    This part compares the values stored in the nodes.
    curr->val accesses the val member (the integer value) of the curr node.
    curr->next->val accesses the val member of the next node.
    The == operator compares these two integer values.

 */