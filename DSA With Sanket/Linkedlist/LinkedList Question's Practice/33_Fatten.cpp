#include<iostream>
using namespace std;

class Node {
    public:

    int data;
    Node *next;
    Node *child;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }

};

Node *mergeTwoList(Node *first, Node *second) {
    
    if(first == NULL) {
        return second;
    }

    if(second == NULL) {
        return first;
    }

    Node *ans;

    if(first -> data <= second -> data) {
        ans = first;
        ans -> child = mergeTwoList(first -> child, second);
    } 
    
    else {
        ans = second;
        ans -> child = mergeTwoList(first, second -> child);
    }

    ans -> next = NULL;

    return ans;
}

Node *solve(Node *head) {
    
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node *right = solve(head->next);

    Node *ans = mergeTwoList(head, right);

    return ans;
}

void print(Node *head) {

    Node *temp = head;

    while(temp != NULL) {

        cout << temp -> data << " -> ";
        temp = temp -> child;
    }

    cout << "NULL" << endl;
}

int main() {

    Node *one = new Node(1);
    Node *two = new Node(4);
    Node *three = new Node(7);
    Node *four = new Node(9);
    Node *five = new Node(11);

    Node *head = one;

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = NULL;

    Node *six = new Node(2);
    Node *seven = new Node(3);

    one->child = six;
    six->child = seven;

    Node *eight = new Node(5);
    Node *nine = new Node(6);

    two->child = eight;
    eight->child = nine;

    Node *ten = new Node(8);
    three->child = ten;

    Node *eleven = new Node(10);
    four->child = eleven;

    Node *ans = solve(head);

    print(ans);


 return 0;
}