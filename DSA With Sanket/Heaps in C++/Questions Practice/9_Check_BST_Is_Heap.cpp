#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {

    public:
        int data;
        Node *left;
        Node *right;

        Node (int data) {

            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

int NodeCount(Node *root) {

    if(root == NULL) {
        return 0;
    }

    /* 

        if(root -> left == NULL && root -> right == NULL) {
            return 1;
        }

        int left = NodeCount(root -> left);
        int right = NodeCount(root -> right);

        return 1 + left + right;
     */

    return 1 + NodeCount(root -> left) + NodeCount(root -> right);
}

bool isBST(Node *root , int index , int cnt) {

    // base case
    if(root == NULL) return true;

    if(index > cnt) return false;

    else {
        bool left = isBST(root -> left , 2 * index + 1 , cnt);
        bool right = isBST(root -> right , 2 * index + 2 , cnt);
        return left && right;
    }


}

bool isMaxOrder(Node *root) {

    if(root -> left == NULL || root -> right == NULL) {
        return true;
    }

    if(root -> right == NULL) return root -> data > root -> left -> data;

    else {
        bool left = isMaxOrder(root -> left);
        bool right = isMaxOrder(root -> right);

        return (left && right &&  (
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

    int cnt = NodeCount(root);
    cout << "Node count: " << cnt << endl;

    int index = 0;
    bool isBst = isBST(root, index, cnt);
    bool isMaxOrderr = isMaxOrder(root);

    if(isBst && isMaxOrderr) {
        cout << "The given tree is a BST and a Heap." << endl;
    } else {
        cout << "The given tree is not a BST or a Heap." << endl;
    }


 return 0;
}