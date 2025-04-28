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

int solve(Node *root ) {

    // base case
    if(root == NULL) return 0;

    // left

    if(root -> left == NULL && root -> right == NULL) {
        return 1;
    }

    int left = solve(root -> left);
    // right
    int right =  solve(root -> right);

    return left + right;
}

int main() {
    Node *root = new Node(4); 
    root -> left = new Node(2); 
    root -> right = new Node(6); 
    root -> left -> left = new Node(1); 
    root -> left -> right = new Node(3); 
    root -> right -> left = new Node(5); 
    root -> right -> right = new Node(7); 

    // Count leaf nodes
    int count = solve(root );
    cout << "Leaf nodes count: " << count << endl;
    
    return 0;
}