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

bool isCircular(Node *head ) {

    //* empty list
    if(head == NULL) {
        return true;
    }

    //* non-empty list
    Node *temp = head;
    while(temp->next != NULL) {
        temp = temp -> next;
        if(temp == head) {
            return true;
        }
    }

    return false;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    if(isCircular(head))
    {
        cout << "Yes, it is circular" << endl;
    }
    else
    {
        cout << "No, it is not circular" << endl;
    }
    return 0;
}