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

void mini(Node *root) {
    
    Node *temp = root;

    while (temp -> left != NULL) {
        temp = temp -> left;
    }

    cout << "Minimum value in BST is : " << temp -> data << endl;
}

void maxi(Node *root) {
    
    Node *temp = root;

    while (temp -> right != NULL) {
        temp = temp -> right;
    }

    cout << "Maximum value in BST is : " << temp -> data << endl;
}

int main() {
    Node *root = new Node(4); 
    root -> left = new Node(2); 
    root -> right = new Node(6); 
    root -> left -> left = new Node(1); 
    root -> left -> right = new Node(3); 
    root -> right -> left = new Node(5); 
    root -> right -> right = new Node(7);

    // Minimum value in BST
    mini(root);

    // Maximum value in BST
    maxi(root); 
    
    return 0;
}