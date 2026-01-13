
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
            Node *left = NULL;
            Node *right = NULL;
        }
};

void InOrder(Node *root) {

    if(root == NULL) {
        return;
    }

    // LNR
    InOrder(root -> left);
    cout << root -> data << " ";
    InOrder(root -> right);
  
}

Node *InsertIntoBST (Node *root , int data) {

    if(root == NULL) {
        root = new Node(data) ;
        return root;
    }

    if(data > root -> data ) {
        // insert the data at right side 
        root -> right = InsertIntoBST(root -> right , data);
    }

    else {
        // insert the data at left side of root (parent node)
        root -> left = InsertIntoBST(root -> left , data);
    }

    return root;
}

void takeInput(Node *&root) {
    
    int data;
    cin >> data;

    while (data != -1) {

        root = InsertIntoBST(root , data);
        cin >> data;
    }
}

int main() {

    Node* root = NULL;

    cout << "Enter the data for the BST: " << endl;

    takeInput(root);

    // inorder travelling...
    cout << "Inorder travelling .. " << endl;
    InOrder(root);
    

    Node *root = new Node(1);
    root -> left = new Node(3);
    root -> right = new Node(34);
    root -> left -> right = new Node(344);
    root -> left -> left = new Node(321);
    
 return 0;
}