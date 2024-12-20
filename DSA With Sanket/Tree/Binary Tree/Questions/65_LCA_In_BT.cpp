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

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *lca(Node *root, int n1, int n2)
{
    // Base case
    if (root == NULL)
    {
        return NULL;
    }

    // If either n1 or n2 matches with root's data
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    // Look for keys in left and right subtrees
    Node *leftLCA = lca(root->left, n1, n2);
    Node *rightLCA = lca(root->right, n1, n2);

    // If both left and right returned non-NULL, root is the LCA
    if (leftLCA && rightLCA)
    {
        return root;
    }

    // Otherwise return the non-NULL value
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->left->left = new Node(76);
    root->right->right = new Node(7);
    root->right->right->right = new Node(17);

    int n1 = 5;  // value of root->left->right
    int n2 = 4;  // value of root->right->left

    Node* lcaNode = lca(root, n1, n2);

    if(lcaNode != NULL) {
        cout << "LCA of " << n1 << " and " << n2 << " is: " << lcaNode->data << endl;
    } else {
        cout << "LCA not found" << endl;
    }

    return 0;
}