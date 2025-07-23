/* 
!  lecture 45 :- Middle Of Linked List

 link :-https://www.naukri.com/code360/problems/middle-of-linked-list_973250?source=youtube&campaign=Lovebabbarcodestudio_24thJan&leftPanelTabValue=PROBLEM
 link :- https://leetcode.com/problems/middle-of-the-linked-list/

             Middle Of Linked List
    
        Problem statement
        Given a singly linked list of 'N' nodes. The objective is to determine the middle node of a singly linked list. However, if the list has an even number of nodes, we return the second middle node.
        
        Detailed explanation ( Input/output format, Notes, Images )
        Sample Input 1 :
        N = 5
        1 2 3 4 5
        Sample Output 1 :
        3 4 5
        Explanation Of Sample Input 1 :
        
        We can clearly see that there are 5 elements in the linked list therefore the middle node is the node with value '3'.
        Sample Input 2 :
        6
        1 2 3 4 5 6
        Sample Output 2 :
        4 5 6
        Explanation Of Sample Input 2 :
        
        We can clearly see that there are 6 elements in the linked list and the middle nodes are  nodes with values 3 and 4 hence we return a second middle node having value '4'.
        Constraints :
        1 <= 'N' <= 10^4
        0 <= 'data' <= 10^3 
        
        Where 'N' is the length of the linked list.
        
        Time Limit: 1 sec
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

int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != 0)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

// first approach
void ans(Node *head , int middle) {

    Node *temp = head;
    int cnt = 0;
    while (cnt < middle) {
        temp = temp ->next;
        cnt++;
    }
    cout << "Middle is :" << temp->data << endl;
}

//* Time complexity is O(N) and space complexity is O(1)
//! same but in one function
void solve(Node *head) {

    cout << "second approach" << endl;

    Node *temp = head;

    int len = 1;

    while(temp != NULL) {
        len++;
        temp = temp -> next;
    }

    temp = head;

    int mid = len / 2;

    int cnt = 1;

    while (cnt < mid) {
        temp = temp -> next;
        cnt++;
    }

    cout << "Middle is : " << temp -> data << endl;
    

    // while(temp != NULL) {
    //     cout << temp -> data << " -> ";
    //     temp = temp -> next;
    // }
    // cout << "NULL" << endl;

    do{
        temp = temp -> next;
        cout << temp -> data << " -> ";
    } while(temp -> next != NULL);
    cout << "NULL" << endl;


}

void print(Node *head , int mid) {

    Node *temp = head;
    int cnt = 0;

    while (cnt < mid)
    {
        temp = temp -> next;
        cnt++;
    }

    while(temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

int main()
{

    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

    cout << endl << endl;

    //* find the middle of the linked list
    int length = getLength(head);
    int middle = length / 2;

    ans(head , middle);

    print(head , middle);

    //--
    solve(head);

    return 0;
}