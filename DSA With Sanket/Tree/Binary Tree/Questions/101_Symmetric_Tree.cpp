#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Helper function to check if two subtrees are mirrors of each other
    bool isMirror(TreeNode* left, TreeNode* right) {
        // If both nodes are NULL, they are mirrors
        if (left == NULL && right == NULL) {
            return true;
        }
        
        // If only one node is NULL, they are not mirrors
        if (left == NULL || right == NULL) {
            return false;
        }
        
        // Check if:
        // 1. The values of the nodes are the same
        // 2. The left subtree of left is a mirror of the right subtree of right
        // 3. The right subtree of left is a mirror of the left subtree of right
        return (left->val == right->val) && 
               isMirror(left->left, right->right) && 
               isMirror(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        // Empty tree is symmetric
        if (root == NULL) {
            return true;
        }
        
        // Check if the left and right subtrees are mirrors of each other
        return isMirror(root->left, root->right);
    }
};

// For testing
int main() {
    // Example 1: [1,2,2,3,4,4,3]
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(3);
    
    Solution sol;
    if (sol.isSymmetric(root1)) {
        cout << "Example 1 is symmetric" << endl;
    } else {
        cout << "Example 1 is not symmetric" << endl;
    }
    
    // Example 2: [1,2,2,null,3,null,3]
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->right = new TreeNode(3);
    root2->right->right = new TreeNode(3);
    
    if (sol.isSymmetric(root2)) {
        cout << "Example 2 is symmetric" << endl;
    } else {
        cout << "Example 2 is not symmetric" << endl;
    }
    
    // Clean up memory
    // (In a real application, you would need to properly delete all nodes)
    
    return 0;
}