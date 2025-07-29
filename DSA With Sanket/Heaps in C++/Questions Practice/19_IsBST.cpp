#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node (int val) {
        this -> data = val;
        this -> left = NULL;
        this -> right = NULL;
    }

};

void print(Node *root) {

    if(root == NULL) {
        cout << "Tree is empty" << endl;
        return;
    }

    print(root -> left);
    cout << root -> data << " ";
    print(root -> right);
}

int NodeCount(Node *root) {

    if(root == NULL) {
        return 0;
    }

    return 1 + NodeCount(root -> left) + NodeCount(root -> right);
}

bool isBST(Node *root , int index , int cnt) {

    if(root == NULL) {
        return true;
    }

    if(index > cnt) return false;

    else {
        bool left = isBST(root -> left , 2 * index + 1 , cnt);
        bool right = isBST(root -> right , 2 * index + 2 , cnt);

        return left && right;
    }

}

bool isMaxOrder(Node *root) {

    if(root -> left == NULL && root -> right == NULL) return true;

    if(root -> left == NULL) {
        return root -> data > root -> right -> data;
    }

    else if(root -> right == NULL) {
        return root -> data > root -> left -> data;
    }

    else {
        bool left = isMaxOrder(root -> left);
        bool right = isMaxOrder(root -> right);

        return (left && right && (
            root -> data > root -> left -> data && root -> data > root -> right -> data
        ));
    }
}

int main() {

    Node* root = new Node(90);
    root->left = new Node(80);
    root->right = new Node(60);
    root->left->left = new Node(40);
    root->left->right = new Node(30);
    root->right->left = new Node(20);
    root->right->right = new Node(10);

    // print(root);

    // check if the tree is a heap or not

    // count the node
    int index = 0;
    int cnt = NodeCount(root);
    cout << "count : " << cnt << endl;

    if(isBST(root , index , cnt) && isMaxOrder(root) ){
        cout << "all set" << endl;
        // return true;
    }

    else {
        cout << "not set" << endl;
        // return false;
    }


 return 0;
}