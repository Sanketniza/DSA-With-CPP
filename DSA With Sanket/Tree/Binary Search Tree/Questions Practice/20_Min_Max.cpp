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

Node *max(Node *root) {
    Node* temp = root;

    while(temp -> right != NULL) {
        temp = temp -> right;
    }

    cout << temp -> data;
}

Node *min(Node *root) {

    Node *temp = root;

    while(temp -> left != NULL) {
        temp = temp -> left;
    }

    cout << "min of the root : " << temp -> data ;
}


int main() {
    Node *root = new Node(4); 
    root -> left = new Node(2); 
    root -> right = new Node(6); 
    root -> left -> left = new Node(1); 
    root -> left -> right = new Node(3); 
    root -> right -> left = new Node(5); 
    root -> right -> right = new Node(7); 

    max(root);    
    cout << endl;

    min(root);

    //      10 
    //     /  \
    //    8    15  
    //   / \   /  \
    //  5   9 12   20



    return 0;
}