#include<iostream>
#include<map>
using namespace std;

class  Node{
    public:
    int data;
    Node* next;

    Node(int d) {
        this -> data = d;
        this -> next = NULL;
    }

};

Node * detectLoop(Node *head) {

    // base case
    if(head == NULL) {
        return NULL;
    }

    Node *temp = head;
    map<Node *, bool> visited;
    Node *prev = NULL;

    while(temp != NULL) {

        if(visited[temp] == true) {
            // cout << "Loop is present at " << prev -> data << endl;
            return prev;
        }

        visited[temp] = true;
        prev = temp;
        temp = temp -> next;
    }

    return NULL;

}

void removeLoop(Node *&head) {

    if(head == NULL) {
        return;
    }

    Node *statOfLoop = detectLoop(head);
    // cout << "Starting node of the loop is " << statOfLoop -> data << endl;

    Node *temp = statOfLoop;

    while(temp -> next != statOfLoop) {
        temp = temp -> next;
    }

    temp -> next = NULL;

   
}

bool detectLoopp(Node *head) {

    // base case
    if(head == NULL) {
        return NULL;
    }

    Node *temp = head;
    map<Node *, bool> visited;
    Node *prev = NULL;

    while(temp != NULL) {

        if(visited[temp] == true) {
            cout << "Loop is present at " << prev -> data << endl;
            return prev;
        }

        visited[temp] = true;
        prev = temp;
        temp = temp -> next;
    }

    return NULL;
}

int main() {

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
    // sixth->next = NULL; // No a loop

    if(detectLoopp(head)) {
        cout << "Loop is present" << endl;
        
    } else {
        cout << "Loop is not present" << endl;
    }

    removeLoop(head);

    cout << "After removing loop ---------- " << endl;

    if(detectLoopp(head)) {
        cout << "Loop is present" << endl;
        
    } else {
        cout << "Loop is not present" << endl;
    }

 return 0;
}