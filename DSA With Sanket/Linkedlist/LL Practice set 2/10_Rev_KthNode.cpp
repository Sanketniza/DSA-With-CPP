#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:

    int data;
    Node *next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

};

void print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

}

Node * Reverse(Node *head, int k) {

    if(head == NULL) {
        return head;
    }

    if(k == 0 || k == 1) return head;

    Node *curr = head;
    Node *prev = NULL;
    Node *forward = NULL;

    Node *temp = head;
    for(int i = 0; i < k; i++) {
        if(temp == NULL) {
            return head;
        }
        temp = temp -> next;
    }

    int cnt = 0;

    while(curr != NULL && cnt < k) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }

    cout << "head at : " << head->data << endl;
    cout << "curr at : " << curr->data << endl;
    cout << "forward at : " << forward->data << endl;
    cout << "prev at : " << prev->data << endl;

    if(forward != NULL) {
        head -> next = Reverse(forward, k);
    }

    return prev;

}

int main() {

    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    // fifth->next = head;
    fifth->next = NULL;

    print(head);

    // revese the ll for kth 
    int k = 3;
    Node *ans = Reverse(head, k);

    print(ans);

 return 0;
}