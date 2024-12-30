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

        cout << val << endl;
    }
};

Node *merge(Node *head1, Node *head2) {

    

    if(head1 == NULL) {
        return head2;
    }

    if(head2 == NULL) {
        return head1;
    }

    Node *MergeHead = NULL;

    if(head1 -> data >= head2 -> data) {
        MergeHead = head1;
        MergeHead -> next = merge(head1 -> next , head2);
    }

    else {
        MergeHead = head2;
        MergeHead -> next = merge(head1 , head2 -> next);
    }

    return MergeHead;
}

void print(Node *head) {
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;

        if (temp == NULL)
        {
            cout << "NULL";
        }
    }
    cout << endl;
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;

    Node *temp1 = new Node(1);
    Node *temp2 = new Node(2);
    Node *temp3 = new Node(3);
    Node *temp4 = new Node(4);
    Node *temp5 = new Node(5);
    Node *temp6 = new Node(16);

    head1 = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;
    temp4->next = temp5;
    temp5->next = temp6;
    temp6->next = NULL;

    Node *temp7 = new Node(7);
    Node *temp8 = new Node(8);
    Node *temp9 = new Node(9);
    Node *temp10 = new Node(10);
    Node *temp11 = new Node(11);
    Node *temp12 = new Node(12);

    head2 = temp7;
    temp7->next = temp8;
    temp8->next = temp9;
    temp9->next = temp10;
    temp10->next = temp11;
    temp11->next = temp12;
    temp12->next = NULL;


    print(head1);
    cout << "------------------------------"<< endl;
    print(head2);

    cout << "------------------------------"<< endl;

   Node *head = merge(head1, head2);
    print(head);



    return 0;
}