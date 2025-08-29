#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

Node *minValue(Node *root) {

    Node *temp = root;

    while (temp -> left != NULL) {
        temp = temp -> left;
    }

    return temp;
}

Node *maxValue(Node *root) {

    Node *temp = root;

    while (temp -> right != NULL) {
        temp = temp -> right;
    }

    return temp;
}

int main() {
    
    Node *root = new Node(1);
    
    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> left -> right -> left = new Node(8);
    root -> left -> right -> right = new Node(9);
    
    root -> right = new Node(3);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    cout << minValue(root) -> data << endl;
    cout << maxValue(root) -> data << endl;
    
    return 0;
}