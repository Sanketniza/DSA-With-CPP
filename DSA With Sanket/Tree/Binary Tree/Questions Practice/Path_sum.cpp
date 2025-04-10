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

int solve(Node *root , int target) {

    // base case
    if(root == NULL) {
        return false;
    }

    if(root -> left == NULL || root -> right == NULL) {
        return target = root -> data;
    }

    return solve(root -> left , target - root -> data) || solve(root -> right , root -> data);
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

    int target = 23;

   if(solve(root , target)) {
        cout << "yes" << endl;
   }

   else {
        cout << "No" << endl;
   }
    
    return 0;
}