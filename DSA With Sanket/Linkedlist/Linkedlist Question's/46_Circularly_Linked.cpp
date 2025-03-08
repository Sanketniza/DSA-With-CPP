/*

 ? https://www.geeksforgeeks.org/problems/circular-linked-list/1
 ? https://leetcode.com/problems/linked-list-cycle/description/
 ? https://www.naukri.com/code360/problems/detect-the-first-node-of-the-loop_1112628?source=youtube&campaign=Lovebabbarcodestudio_24thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio_24thJan&count=25&page=1&search=linked%20list%20is%20circular%20or%20not&sort_entity=order&sort_order=ASC&attempt_status=NOT_ATTEMPTED&leftPanelTabValue=PROBLEM&customSource=studio_nav

    Circular Linked List:
        - Last node is pointing to first node.
        - First node is pointing to last node.
        - Circularly Linked List is a type of linked list where the last node of the list points to the first node, creating a circular structure.
        - Circular linked lists can be singly or doubly linked.
        - Circular linked lists are useful for implementing data structures like circular buffers and for tasks requiring cyclic traversal.
        - The circular

         nature of circular linked lists allows for efficient traversal in both directions and can simplify certain algorithms.

   ! lecture 46: check linked list is circular or not
   You are given the head of a linked list containing integers, You need to find out whether the given linked list is circular or not.

Note :

1. A linked list is said to be circular if it has no node having its next pointer equal to NULL and all the nodes form a circle i.e. the next pointer of last node points to the first node.
2. An empty linked will also be considered as circular.
3. All the integers in the linked list are unique.
4. In the input, the next pointer of a node with i’th integer is linked to the node with data (i+1)’th integer (If (i+1)’th node exists). If there is no such (i+1)’th integer then the next pointer of such node is set to NULL.

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

bool isCircular(Node *head)
{

    //* empty list
    if (head == NULL)
    {
        return true;
    }

    //* non-empty list
    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        return true;
    }

    return false;
}

int main()
{

    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = head;
    // fifth->next = NULL;

    if (isCircular(head))
    {
        cout << "Linked list is circular" << endl;
    }
    else
    {
        cout << "Linked list is not circular" << endl;
    }

    return 0;
}