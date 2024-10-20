/* 
    lecture 63 : Balanced Tree Check
    ?link - https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1

    Given a binary tree, find if it is height balanced or not.  A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

    Examples:

    Input:
          1
        /
       2
        \
         3 
    Output: 0
    Explanation: The max difference in height of left subtree and right subtree is 2, which is greater than 1. Hence unbalanced
    Input:
           10
         /   \
        20   30 
      /   \
     40   60
    Output: 1
    Explanation: The max difference in height of left subtree and right subtree is 1. Hence balanced. 

    
 */

#include<iostream>
using namespace std;

//! First Approach with Time complexicity O(n * n)
//! Second Approach with Time complexicity O(n)

class node {
    public:
       int data;
       node *left;
       node *right;

       node (int d) {
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }

};

int height(node *root) {

    // base case 
    if(root == NULL) {
        return 0;
    }

    // recursive call
    int left = height(root -> left);
    int right = height(root -> right);

    int ans = max(left , right ) + 1;

    return ans;

}

bool isBalanced(node *root) {

    //base case
    if(root == NULL){
        return 0;
    }

    // recursive call

    bool left = isBalanced(root -> left);
    bool right = isBalanced(root -> right);
    bool diff = abs (height(root -> left) - height(root -> right)) <= 1;

    if(left && right && diff) {
        return true;
    }

    else {
        return false;
    }
}

int main() {

      node *root = NULL;

    // creating a tree
    root = new node(1);
    root -> left = new node(2);
    root -> right = new node(3);
    root -> left -> left = new node(4);
    root -> left -> right = new node(5);
    root -> right -> left = new node(6);
    root -> right -> right = new node(7);

    // cout << " hello ans is : " << height(root);

    if(isBalanced) {
        cout << "ans is true " << endl;
    }

    else {
        cout << "ans is false " << endl;
    }


 return 0;
}