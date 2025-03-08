#include <iostream>
using namespace std;

class Node {
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

void reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    // Node *forward

    while (curr != NULL) {
        Node *forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }

    head = prev;

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;

        if(temp == NULL) {
            cout << "NULL" << endl;
        }
    }

}

int main()
{

    Node *head = new Node(10);
    Node *node1 = new Node(20);
    Node *node2 = new Node(30);
    Node *node3 = new Node(40);
    Node *node4 = new Node(50);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    reverse(head);

     

    return 0;
}