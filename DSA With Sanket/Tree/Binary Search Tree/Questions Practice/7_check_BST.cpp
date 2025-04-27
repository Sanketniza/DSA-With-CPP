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

bool isPartialBST(Node* root , int min, int max) {

    if(root == NULL) return true;

    if(root -> data <= min || root -> data >= max) return false;

    return isPartialBST(root -> left , min , root -> data) && isPartialBST(root -> right , root -> data , max);
}

int main() {
    
    Node *root = new Node(4); 
    root -> left = new Node(12); 
    root -> right = new Node(6); 
    root -> left -> left = new Node(1); 
    root -> left -> right = new Node(3); 
    root -> right -> left = new Node(5); 
    root -> right -> right = new Node(7); 

    if(isPartialBST(root , INT_MIN , INT_MAX)) {
        cout << "True" << endl;
    } 
    
    else {
        cout << "False" << endl;
    }
    
    return 0;
}