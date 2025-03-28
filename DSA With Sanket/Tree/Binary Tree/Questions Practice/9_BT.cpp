
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

Node *CreateNewNode(Node *root) {

    int data;
    cout << "Enter the data: " << endl;
    cin >> data;
    root = new Node(data);

    if(data == -1) {
        return NULL;
    }

    cout << "Enter the left child of " << data << endl;
    root -> left = CreateNewNode(root -> left);

    cout << "Enter the right child of " << data << endl;
    root -> right = CreateNewNode(root -> right);

    return root;
    
}

void prevorder(Node *root) {
    
    if(root == NULL) {
        return;
    }

    cout << root -> data << " ";
    prevorder(root -> left);
    prevorder(root -> right);
}

void inorder(Node *root) {

    // base case
    if(root == NULL) {
        return;
    }

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void postorder(Node *root) {

    // base case
    if(root == NULL) {
        return;
    }

    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
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

    Node *root = NULL;
    root = CreateNewNode(root);

    cout << "Preorder traversal of the binary tree is: ";
    prevorder(root);

    cout << endl;

    cout << "Inorder traversal of the binary tree is: ";
    inorder(root);

    cout << endl;

    cout << "Postorder traversal of the binary tree is: ";
    postorder(root);


    


 return 0;
}