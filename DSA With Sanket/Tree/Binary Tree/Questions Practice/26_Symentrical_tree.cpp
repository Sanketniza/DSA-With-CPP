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

bool isSame(Node *p , Node *q) {

    // base case
    if(p == NULL && q == NULL) {
        return true;
    }

    if(p == NULL || q == NULL) {
        return false;
    }

    if(p -> data != q -> data) {
        return false;
    }

    return (p -> data == q -> data) && isSame(p -> left , q -> right) && isSame(p -> right , q -> left);
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

    if(isSame(root -> left, root -> right)) {
        cout << "Both trees are same" << endl;
    } 
    else {
        cout << "Both trees are not same" << endl;
    }
    
    return 0;
}