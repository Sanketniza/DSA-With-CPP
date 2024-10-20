/* 
    ? leetcode 545. Boundary of Binary Tree
    ? lecture 64 : Tree Boundary Traversal
    ? link : https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

    Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:

Input:
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3

 */

#include<iostream>
#include<vector>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node(int d) {
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }

};

void LeftSideTraversal (Node *root , vector<int> &ans) {

    // base case
    if(root == NULL || ( root -> left == NULL && root -> right == NULL)) {
        return;
    }

    ans.push_back(root -> data);

    // recursive call
    if(root -> left) {
        LeftSideTraversal(root -> left, ans);
    }

    else {
        LeftSideTraversal(root -> right, ans);
    }

}

void LeafNodeTraversal (Node *root , vector<int> &ans) {

    // base case
    if(root == NULL) {
        return;
    }

    if(root -> left == NULL && root -> right == NULL) {
        ans.push_back(root -> data);
        return;
    }

    // recursive call
    
    LeafNodeTraversal(root -> left, ans);
    LeafNodeTraversal(root -> right, ans);
    
}

void RightSideTraversal (Node *root , vector<int> &ans) {

    //base case

    if(root == NULL || ( root -> left == NULL && root -> right == NULL)) {
        return;
    }

    // recursive call
    if(root -> right) {
        RightSideTraversal(root -> right, ans);
    }

    else {
        RightSideTraversal(root -> left, ans);
    }

}

vector<int> boundary(Node *root) {

    vector<int> ans;

    if(root == NULL) {
        return ans;
    }

    ans.push_back(root -> data);

    // left boundary
    LeftSideTraversal(root -> left, ans);

    // leaf node
    LeafNodeTraversal(root -> left, ans);
    LeafNodeTraversal(root -> right, ans);

    // right boundary
    RightSideTraversal(root -> right, ans);

    return ans;
}

int main() {

    Node *root = new Node(1);
    
    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> left -> right -> left = new Node(8);
    root -> left -> right -> right = new Node(9);

    root -> right = new Node(3);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    // create vector
    
     vector<int> ans = boundary(root);

     for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
     }



 return 0;
}