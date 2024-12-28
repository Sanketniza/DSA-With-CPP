#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
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

        cout << "Memory free for node with data :" << val << endl;
    }
};

int len(Node *head) {
    Node *temp = head;
    int cnt = 0;

    while (temp != NULL) {
        cnt++;
        temp = temp -> next;
    }

    cout << "Length is : " << cnt << endl;

    return cnt;
}

void ans(Node *head, int mid)
{
    Node *temp = head;
    int cnt = 0;

    while (cnt < mid)
    {
        temp = temp->next;
        cnt++;
    }

    cout << "Middle is : " << temp -> data << endl;
}

void print(Node *head , int mid) {

    Node *temp = head;
    int cnt = 0;

    while (cnt < mid)
    {
        temp = temp -> next;
        cnt++;
    }

    while(temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
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

    int length = len(head);
    int mid = length / 2;

    ans(head, mid);

    print(head , mid);


    return 0;
}