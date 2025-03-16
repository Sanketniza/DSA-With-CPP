#include<iostream>
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

Node* reverse(Node *head) {

    Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;

    while (curr != NULL) {
        
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}



void insert(Node* &head, Node* &tail, int data) {

    Node *temp = new Node(data);

    if(head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail -> next = temp;
        tail = temp;
    }

}

Node *addToNodes(Node *head1, Node *head2) {
    
    Node *ansHead = NULL;
    Node *ansTail = NULL;
    int carry = 0;

    while (head1 != NULL || head2 != NULL || carry != 0) {

        int val1 = 0;
        while (head1 != NULL) {
            val1 = head1 -> data;
        }

        int val2 = 0;
        while (head2 != NULL) {
            val2 = head2 -> data;
        }

        int sum = carry + val1 + val2;
        int digit = sum % 10;

        insert(ansHead, ansTail, digit);

        carry = sum / 10;

        if (head1 != NULL) {
            head1 = head1 -> next;
        }

        if (head2 != NULL) {
            head2 = head2 -> next;
        }

    }

    return ansHead;
}

void print(Node* &head) {

    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" <<endl;
}

int main() {

   Node *head1 = new Node(1);
    Node *second1 = new Node(2);
    Node *third1 = new Node(3);

    head1->next = second1;
    second1->next = third1;
    third1->next = NULL;

    Node *head2 = new Node(4);
    Node *second2 = new Node(5);
    Node *third2 = new Node(6);

    head2->next = second2;
    second2->next = third2;
    third2->next = NULL;

    print(head1);
    cout << endl;
    print(head2);
    cout << "------------------------------" << endl;

    //-----------------Addition of two linked list-------------------

    head1 = reverse(head1);
    head2 = reverse(head2);

    print(head1);
    cout << endl;
    print(head2);   
    cout << "------------------------------" << endl;

    Node *ans = addToNodes(head1, head2);
    // ans = reverse(ans);
    print(ans);

    cout << "------------------------------" << endl;
    

 return 0;
}