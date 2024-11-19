/* 
    ? lecture 70:  Find K-th smallest Element in BST
    ? https://www.naukri.com/code360/problems/find-k-th-smallest-element-in-bst_1069333?leftPanelTab=0&leftPanelTabValue=PROBLEM

    Problem statement
    You have been given a binary search tree of integers with ‘N’ nodes. You are also given 'KEY' which represents data of a node of this tree.
    
    
    
    Your task is to return the predecessor and successor of the given node in the BST.
    
    
    
    Note:
    1. The predecessor of a node in BST is that node that will be visited just before the given node in the inorder traversal of the tree. If the given node is visited first in the inorder traversal, then its predecessor is NULL.
    
    2. The successor of a node in BST is that node that will be visited immediately after the given node in the inorder traversal of the tree. If the given node is visited last in the inorder traversal, then its successor is NULL.
    
    3. The node for which the predecessor and successor will not always be present. If not present, you can hypothetically assume it's position (Given that it is a BST) and accordingly find out the predecessor and successor.
    
    4. A binary search tree (BST) is a binary tree data structure which has the following properties.
         • The left subtree of a node contains only nodes with data less than the node’s data.
         • The right subtree of a node contains only nodes with data greater than the node’s data.
         • Both the left and right subtrees must also be binary search trees.
    
    
    Detailed explanation ( Input/output format, Notes, Images )
    Sample Input 1:
    15 10 20 8 12 16 25 -1 -1 -1 -1 -1 -1 -1 -1
    10
    Sample output 1:
    8 12

 */

#include<iostream>
using namespace std;

class  bst{
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

pair<int , int> predecessorAndSuccessor(bst *root , int key){

    // key is present in the tree
    bst *temp = root;
    int pred = -1;
    int succ = -1;

    while(temp -> data != key) {

       if(temp -> data > key) {
            succ = temp -> data;
            temp = temp -> left;
        }

        else {
            pred = temp -> data;
            temp = temp -> right;
        }

    }

    bst *leftT = temp -> left;
       while (leftT != NULL) {
            pred = leftT -> data;
            leftT = leftT -> right;
        }

    bst *rightT = temp -> right;
        while (rightT != NULL) {
            succ = rightT -> data;
            rightT = rightT -> left;
        }


    return {pred , succ};
}

int main() {


    bst *root = new bst(15);
    root -> left = new bst(10);
    root -> right = new bst(20);
    root -> left -> left = new bst(8);
    root -> left -> right = new bst(12);
    root -> right -> left = new bst(16);
    root -> right -> right = new bst(25);

    int key = 10;

    pair<int , int> ans = predecessorAndSuccessor(root , key);
    cout << ans.first << " " << ans.second << endl;

 return 0;
}