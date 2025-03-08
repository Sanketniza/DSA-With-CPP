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
    ~Node()
    {

        int val = this->data;

        if (next != NULL)
        {
            delete next;
            next = NULL;
        }

    }
};


Node *reverse (Node *&head , int k) {

    //base case
    if(head == NULL) {
        return NULL;
    }

    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;

    int count = 0;

   // Check if there are at least k nodes left
    Node *temp = head;
        cout << "head->data : " << head->data << endl;
        cout << "temp->data : " << temp->data << endl;

    for (int i = 0; i < k; i++) {
        if (temp == NULL) {
            return head; // Not enough nodes to reverse, return the head as is
        }
        temp = temp->next;
    }

     while(curr != NULL && count < k) {
        
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        count++;
        cout << "head->data - : " << head->data << endl;
    }

    if(forward != NULL) {
        cout << "head->data + : " << head->data << endl;
        head->next = reverse(forward, k);
        cout << "head->data -+ : " << head->data << endl;
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

   Node *newHead = reverse(head, 4);
    print(newHead);

    return 0;
}