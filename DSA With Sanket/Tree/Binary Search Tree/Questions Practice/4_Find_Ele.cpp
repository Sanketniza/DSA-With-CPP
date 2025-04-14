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

bool SearchInBST(Node *root , int x) {

    // base case
    if(root == NULL) return false;

    if(root -> data == x) return true;

    // recursive call
    if(root -> data > x) {
        return SearchInBST(root -> left , x);
    } else {
        return SearchInBST(root -> right , x);
    }
}

int main() {
    Node *root = new Node(4); 
    root -> left = new Node(2); 
    root -> right = new Node(6); 
    root -> left -> left = new Node(1); 
    root -> left -> right = new Node(3); 
    root -> right -> left = new Node(5); 
    root -> right -> right = new Node(7); 

    int x = 15;

    cout << "Element " << x << (SearchInBST(root, x) ? " found in BST." : " not found in BST.") << endl;
    
    return 0;
}