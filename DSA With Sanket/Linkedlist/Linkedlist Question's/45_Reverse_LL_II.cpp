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

Node *reverseBetween(Node *head, int left, int right) {
    
     if (!head || left == right) {
            return head;
        }

        Node* dummy = new Node(0);
        dummy->next = head;
        Node* prevLeft = dummy;

        // Find the node before the left position
        for (int i = 1; i < left; i++) {
            prevLeft = prevLeft->next;
        }

        Node* curr = prevLeft->next;
        Node* prev = nullptr;
        Node* next = nullptr;

        // Reverse the sublist
        for (int i = left; i <= right; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Connect the reversed sublist
        prevLeft->next->next = curr;
        prevLeft->next = prev;

        return dummy->next;
}

void print(Node* head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {

    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    print(head);

    Node *ans = reverseBetween(head, 2, 4);
    print(ans);
    
 return 0;
}