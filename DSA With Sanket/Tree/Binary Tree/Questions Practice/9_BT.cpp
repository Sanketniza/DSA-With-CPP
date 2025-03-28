
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node (int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }

};

Node *CreateNewNode(int data) {
    Node *newNode = new Node(data);
    
}

void print(Node *root) {
    
    if(root == NULL) {
        return;
    }

    cout << root -> data << " ";
    print(root -> left);
    print(root -> right);
}

int main() {

    // Node *root = new Node(1);
    // root -> left = new Node(2);
    // root -> right = new Node(3);
    // root -> left -> left = new Node(4);
    // root -> left -> right = new Node(5);
    // root -> right -> left = new Node(6);
    // root -> right -> right = new Node(7);

    // cout << "Preorder traversal of the binary tree is: ";
    // print(root);

    CreateNewNode(1);
    


 return 0;
}