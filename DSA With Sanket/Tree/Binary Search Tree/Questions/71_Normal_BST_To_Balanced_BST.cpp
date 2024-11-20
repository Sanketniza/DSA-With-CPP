
/* 
    ? lecture 71: Normal BST to Balanced BST
    ? https://www.naukri.com/code360/problems/normal-bst-to-balanced-bst_920472?leftPanelTab=0&leftPanelTabValue=PROBLEM

    Problem statement
You have been given a binary search tree of integers with ‘N’ nodes. Your task is to convert it into a balanced BST with the minimum height possible.

A binary search tree (BST) is a binary tree data structure that has the following properties.

• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.
A Balanced BST is defined as a BST, in which the height of two subtrees of every node differs no more than 1.

For Example:

For the given BST:

The modified BST will be:

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
1
10 6 -1 4 -1 -1 -1
Sample output 1:
4 6 10
Explanation of Sample output 1:
The tree can be represented as follows:

After converting this tree to balanced BST. It will look like this:   

The inorder traversal of the modified tree will be 4 6 10. Since the inorder is sorted. Hence, it is a valid BST. 
Sample Input 2:
2 
10 5 -1 -1 -1
20 -1 -1

 */

#include<iostream>
#include<vector>
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

void solveInorder(bst *root , vector<int> &v) {

    if(root == NULL)
        return;

    solveInorder(root -> left , v);
    v.push_back(root -> data);
    solveInorder(root -> right , v);

}

bst *balanceBSTheight(int s , int e , vector<int> &v ) {

    // base case 
    if(s > e ) {
        return NULL;
    }

    int mid = (s + e) /2;

    bst * root = new bst(v[mid]);
    root -> left = balanceBSTheight(s , mid - 1, v);
    root -> right = balanceBSTheight(mid + 1 , e , v);

    return root;
}

bst *balanceBST(bst *root) {

    vector<int> v;
    solveInorder(root , v);
    int n = v.size();

    return balanceBSTheight(0 , n - 1 , v);

}

int main() {

    bst *root = new bst(10);
    root -> left = new bst(6);
    root -> right = new bst(16);
    root -> left -> left = new bst(2);
    root -> left -> right = new bst(8);
    root -> right -> left = new bst(12);
    root -> right -> right = new bst(20);
    // output : 4 , 6 , 10

    bst *ans = balanceBST(root);

    while(ans != NULL) {
        cout << ans -> data << " ";
        ans = ans -> right;
    }




 return 0;
}