/*
   * Lecture :- 50
   * Link :- https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

   Add Number Linked Lists
Difficulty: MediumAccuracy: 34.52%Submissions: 286K+Points: 4
Given two numbers, num1, and num2, represented by linked lists. The task is to return the head of the linked list representing the sum of these two numbers.

For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

Examples:

Input: num1 = 45 (4->5->null), num2 = 345 (3->4->5->null)
Output:  3->9->0->null

Explanation:
For the given two linked list (4 5) and (3 4 5), after adding the two linked list resultant linked list will be (3 9 0).
Input: num1 = 0063 (0->0->6->3->null), num2 = 07 (0->7->null)
Output: 7->0->null

Explanation:
For the given two linked list (0 0 6 3) and (0 7), after adding the two linked list resultant linked list will be (7 0).
Expected Time Complexity: O(n+m)
Expected Space Complexity: O(max(n,m)) for the resultant list.

Constraints:
1 <= size of both linked lists <= 106
0 <= elements of both linked lists <= 99


 */

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {

        this->data = d;
        this->next = NULL;
    }
};

Node *reverse(Node *head)
{

    Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{

    Node *temp = new Node(data);
    // if the linked list is empty
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }

    // if the linked list is not empty
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

Node *addTwoNumber(Node *head1, Node *head2)
{

    int carry = 0;
    Node *ansHead = NULL;
    Node *ansTail = NULL;

    while (head1 != NULL || head2 != NULL || carry != 0)
    {

        int val1 = 0;
        if (head1 != NULL)
        {
            val1 = head1->data;
        }

        int val2 = 0;
        if (head2 != NULL)
        {
            val2 = head2->data;
        }

        int sum = carry + val1 + val2;

        int digit = sum % 10;

        insertAtHead(ansHead, ansTail, digit);

        carry = sum / 10;

        if (head1 != NULL)
        {
            head1 = head1->next;
        }

        if (head2 != NULL)
        {
            head2 = head2->next;
        }
    }

    return ansHead;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

int main()
{

    Node *head1 = new Node(1);
    Node *second1 = new Node(2);
    Node *third1 = new Node(3);

    head1->next = second1;
    second1->next = third1;
    third1->next = NULL;

    Node *head2 = new Node(4);
    Node *second2 = new Node(5);

    head2->next = second2;
    second2->next = NULL;

    // before revesering the linked list
    cout << "Before revesering the linked list" << endl;
    print(head1);
    cout << endl;
    print(head2);
    cout << endl
         << "------------------" << endl;

    head1 = reverse(head1);
    head2 = reverse(head2);

    // after revesering the linked list
    cout << "After revesering the linked list" << endl;
    print(head1);
    cout << endl;
    print(head2);
    cout << endl
         << "------------------" << endl;

    // add two number
    Node *ans = addTwoNumber(head1, head2);
    ans = reverse(ans);

    // print the result
    cout << "After adding the two number" << endl;
    print(ans);

    return 0;
}