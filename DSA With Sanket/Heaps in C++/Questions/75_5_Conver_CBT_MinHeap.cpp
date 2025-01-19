
/* 
    ? Lecture : 75 Convert BST to Min Heap

    Given a binary search tree which is also a complete binary tree. The problem is to convert the given BST into a Min Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied to all the nodes, in the resultant converted Min Heap. 


 */

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

Node *InOrder (Node *root , vector<int> &v) { 

    // base case LNR
    if (root == NULL) 
        return NULL;

    // recursive call

    InOrder(root -> left , v);
    // cout << root -> data << " ";
    v.push_back(root -> data);
    InOrder(root -> right , v);

}

int main() {

    Node *root = new Node (34);
    root->left = new Node(17);
    root->right = new Node(45);
    root->left->left = new Node(13);
    root->left->right = new Node(20);
    root->right->left = new Node(40);
    root->right->right = new Node(50);


    // InOrder Traversal of the given BST

    vector<int> v;

    InOrder(root , v);

    for(auto it : v) {
        cout << it << " ";
    }

    // sort the vector

    for(int i = 0; i < v.size() - 1; i++) {
        for(int j = 0; j < v.size() - i - 1; j++) {
            if(v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                }
                }
        }

        // for(auto it : v) {
        //     cout << it << " ";
        //     }

 return 0;
}