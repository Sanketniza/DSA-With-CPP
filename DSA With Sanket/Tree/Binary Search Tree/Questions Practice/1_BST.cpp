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

Node * CreateBst(Node* root , int data) {
    
   if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data < root -> data) {
        root -> left = CreateBst(root -> left , data);
    } else {
        root -> right = CreateBst(root -> right , data);
    }

    return root;

}



void intputBST(Node* root) {

    int data;
    cout << "Enter a data for binary search tree : " << endl;
    cin >> data;

    while (data != -1) {
        root = CreateBst(root , data);
        cin >> data;
    }

    
}

void inOrder(Node * root) {
    if(root == NULL) {
        return;
    }

    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}

int main() {

    // creating an empty Node
    Node* root = NULL;

    intputBST(root);

    cout << "Inorder Traversal of BST is : " << endl;
    inOrder(root);
    cout << endl;
    
    
    return 0;
}