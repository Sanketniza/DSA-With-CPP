#include <iostream>
#include <map>
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

        cout << "Memory free for node with data : " << val << endl;
    }
};





Node *FloydCycleDetection(Node *head) {
    

    if(head == NULL) {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL) {

        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
        }

        slow = slow->next;

        if(slow == fast) {
            cout << "Loop is present at " << slow->data << endl;
            return slow;
        }

    }

    return NULL;
}

Node *startingNode(Node *head) {

    if(head == NULL) {
        return NULL;
    }

    Node *temp = head;

    Node *meetingPoint = FloydCycleDetection(head);

    while (temp != meetingPoint) {
        temp = temp->next;
        meetingPoint = meetingPoint->next;
    }

    return temp;
}

void removeLoop (Node *&head) {

    if(head == NULL) {
        return;
    }

    Node *start = startingNode(head);

    Node *temp = start;

    while (temp->next != start) {
        temp = temp->next;
    }

    temp->next = NULL;
}

void print(Node *head) {

    Node *temp = head;  

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;

        if(temp == NULL) {
            cout << "NULL";
        }
    }

    cout << endl;
}

bool isVisited(Node *head) {


    if(head == NULL) {
        return false;
    }
    
    Node *temp = head;

    map<Node *, bool> visited;

    while (temp != NULL) {

        if (visited[temp ] == true) {
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);
    Node *sixth = new Node(6);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = second; // Creating a loop

    /* 
       1 -> 2 -> 3 -> 4 -> 5 -> 6
            ^                   !
            |                   !
            |___________________!
     */


    if(isVisited(head)) {
        cout << "Loop is present" << endl;
        removeLoop(head);
        cout << "Loop is removed" << endl;
    } else {
        cout << "Loop is not present" << endl;
    }

    print(head);

    return 0;
}