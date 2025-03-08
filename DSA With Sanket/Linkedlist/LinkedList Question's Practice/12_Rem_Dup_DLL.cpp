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
    
};

void remove(Node *&head) {

    if (head == NULL)
    {
        return;
    }
    

    Node *curr = head;

    while (curr != NULL) {

        Node *temp = curr->next;
        Node *pre = curr;

        while (temp != NULL) {

            if (curr->data == temp->data) {
                Node *nodeToDelete = temp;
                temp = temp->next;
                pre->next = temp;
                temp -> prev = pre;
                delete(nodeToDelete);
            }

            else {
                pre = temp;
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;

        if (temp != NULL)
        {
            cout << "<=> ";
        }

        else
        {
            cout << " NULL";
        }
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(20);
    Node *temp3 = new Node(30);
    Node *temp4 = new Node(30);
    Node *temp5 = new Node(40);
    Node *temp6 = new Node(40);
    Node *temp7 = new Node(50);

    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    temp2->next = temp3;
    temp3->prev = temp2;
    temp3->next = temp4;
    temp4->prev = temp3;
    temp4->next = temp5;
    temp5->prev = temp4;
    temp5->next = temp6;
    temp6->prev = temp5;
    temp6->next = temp7;
    temp7->prev = temp6;
    temp7->next = NULL;

    print(head);

    remove(head);
    print(head);

    return 0;
    
}