/* 
    ? Rotate List
    ? https://leetcode.com/problems/rotate-list/description/?envType=problem-list-v2&envId=linked-list
    Given the head of a linked list, rotate the list to the right by k places.

 

    Example 1:


    Input: head = [1,2,3,4,5], k = 2
    Output: [4,5,1,2,3]
    Example 2:


    Input: head = [0,1,2], k = 4
    Output: [2,0,1]
    

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

Node* solve(Node *head, int k) {

        if (!head || !head->next || k == 0) { //(head == NULL || head -> next == NULL || k == 0) {
            return head;
        }

        int length = 1;
        Node* tail = head;
        cout << "tail next : " << tail->next << endl;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // int length = 0;
        // ListNode* tail = head;
        // while (tail != NULL) {
        //     length++;
        //     tail = tail->next;
        // }

        k = k % length;
        if (k == 0) {
            return head;
        }

       Node* curr = head;
        for (int i = 1; i < length - k; i++) {
            curr = curr->next;
        }

       Node* newHead = curr->next;
        curr->next = nullptr;
        tail->next = head;

        return newHead;
}

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {

    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node *fifth = new Node(5);


    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;
    

    print(head);

    cout << "---------------------" << endl;

    int k = 2;

    Node *ans = solve(head, k);
    print(ans);

 return 0;
}