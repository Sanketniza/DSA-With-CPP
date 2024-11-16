/* 
    ? lecture 68: Flatten a Binary Tree to Linked List
    ? https://www.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1

            Given the root of a binary tree, flatten the tree into a "Linked list":

    The "linked list" should use the same Node class where the right child pointer points to the next node in the list and the left child pointer is always null.
    The "linked list" should be in the same order as a pre-order traversal of the binary tree.

    Examples:

Input: 
          1
        /   \
       2     5
      / \     \
     3   4     6
Output : 1 2 3 4 5 6 
 
Explanation: After flattening, the tree looks like this - 
     1
      \
       2
        \
         3
          \
           4
            \ 
             5 
              \
               6
Here, left of each node points to NULL and right contains the next node in preorder.The inorder traversal of this flattened tree is 1 2 3 4 5 6.

Input :
        1
       / \
      3   4
         /
        2
         \
          5 
Output : 
1 3 4 2 5 
Explanation : After flattening, the tree looks like this -
     1
      \
       3
        \
         4
          \
           2
            \ 
             5 
Here, left of each node points to NULL and right contains the next node in preorder.The inorder traversal of this flattened tree is 1 3 4 2 5.

 */

// ? approach 1: using recursion
// ? approach 2: using stack
// ^ approach 3: using morris traversal

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

void flatten(Node* root) {

    Node *curr = root;

    while (curr != NULL) {

        if(curr -> left) {

            Node *pred = curr -> left;

            while (pred -> right) {
                pred = pred -> right;
            }

            pred -> right = curr -> right;
            curr -> right = curr -> left;
            curr -> left = NULL;    
        }

        else {
            curr = curr -> right;
        }
    }

}

void printTree(Node *root) {
    if(root == NULL) return;

    cout << root -> data << " ";
    printTree(root -> right);
}

int main() {

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

      flatten(root);
     
    printTree(root);

 return 0;
}