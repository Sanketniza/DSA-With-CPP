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

Node* MinVal(Node* root) {
    Node* temp = root;
    while(temp -> left != NULL) {
        temp = temp -> left;
    }
    return temp;
}

Node* deleteNode(Node* root, int key) {

    if(root == NULL ) {
        return NULL;
    }

    if(root -> data == key) {

        // 0 child
        if(root -> left == NULL && root -> right == NULL) {
            delete root;
            return NULL;
        }

        // 1 child present
        //? if left node is present
        if(root -> left != NULL && root -> right == NULL) {
            Node *temp = root -> left;
            delete root;
            return temp;
        }

        // 2 child present

        if(root -> left == NULL && root -> right != NULL) {
            Node *temp = root -> right;
            delete root;
            return temp;
        }

        // 2 child present
        if(root -> left != NULL && root -> right != NULL) {
            Node *temp = MinVal(root -> right);
            root -> data = temp -> data;
            root -> right = deleteNode(root -> right , temp -> data);
            return root;
        }
    }

    else if(root -> data > key) { // left side
        root -> left = deleteNode(root -> left , key);
        // return root;
    }

    else {
        root -> right = deleteNode(root -> right , key);
        // return root;
    }

    return root;
}
   

void inorde(Node *root) {
    // base case 
    if(root == NULL) {
        return;
    }

    // LNR
    inorde(root -> left);
    cout << root -> data << " ";
    inorde(root -> right);
}   

int main() {
    Node *root = new Node(4); 
    root -> left = new Node(2); 
    root -> right = new Node(6); 
    root -> left -> left = new Node(1); 
    root -> left -> right = new Node(3); 
    root -> right -> left = new Node(5); 
    root -> right -> right = new Node(7); 

    cout << "Inorder Traversal before deletion: ";
    inorde(root);
    cout << endl;

    deleteNode(root, 4); // Deleting the root node
    cout << "After deleting the root node, the new root is: " << root->data << endl;
    cout << "Inorder Traversal after deletion: ";

    // Inorder Traversal
    inorde(root);
   
    
    return 0;
}