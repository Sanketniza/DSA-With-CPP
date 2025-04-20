
/* 
    ? lecture 70:  LCA of Two Nodes In A BST
    ? https://www.naukri.com/code360/problems/lca-in-a-bst_981280?leftPanelTab=0&leftPanelTabValue=PROBLEM

    Problem statement
    You are given a binary search tree of integers with N nodes. You are also   given references to two nodes 'P' and 'Q' from this BST.



    Your task is to find the lowest common ancestor(LCA) of these two given     nodes.



    The lowest common ancestor for two nodes P and Q is defined as the lowest   node that has both P and Q as descendants (where we allow a node to be a  descendant of itself)



    A binary search tree (BST) is a binary tree data structure which has the    following properties.

    • The left subtree of a node contains only nodes with data less than the    node’s data.
    • The right subtree of a node contains only nodes with data greater than    the node’s data.
    • Both the left and right subtrees must also be binary search trees.


    For example:
    'P' = 1, 'Q' = 3
    tree = 2 1 4 -1 -1 3 -1 -1 -1,

    The BST corresponding will be- 

    Here, we can clearly see that LCA of node 1 and node 3 is 2.
    Detailed explanation ( Input/output format, Notes, Images )
    Sample Input 1 :
    3 5
    2 1 3 -1 -1 -1 5 -1 -1
    Sample Output 1:
    3
    Explanation for Sample 1:
    The BST corresponding will be-

    Here, we can clearly see that LCA of node 3 and node 5 is 3.
    Sample Input 2 :
    1 2
    3 2 -1 1 -1 -1 -1
    Sample Output 2:
    2
    Constraints:
    1 <= 'N' <= 10^5
    1 <= Data <= 10^6

    Time Limit: 1sec

 */

#include<iostream>
using namespace std;

 /* 
    ? Two ways to solve this problem

        * Recursive way
            ^ - Time Complexity = O(n);
            ^ - space Complexity = O(n);

        * Iterative way
            ^ - Time Complexity = O(n);    
            ^ - Time Complexity = O(1);     
 
  */

class  bst {
    public:
        int data;
        bst *left;
        bst *right;

        bst(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

//todo: Recursive way

bst * lcaOfBST(bst *root , int p , int q) {

    if(root == NULL) {
        return NULL;
    }

    if(root -> data > p && root -> data > q) {
        return lcaOfBST(root -> left , p , q );
    }

    if(root -> data < p && root -> data < q) {
        return lcaOfBST (root -> right , p , q);
    }

    return root;

}

//todo: Iterative way
bst * lcaOfBST_Iterative(bst *root , int p , int q) {

    while (root != NULL) {

        if(root -> data > p && root -> data > q) {
             root = lcaOfBST_Iterative(root -> left , p , q );
        }

        else if (root -> data < p && root -> data < q) {
             root = lcaOfBST_Iterative (root -> right , p , q);
        }

        else {
            return root;
        }
    }
}
 

int main() {

    
    bst *root = new bst(15);
    root -> left = new bst(10);
    root -> right = new bst(20);
    root -> left -> left = new bst(8);
    root -> left -> right = new bst(12);
    root -> right -> left = new bst(16);
    root -> right -> right = new bst(25);

    int p = 10;
    int q = 25;

    bst *ans = lcaOfBST(root , p , q);
    cout << "Recursive way: " << ans -> data << endl;

    bst *ans2 = lcaOfBST_Iterative(root , p , q);
    cout << "Iterative way: " << ans2 -> data << endl;

 return 0;
}