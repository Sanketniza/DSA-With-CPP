#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

};


class Solution {
public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // Base case: if the node is NULL, return
        if (node == NULL) 
            return;
        
        // Recursively mirror the left and right subtrees
        mirror(node->left);
        mirror(node->right);
        
        // Swap the left and right children
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};



int main() {

    solution sol;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    cout << "Original Tree: ";
    vector<int> original = traversalBT(root);
    for (int val : original) {
        cout << val << " ";
    }

    cout << endl;
    sol.mirror(root);
    cout << "Mirrored Tree: ";
    vector<int> mirrored = traversalBT(root);
    for (int val : mirrored) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}