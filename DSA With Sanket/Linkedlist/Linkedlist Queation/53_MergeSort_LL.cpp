/* 
   * lecture 53
   * Merge Sort in LL
   * link: https://www.naukri.com/code360/problems/mergesort-linked-list_630514?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_CodestudioLovebabbar5thfeb&leftPanelTabValue=PROBLEM
   
   Problem statement
For a given Singly Linked List of integers, sort the list using the 'Merge Sort' algorithm.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= N <= 10^5
1 <= DATA <= 10^9

Where 'DATA' denotes the value of node of Linked List.

Time Limit: 1sec
Sample Input 1 :
1 4 5 2 -1
Sample Output 1 :
1 2 4 5
Sample Input 2 :
10 9 8 7 6 5 4 -1
Sample Output 2 :
4 5 6 7 8 9 10

 */

#include<iostream>
using namespace std;

class Node  {
    public:
     int data;
     Node *next;

        Node(int data){
           this->data = data;
           this->next = NULL;
        }

};

Node *findMiddle(Node *head) {

    Node *slow = head;
    Node *fast = head -> next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node *merge(Node *left, Node *right) {

    if(left == NULL){
        return right;
    }

    if(right == NULL){
        return left;
    }

    Node *ans = new Node(-1);
    Node *temp = ans;

    // merge two sorted linked list

    while(left != NULL && right != NULL) {

        if (left -> data < right -> data) {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }

        else {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }

    while (left != NULL) {
        temp -> next = left;
        temp = left;
        left = left -> next;
    }

    while (right != NULL) {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    
    return ans->next;
}

Node *MergeSort(Node *head){

    // base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    // step 1. Find the middle of the linked list
    Node *middle = findMiddle(head);

    // step 2. Sort the left half and right half
    Node *left = head;
    Node *right = middle->next;
    middle->next = NULL;

    // step 3. Recursively sort the left and right halves
    left = MergeSort(left);
    right = MergeSort(right);
    
    // step 4. Merge the two sorted halves
    Node *result = merge(left, right);

    return result;
    
}

void print(Node *head){

    Node *temp = head;

    while(temp != NULL){

        cout<< temp -> data << " -> ";
        temp = temp -> next;
    }

    cout << "NULL"<< endl;
}

int main() {



    Node *head = new Node(1);
    Node *second = new Node(4);
    Node *third = new Node(5);
    Node *fourth = new Node(2);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    cout << "Before sorting: " << endl;
    print(head);
    cout << endl << "----------------------------------" << endl;

        /* 
            ? 1. Find the middle of the linked list
            ? 2. Sort the left half
            ? 3. Sort the right half
            ? 4. Merge the two sorted halves
         */

    // step 1. Find the middle of the linked list

    Node *middle = findMiddle(head);
    cout << "Middle: " << middle -> data << endl;

    MergeSort(head);

    cout << "After sorting: " << endl;
    print(head);

    cout << endl << "----------------------------------" << endl;
    
 return 0;
 
}