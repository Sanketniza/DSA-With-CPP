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

Node *solve(Node *root , int p , int q) {

    // base case
    if(root == NULL) return NULL;

    if(root -> data > p && root -> data > q) {
        return solve(root -> left , p , q);
    }

    if(root -> data < p && root -> data < q) {
        return solve(root -> right , p , q);
    }

    return root;
}

void me(Node *root , int p , int q) {

    while(root != NULL) {

        if(root -> data > p && root -> data > q) {
            me(root -> left , p , q);
        }

        else if(root -> data < p && root -> data < q) {
            me(root -> right , p , q);
        }

        else {
            cout << "LCA is " << root -> data << endl;
            break;
        }
        break;
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

    int p = 6;
    int q = 7;
    Node *ans = solve(root , p , q);
    cout << "LCS is " << ans -> data << endl;

    me(root , p , q);
    
    return 0;
}