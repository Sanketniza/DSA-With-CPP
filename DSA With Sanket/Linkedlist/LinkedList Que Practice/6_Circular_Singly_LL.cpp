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

        ~Node() {

        int value = this -> data;

        if(this -> next != NULL) {
            delete next;
            this -> next = NULL;
        }

        cout << "Memory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        tail->next = head;
    }
    else
    {
        temp->next = head;
        head = temp;
        tail->next = head;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (tail == NULL)
    {
        head = temp;
        tail = temp;
        tail->next = head;
    }
    else
    {
        tail->next = temp;
        tail = temp;
        tail->next = head;
    }
}

void deleteAtHead(Node *&head, Node *&tail) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    if (head == tail) {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    Node* temp = head;
    head = head->next;
    tail->next = head;
    delete temp;
}

void deleteAtTail(Node *&head, Node *&tail) {
    if (tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    if (head == tail) {
        delete tail;
        head = NULL;
        tail = NULL;
        return;
    }

    Node* temp = tail;
    Node* curr = head;
    while (curr->next != tail) {
        curr = curr->next;
    }
    tail = curr;
    tail->next = head;
    delete temp;
}

void deleteAtPosition(Node *&head, Node *&tail, int position) {
    if (position == 1) {
        deleteAtHead(head, tail);
        return;
    }

    Node* curr = head;
    Node* prev = NULL;
    int cnt = 1;

    while (cnt < position && curr != NULL) {
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    if (curr == NULL) {
        cout << "Position out of bounds" << endl;
        return;
    }

    if (curr == tail) {
        deleteAtTail(head, tail);
        return;
    }

    prev->next = curr->next;
    delete curr;
}

void insertAtPosition(Node *&head, Node *&tail, int position, int data) {

    if(position == 1) {
        insertAtHead(head, tail, data);
        return;
    }

    Node *curr = head;
    Node *prev = NULL;

    int cnt = 1;

    while (cnt < position && curr != NULL) {
        prev = curr;
        curr = curr -> next;
        cnt++;
    }

    if(curr == NULL) {
        insertAtTail(head, tail, data);
        return;
    }

    Node *temp = new Node(data);
    temp -> next = curr;
    prev -> next = temp;
}

void print(Node *head)
{
    if (head == NULL)
        return;

    Node *temp = head;
    do
    {
        cout << " " << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 1);
    print(head);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 22);
    insertAtHead(head, tail, 12);
    print(head);

    cout << endl;
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;

//============================================================================================

    insertAtTail(head, tail, 3);
    print(head);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 6);
    print(head);
    cout << endl;
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;

//============================================================================================

    insertAtPosition(head, tail, 1, 9);
    print(head);
    insertAtPosition(head, tail, 5, 8);
    insertAtPosition(head, tail, 3, 128);
    print(head);
    cout << endl;
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;

//============================================================================================
    cout << "deletion is starting" << endl;
    deleteAtHead(head, tail);
    print(head);
    cout << endl;
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;

//============================================================================================

    deleteAtTail(head, tail);
    print(head);

    cout << endl;
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;

//============================================================================================

    deleteAtPosition(head, tail, 3);
    print(head);
    cout << endl;
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;

    return 0;
}