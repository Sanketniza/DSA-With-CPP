
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

bool isPalindrom(Node *head) {
    
   
    
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    Node* next = NULL;
    Node* temp = head;
    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    while(slow != NULL) {
        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }
    
    while(prev != NULL) {
        if(prev->data != temp->data) {
            return false;
        }
        prev = prev->next;
        temp = temp->next;
    }
    
    return true; 
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;

        if (temp == NULL)
        {
            cout << "NULL" << endl;
        }
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(10);
    Node *two = new Node(20);
    Node *three = new Node(30);
    Node *four = new Node(30);
    Node *five = new Node(20);
    Node *six = new Node(10);



    head->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = NULL;

    print(head);

    if(isPalindrom(head)) {
        cout << "The linked list is a palindrome." << endl;
    }
    else {
        cout << "The linked list is not a palindrome." << endl;
    }


    return 0;
}