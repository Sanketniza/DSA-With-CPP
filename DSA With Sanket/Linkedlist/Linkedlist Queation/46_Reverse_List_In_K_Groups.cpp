
/* 
    ~ lecture 46 :- Reverse List In K Groups
    * link :- https://www.naukri.com/code360/problems/reverse-list-in-k-groups_983644?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbar_codestudio_26thjan&leftPanelTabValue=PROBLEM

    Problem statement
You are given a linked list of 'n' nodes and an integer 'k', where 'k' is less than or equal to 'n'.



Your task is to reverse the order of each group of 'k' consecutive nodes, if 'n' is not divisible by 'k', then the last group of nodes should remain unchanged.



For example, if the linked list is 1->2->3->4->5, and 'k' is 3, we have to reverse the first three elements, and leave the last two elements unchanged. Thus, the final linked list being 3->2->1->4->5.



Implement a function that performs this reversal, and returns the head of the modified linked list.



Example:
Input: 'list' = [1, 2, 3, 4], 'k' = 2

Output: 2 1 4 3

Explanation:
We have to reverse the given list 'k' at a time, which is 2 in this case. So we reverse the first 2 elements then the next 2 elements, giving us 2->1->4->3.


Note:
All the node values will be distinct.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
6
5 4 3 7 9 2
4 


Sample Output 1:
7 3 4 5 9 2


Explanation of the Sample Input 1:
For the given test case, we reverse the nodes in groups of four. But for the last 2 elements, we cannot form a group of four, so leave them as they are. The linked list becomes 7->3->4->5->9->2. Hence the output is 7 3 4 5 9 2


Sample Input 2:
4
4 3 2 8
4 


Sample Output 2:
8 2 3 4


Expected Time Complexity:
Try to solve this in O(n). 


Expected Space Complexity:
Try to solve this using O(1) extra space.    


Constraints:
1 <= n <= 10^4
1 <= k <= n

Time Limit: 1 sec
*/


#include<iostream>
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

Node *reverseKGroup(Node *head, int k) {
    if(head == NULL) {
        return NULL;
    }

    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    int count = 0;

    while(curr != NULL && count < k) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if(forward != NULL) {
        head->next = reverseKGroup(forward, k);
    }

    return prev;
}



void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {

    //* create a linked list
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);
    Node *sixth = new Node(6);

    head->next = second;    
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    print(head);

    //* reverse the linked list in k groups
    // int k = 2;
    int k = 3;
    cout << "After reversing the linked list in k groups of " << k << " :" << endl;
    Node *newHead = reverseKGroup(head, k);
    print(newHead);

 return 0;
}