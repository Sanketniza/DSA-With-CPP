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

bool isCircular(Node *head) {

    Node *temp = head;
    if(head == NULL) {
        return false;
    }

    map<Node*, bool> visited;

    while(temp != NULL) {

        if(visited[temp] == true) {
            cout << "Loop found at " << temp->data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

Node *FloydCycleDetection(Node *head) {

    if(head == NULL) {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;


    while (slow != NULL && fast != NULL) {

        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            cout << "Loop found at " << slow->data << endl;
            return slow;
        }
    }
    return NULL;
}

void removeNode(Node *&head) {

    if(head == NULL){
        return;
    }

    Node *point = FloydCycleDetection(head);
    Node *temp = point;

    while (temp -> next != point) {
        temp = temp->next;
    }

    temp->next = NULL;
}

void print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

}

int main() {

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
    sixth->next = second; // Creating a loop

    if(isCircular(head)) {
        cout << "Linked list is circular" << endl;
    }

    else {
        cout << "Linked list is not circular" << endl;
    }

    removeNode(head);
    print(head);



 return 0;
}