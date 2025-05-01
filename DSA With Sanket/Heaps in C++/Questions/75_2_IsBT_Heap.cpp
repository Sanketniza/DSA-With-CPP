
/* 
    ? lecture : 75 
    ? Is Binary Tree a Heap?
    ? link : https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1

    You are given a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.

A binary tree is considered a max-heap if it satisfies the following conditions:

Completeness: Every level of the tree, except possibly the last, is completely filled, and all nodes are as far left as possible.
Max-Heap Property: The value of each node is greater than or equal to the values of its children.
Examples:

Input: root[] = [97, 46, 37, 12, 3, 7, 31, 6, 9]
 
Output: true
Explanation: The tree is complete and satisfies the max-heap property.

 */

#include<iostream>
using namespace std;
 
class Node {

    public:

    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
}; 

int NodeCount(Node *root) {

    if(root == NULL) {
        return 0;
    }

    return 1 + NodeCount(root->left) + NodeCount(root->right);
}

bool isBSt(Node *root , int index , int cnt) {

    if(root == NULL) {
        return true;
    }

    if(index > cnt) {
        return false;
    }

    else {
        bool left = isBSt(root -> left , 2 * index + 1 , cnt);
        bool right = isBSt(root -> right , 2 * index + 2 , cnt);

        return left && right;
    }
}

bool isMaxOrder(Node *root) {

    if(root -> left == NULL || root -> right == NULL) {
        return true;
    }

    if(root -> right == NULL) {
        return root -> data > root -> left -> data;
    }

    else {
        bool left = isMaxOrder(root -> left);
        bool right = isMaxOrder(root -> right);

        cout << "left order : " << left << " right order : " << right << endl;

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

    // check if the tree is a heap or not

    int index = 0;
    int cnt = NodeCount(root);
    cout << "count : " << cnt << endl;

    if(isBSt(root, index, cnt) && isMaxOrder(root) ){
        cout << "all set" << endl;
        return true;

    }

    else {
        cout << "not set" << endl;
        return false;
    }

    return 0;
}