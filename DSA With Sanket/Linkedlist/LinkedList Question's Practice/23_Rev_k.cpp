#include<iostream>
using namespace std;

class  Node{
    public:
    int data;
    Node* next;

    Node(int d) {
        this -> data = d;
        this -> next = NULL;
    }

};

Node*solve(Node *head, int k) {
    
    // base cas
    if(head == NULL) {
        return NULL; 
    }

    // reverse first k nodes
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    int count = 0;

    // check if there are at least k nodes left
    Node *temp = head;
    for(int i = 0; i < k; i++) {
        if(temp == NULL) {
            return head;
        }
        temp = temp -> next;
    }

    while(curr != NULL && count < k) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // reverse remaining nodes
    if(forward != NULL) {
        head -> next = solve(forward, k);
    }

    return prev;
}

void print(Node* head) {

    Node* temp = head;

    while(temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;

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

    // reverse the linked list in k groups
    int k = 4;

    Node *newNode = solve(head, k);
    print(newNode);



 return 0;
}


