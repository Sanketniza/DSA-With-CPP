
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

Node *sort(Node *head) {

    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    Node *temp = head;

    while (temp != NULL) {

        if(temp -> data == 0) {
            count0++;
        }

        else if(temp -> data == 1) {
            count1++;        
        }

        else {
            count2++;
        }

        temp = temp -> next;
    }

    temp = head;

    while (temp != NULL) {

        if(count0 != 0) {
            temp -> data = 0;
            count0--;
        }

        else if(count1 != 0) {
            temp -> data = 1;
            count1--;
        }

        else {
            temp -> data = 2;
            count2--;
        }

        temp = temp -> next;
    }

    return head;
}

void print(Node *head) {

    // Node *temp = head;

    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;

            if(head == NULL) {
                cout << "NULL" << endl;
            }
    }
}

int main()
{
    Node *head = new Node(1);
    Node *temp1 = new Node(0);
    Node *temp2 = new Node(2);
    Node *temp3 = new Node(1);
    Node *temp4 = new Node(0);
    Node *temp5 = new Node(2);

    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;
    temp4->next = temp5;
    temp5->next = NULL;

    print(head);

    sort(head);

    print(head);

    return 0;
}