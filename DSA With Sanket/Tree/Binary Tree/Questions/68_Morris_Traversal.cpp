/* 
    ? lecture 68
    ? Morris Traversal

    ? inorder traversal without using recursion and stack
    ? O(1) space complexity
    ? O(n) time complexity

    Given a Binary Tree, the task is to print its Inorder Traversal, without using recursion or stack.

Examples:

Input:


Iterative-Postorder-Traversal
Output: 4 2 5 1 3
Explanation: Inorder traversal (Left->Root->Right) of the tree is 4 2 5 1 3


Input:


Iterative-Postorder-Traversal-2
Output: 1 7 10 8 6 10 5 6
Explanation: Inorder traversal (Left->Root->Right) of the tree is 1 7 10 8 6 10 5 6
 */
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

// Function for inorder traversal 
// using Morris Traversal
vector<int> inOrder(Node* root) {
    vector<int> result;
    Node* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
          
            // If no left child, visit this node 
            // and go right
            result.push_back(curr->data);
            curr = curr->right;
        }
        else {
          
            // Find the inorder predecessor of curr
            Node* prev = curr->left;
            while (prev->right != nullptr &&
                                 prev->right != curr) {
                prev = prev->right;
            }

            // Make curr the right child of its 
            // inorder predecessor
            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            } 
            else {
              
                // Revert the changes made in 
                // the tree structure
                prev->right = nullptr;
                result.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return result;
}


int main() {
  
    // Representation of input binary tree:
    //           1
    //          / \
    //         2   3
    //            / \  
    //           4   5


    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    vector<int> result = inOrder(root);
  
     for (int data : result) {
        cout << data << " ";
    }
    
    return 0;
}