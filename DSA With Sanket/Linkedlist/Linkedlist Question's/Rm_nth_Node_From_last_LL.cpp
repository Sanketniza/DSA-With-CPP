/* 
    ? Remove Nth Node From End of List
    ? https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=problem-list-v2&envId=linked-list

    Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

    Example 1:


    Input: head = [1,2,3,4,5], n = 2
    Output: [1,2,3,5]
    Example 2:

    Input: head = [1], n = 1
    Output: []
    Example 3:

    Input: head = [1,2], n = 1
    Output: [1]
 
 */

#include<iostream>
using namespace std;

class  Node{
    public:
    int data;
    Node *next;


    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};

void solve(Node *&head, int n){

    // 1. Find the length of the linked list

    int len = 0;
    Node *temp = head;
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }

    // 2. Find the position of the node to be deleted from the start

    int pos = len - n + 1;

    // 3. If the position is 1, then delete the head node

    if(pos == 1){
        Node *temp = head;
        head = head -> next;
        delete temp;
        return;
    }

    //
    if(n == len){
        Node *temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = NULL;
        delete temp;
        return;
    }

    // 4. If the position is not 1, then delete the node at the position

    Node *curr = head;
    Node *prev = NULL;
    int cnt = 1;

    while(cnt < pos){
        prev = curr;
        curr = curr -> next;
        cnt++;
    }

    prev -> next = curr -> next;
    delete curr;

    
}

Node *solve2(Node *head, int n) {

    int len = 0;
    Node *temp = head;
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }

    if(n == len){
        return head -> next;
    }

    if(n > len){
        return head;
    }

    int cnt = len - n;

    Node *curr = head;
    Node *prev = NULL;

    for(int i = 0; i < cnt; i++){
        prev = curr;
        curr = curr -> next;
    }

    prev -> next = curr -> next;
    delete curr;

    return head;
}

void print(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

int main() {

    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);

    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = NULL;
    print(head);
    cout << endl;

    int n = 2;

// solution 1
    solve(head, n);
    print(head);

    //solution 2
    Node *ans = solve2(head, n);
    print(ans);


 return 0;
}