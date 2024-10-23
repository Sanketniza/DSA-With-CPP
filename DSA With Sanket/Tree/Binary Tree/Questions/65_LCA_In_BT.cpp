/* 
   ? Lowest Common Ancestor in Binary Tree
   ? https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

   Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.

   LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

    Example 1:

    Input:
    n1 = 2 , n2 = 3  
       1 
      / \ 
     2   3
    Output: 1
    Explanation:
    LCA of 2 and 3 is 1.

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

Node* lca(Node* root, int n1, int n2) {

    if(root == NULL) {
        return NULL;
    }

    if(root -> data == n1 || root -> data == n2) {
        return root;
    }

    Node* left = lca(root->left, n1, n2);
    Node* right = lca(root->right, n1, n2);

    if(left != NULL && right != NULL) {
        return root;
    }

    else if(left != NULL && right != NULL) {
        return right;
    }

    else if(left == NULL && right != NULL   ) {
        return left;
    }


    else {
        return NULL;
    }

}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->left->left = new Node(76);
    root->right->right = new Node(7);
    root->right->right->right = new Node(17);

    cout << "LCA of 2 and 3 is: " << lca(root, 2, 3) << endl;

 return 0;
}