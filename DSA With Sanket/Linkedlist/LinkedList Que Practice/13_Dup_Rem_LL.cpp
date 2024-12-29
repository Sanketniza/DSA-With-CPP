
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

    
};
Node *removeDuplicates(Node *head) {
// void removeDuplicates(Node *head) {

    // base case 
    if (head == NULL ) {
        return head;
        // return ;
    }

    Node *curr = head;

    while (curr != NULL) {

        if((curr -> next != NULL)  && (curr -> data == curr -> next -> data) ){

            Node *next_next = curr -> next -> next;
            Node *nodeToDelete = curr -> next;
            delete(nodeToDelete);
            curr -> next = next_next;
        }
        else {
            curr = curr -> next;
        }
    }

    return head;
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
            cout << "-> ";
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

    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;
    temp4->next = temp5;
    temp5->next = temp6;
    temp6->next = NULL;

    print(head);

   Node *head2 = removeDuplicates(head);
    print(head2);

    // removeDuplicates(head);
    // print(head);

    return 0;
}