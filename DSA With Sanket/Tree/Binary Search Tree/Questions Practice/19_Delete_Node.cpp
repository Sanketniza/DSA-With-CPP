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

Node *minival(Node *root) {
    Node *temp = root;
    while (temp -> left != NULL) {
        temp = temp -> left;
    }

    return temp;
}

Node *Delete(Node *root , int data) {

    //base case
    if(root == NULL) {
        return NULL;
    }

    // condition number one
    if(root -> data == data) {

        if(root -> left == NULL && root -> right == NULL) {
            delete root;
            return NULL;
        }

        if(root -> left != NULL && root -> right == NULL) {
            Node *temp = root -> left;
            delete root;
            return temp;
        }

        if(root -> left == NULL && root -> right != NULL) {
            Node *temp = root -> right;
            delete root;
            return temp;
        }

        if(root -> left != NULL && root -> right != NULL) {
            int mini =  minival(root -> right) -> data;
            root -> data = mini;
            root -> right = Delete(root -> right , mini);
            return root;
        }
    }

    else if(root -> data < data) {
        root -> right = Delete(root -> right , data);
    }

    else {
        root -> left = Delete(root -> left , data);

    }
}

void Inorder(Node *root) {
    if(root == NULL) {
        return;
    }

    Inorder(root -> left);
    cout << root -> data << " ";
    Inorder(root -> right);
}

int main() {
    Node *root = new Node(4); 
    root -> left = new Node(2); 
    root -> right = new Node(6); 
    root -> left -> left = new Node(1); 
    root -> left -> right = new Node(3); 
    root -> right -> left = new Node(5); 
    root -> right -> right = new Node(7); 
    
    cout << "inorder" << endl;
    Inorder(root); cout << endl;
    
    Delete(root , 4);
    cout << "aft" << endl;
    Inorder(root);



    return 0;
}