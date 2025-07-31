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

void print(Node *root) {

    if(root == NULL) return;

    cout << root -> data << " ";
    print(root -> left);
    print(root -> right);
}

void inorderTraversal(Node *root, vector<int> &inorder) {
    
    if(root == NULL) return;

    inorderTraversal(root -> left , inorder);
    inorder.push_back(root -> data);
    inorderTraversal(root -> right , inorder);

}

void preorderFill(Node *root, vector<int> &inorder, int &index) {
    
    if(root == NULL) return;

    root -> data = inorder[index];
    index++;

    preorderFill(root -> left , inorder , index);
    preorderFill(root -> right , inorder , index);
}    

void convertBSTtoMinHeap(Node *root) {
    
    if(root == NULL) return;

    vector<int> inorder;

    // Perform inorder traversal and store the values in a vector
    inorderTraversal(root, inorder);

    // Copy the values from the vector to the nodes
    int index = 0;
    preorderFill(root, inorder, index);
}

int main() {
     // Constructing the Binary Search Tree (BST)
    //          4
    //        /   \
    //       2     6
    //      / \   / \
    //     1   3 5   7
    
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    // Print the preorder traversal of the tree
    cout << "Preorder traversal of the tree: ";
    print(root);

    // Convert the BST to a Min Heap
    convertBSTtoMinHeap(root);

    // Print the preorder traversal of the converted tree
    cout << "\nPreorder traversal of the converted tree: ";
    print(root);
    
    return 0;
}