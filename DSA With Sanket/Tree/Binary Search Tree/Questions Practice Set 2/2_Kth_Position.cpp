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

void solve(Node *root , int k) {

    static int count = 0; // static variable to keep track of the count of nodes visited
    static int result = -1;

    if(root == NULL) {
        return;
    }

    // Inorder Traversal
    solve(root -> left , k);

    count++;

    if(count == k) {
        result = root -> data;
        cout << "The " << k << "th smallest element in the BST is: " << result << endl;
        return;
    }

    solve(root -> right , k);
}

int main() {
    Node *root = new Node(4); 
    root -> left = new Node(12); 
    root -> right = new Node(6); 
    root -> left -> left = new Node(1); 
    root -> left -> right = new Node(3); 
    root -> right -> left = new Node(5); 
    root -> right -> right = new Node(7); 

    int k = 2;
    solve(root , k);
    
    return 0;
}