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

    Node* lca(Node* root ,int n1 ,int n2 )
    {
       // base case 
       if(root == NULL) {
           return NULL;
       }
       
       if(root -> data == n1 || root -> data == n2) {
           return root;
       }
       
       //recursive call
       Node *leftAns = lca(root -> left , n1 , n2);
       Node *rightAns = lca(root -> right , n1 , n2);
       
       if(leftAns != NULL && rightAns != NULL){
           return root;
       }
       
       else if(leftAns != NULL && rightAns == NULL){
           return leftAns;
       }
       
       else if(leftAns == NULL && rightAns != NULL) {
           return rightAns;
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

    Node *n1 = root -> left -> right;
    Node *n2 = root -> right -> left;

    cout << "LCA of 2 and 3 is: " << lca(root, n1 , n2) << endl;

 return 0;
}