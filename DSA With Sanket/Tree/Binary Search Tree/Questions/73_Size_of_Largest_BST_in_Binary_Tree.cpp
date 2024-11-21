

/* 
    ? lecture 73: Size of Largest BST in Binary Tree
    ? https://www.naukri.com/code360/problems/largest-bst-subtree_893103?leftPanelTab=0&leftPanelTabValue=PROBLEM

    Problem statement

    You have been given a Binary Tree of 'N' nodes, where the nodes have integer values. Your task is to return the size of the largest subtree of the binary tree which is also a BST.



    A binary search tree (BST) is a binary tree data structure which has the following properties.
    
    • The left subtree of a node contains only nodes with data less than the node’s data.
    • The right subtree of a node contains only nodes with data greater than the node’s data.
    • Both the left and right subtrees must also be binary search trees.
    
    
    Example:
    Given binary tree:
    
    In the given binary tree, subtree rooted at 2 is a BST and its size is 3.
    Detailed explanation ( Input/output format, Notes, Images )
    Sample Input 1 :
    2 1 3 -1 -1 -1 -1
    Sample Output 1:
    3
    Explanation for Sample 1:
    In the given binary tree, subtree rooted at 2 is a BST and its size is 3.
    
    Sample Input 2 :
    50 -1 20 -1 30 -1 40 -1 50 -1 -1
    Sample Output 2:
    4

 */

#include<iostream>
#include<climits>
using namespace std;

class bst {
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

class info {
     
    // -> creating a class for storing the information of the tree
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};

info solve(bst *root , int &maxSize ) {

    // base case
    if(root == NULL) 
        return {INT_MIN , INT_MAX , true , 0};

    // recursive call

    info left = solve(root -> left , maxSize);
    info right = solve(root -> right , maxSize);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root -> data , right.maxi);
    currNode.mini = min(root -> data , left.mini);

    if(left.isBST && right.isBST && ( root -> data > left.maxi && root -> data < right.mini)) {
        currNode.isBST = true;
    } 

    else {
        currNode.isBST = false;
    }

    // ans update 
    if(currNode.isBST) {
        maxSize = max(maxSize , currNode.size); // Change mazSize to maxSize
    }

    return currNode;
}

int largestBSTSubtree(bst *root) {

   int maxSize = 0;
   info temp = solve (root , maxSize);
   return maxSize;

}

int main() {

    bst *root = new bst(1);
    root -> left = new bst(4);
    root -> right = new bst(3);
    root -> left -> left = new bst(2);
    root -> left -> right = new bst(4);
    root -> right -> left = new bst(2);
    root -> right -> right = new bst(5);
    root -> right -> right -> left = new bst(4);
    root -> right -> right -> right = new bst(6);

    int largestBST = largestBSTSubtree(root);

    cout << "Size of Largest BST in Binary Tree: " << largestBST << endl;

 return 0;
}