/* 
    ? lecture 66 : Binary Tree from Inorder and Postorder
    ? link : https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

    Given inorder and postorder traversals of a binary tree(having n nodes) in the arrays inorder[] and postorder[] respectively. The task is to construct a unique binary tree from these traversals and return its root.
    Driver code will print the preorder traversal of the constructed tree.

    Note: The inorder and postorder traversals contain unique values, and every value present in the postorder traversal is also found in the inorder traversal.

    Examples:

    Input: inorder[] = [4, 8, 2, 5, 1, 6, 3, 7], postorder[] = [8, 4, 5, 2, 6, 7, 3, 1]
    Output: [1, 2, 4, 8, 5, 3, 6, 7]
    Explanation: For the given postorder and inorder traversal of tree the resultant binary tree will be
          1
       /      \
     2        3
   /  \      /  \
  4   5     6    7
   \
    8
    Input: inorder[] = [9, 5, 2, 3, 4], postorder[] = [5, 9, 3, 4, 2]
    Output: [2, 9, 5, 4, 3]
    Explanation: The resultant binary tree will be
           2
        /     \
       9      4
        \     /
         5   3

 */

#include<iostream>
#include<vector>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val) {
            data = val;
            left = NULL;
            right = NULL;
        }
};

int findIndex(vector<int>& inorder, int inStart, int inEnd, int value) {
    for(int i=inStart; i<=inEnd; i++) {
        if(inorder[i] == value) {
            return i;
        }
    }
    return -1;
}

Node* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int& postIndex, int& inorderIndex) {

    // base case
    if(inStart > inEnd || postIndex < 0) {
        return NULL;
    }

    // recursive case
    int curr = postorder[postIndex++];
    Node* root = new Node(curr);
        
    int inorderIndex = findIndex(inorder, inStart, inEnd, curr);

    root->right = buildTreeHelper(inorder, postorder, inorderIndex+1, inEnd, postIndex, inorderIndex);
    root->left = buildTreeHelper(inorder, postorder, inStart, inorderIndex-1, postIndex, inorderIndex);

    return root;
}

Node* buildTree(vector<int>& inorder, vector<int>& postorder) {

    int n = inorder.size();
    int postIndex = n-1;
    int inorderIndex = 0;

    Node *ans = buildTreeHelper(inorder, postorder, 0, n-1, postIndex, inorderIndex);

    return ans;
}

int main() {
    
    vector<int> inorder = {4, 8, 2, 5, 1, 6, 3, 7};
    vector<int> postorder = {8, 4, 5, 2, 6, 7, 3, 1};

    Node* root = buildTree(inorder, postorder);

 return 0;
}