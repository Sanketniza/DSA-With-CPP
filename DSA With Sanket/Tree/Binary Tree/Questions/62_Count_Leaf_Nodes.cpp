/* 
    ? Count Leaf Nodes
    ? https://www.naukri.com/code360/problems/count-leaf-nodes_893055?source=youtube&campaign=LoveBabbar_Codestudio&leftPanelTabValue=PROBLEM&customSource=studio_nav

    Problem statement
You are given a Binary tree. You have to count and return the number of leaf nodes present in it.

A binary tree is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child

A node is a leaf node if both left and right child nodes of it are NULL.
 */

#include<iostream>
using namespace std;

class node {
    public:
       int data;
       node *left;
       node *right;

       node (int d) {
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }

};

void Inorder (node *root , int &count) {

    // base case
    if(root == NULL) {
        return;
    }

    // left
    Inorder(root -> left , count);

    if(root -> left == NULL && root -> right == NULL) {
        count++;
    }

    // right
    Inorder(root -> right , count);


    //   if (root == NULL) {
    //     return 0;
    // }
    
    // if(root -> left == NULL && root -> right == NULL) {
    //     count++;
    // }

    // // Recursively count leaf Nodes in left and right subtrees
    // int leftLeaves = countLeafNodes(root->left , count);
    // int rightLeaves = countLeafNodes(root->right , count);
    
    // return count;
}

int main() {

    node *root = NULL;

    // creating a tree
    root = new node(1);
    root -> left = new node(2);
    root -> right = new node(3);
    root -> left -> left = new node(4);
    root -> left -> right = new node(5);
    root -> right -> left = new node(6);
    root -> right -> right = new node(7);
    
    int count = 0;
    Inorder(root , count);

    cout << "Count of leaf nodes : " << count << endl;

    return 0;
}