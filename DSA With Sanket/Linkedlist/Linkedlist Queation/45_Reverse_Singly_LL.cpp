
/*
lecture 45 : Reverse a Singly Linked List
? https://www.naukri.com/code360/problems/reverse-the-singly-linked-list_799897?source=youtube&campaign=Lovebabbarcodestudio_24thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio_24thJan

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

#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void reverse(Node *&head, Node *curr, Node *prev)
{

    // base
    if (curr == NULL)
    {
        head = prev;
        return;
    }

    // recusrion call
    Node *forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
}

void print(Node *head)
{

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{

    // create nodes
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(30);
    Node *node4 = new Node(40);
    Node *node5 = new Node(50);

    // link nodes , joining the node to each other
    Node *head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    print(head);
    cout << "head is at :" << head->data << endl
         << endl;

    // reverse the linked list
    cout << "Reversing the linked list" << endl;
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    head = prev;
    print(head);
    cout << "head is at :" << head->data << endl
         << endl;

    //^ reverse the linked list by recusrion
    cout << "Reversing the linked list by recusrion" << endl;
    // Node *prev = NULL;
    // Node *curr = head;
    // Node *forward = NULL;

    reverse(head, curr, prev);
    print(head);
    cout << "head is at :" << head->data << endl
         << endl;

    return 0;
}