/*
 *  lecture 53 : Flatten a Linked List
 *  link -https://www.naukri.com/code360/problems/flatten-a-linked-list_1112655?source=youtube&campaign=YouTube_CodestudioLovebabbar5thfeb

   Problem statement
You are given a linked list containing 'n' 'head' nodes, where every node in the linked list contains two pointers:



(1) ‘next’ which points to the next node in the list

(2) ‘child’ pointer to a linked list where the current node is the head.



Each of these child linked lists is in sorted order and connected by 'child' pointer.



Your task is to flatten this linked such that all nodes appear in a single layer or level in a 'sorted order'.



Example:
Input: Given linked list is:

Output:
1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 → 9 → 12 → 20 → null.
 */

#include <iostream>
using namespace std;

// Definition for linked list node
class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};

Node *mergeTwoList(Node *first, Node *second)
{

       // Base cases: if one list is empty, return the other
    if (first == NULL) {
      return second;
    }
    if ( second == NULL ) {
      return first;
    }

    // Choose the smaller head as the new head
    Node *result;

    if (first->data <= second->data) {
        result = first;
        result->child = mergeTwoList(first->child, second);
    }

    else {
        result = second;
        result->child = mergeTwoList(first, second->child);
    }

    // Set next to NULL as we're flattening the list
    result->next = NULL;
    return result;
}

Node *flattenLinkedList(Node *head)
{

    if (!head || !head->next)
    {
        return head;
    }

    // recurse for list on right
    head->next = flattenLinkedList(head->next);

    // merge two list
    head = mergeTwoList(head, head->next);

    return head;
}

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp -> data << " -> ";
        temp = temp -> child;  // Change this line from temp = temp->next to temp = temp->child
    }
    cout << "NULL" << endl;
}

int main()
{

    Node *one = new Node(1);
    Node *two = new Node(4);
    Node *three = new Node(7);
    Node *four = new Node(9);
    Node *five = new Node(11);

    Node *head = one;

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = NULL;

    Node *six = new Node(2);
    Node *seven = new Node(3);

    one->child = six;
    six->next = seven;

    Node *eight = new Node(5);
    Node *nine = new Node(6);

    two->child = eight;
    eight->next = nine;

    Node *ten = new Node(8);
    three->child = ten;

    Node *eleven = new Node(10);
    four->child = eleven;

    // flattenLinkedList
    Node* ans = flattenLinkedList(head);

    print(ans);

    return 0;
}