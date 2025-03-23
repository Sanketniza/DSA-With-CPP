/* 
    ? Swap Nodes in Pairs
    ? https://leetcode.com/problems/swap-nodes-in-pairs/description/?envType=problem-list-v2&envId=linked-list

    Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

    Example 1:

    Input: head = [1,2,3,4]

    Output: [2,1,4,3]

    Explanation:



    Example 2:

    Input: head = []

    Output: []

    Example 3:

    Input: head = [1]

    Output: [1]

    Example 4:

    Input: head = [1,2,3]

    Output: [2,1,3]

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

void print(Node* head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {

    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;    
    fourth->next = fifth;
    fifth->next = NULL;

    print(head);

    //* ------------------solution-------------------

    Node* dummy = new Node(0);
    dummy->next = head;

    Node* prev = dummy;
    Node* curr = head;

    while(curr != NULL && curr->next != NULL) {
        Node* first = curr;
        printf("first: %d\n", first->data);
        cout << "first:"; print(first);

        Node* second = curr->next;
        printf("first: %d\n", second->data);
        cout << "second:"; print(second);

        prev->next = second;
        first->next = second->next;
        second->next = first;

        printf("+first: %d\n", first->data);
        cout << "-> first:"; print(first);

        printf("+first: %d\n", second->data);
        cout << "-> second:"; print(second);

        prev = first;
        curr = first->next;
    }

    curr = dummy->next;
    
    print(curr);


 return 0;
}