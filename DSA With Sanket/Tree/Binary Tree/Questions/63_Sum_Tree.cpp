/* 
    lecture 63 : Sum Tree
    ?link - https://www.geeksforgeeks.org/problems/sum-tree/1

    Given a Binary Tree. Check whether all of its nodes have the value equal to the sum of their left and right sub-tree.

    Examples:

    Input:

    
 */

#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node (int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }

};

pair<bool , int> isSumTreeFast(Node *root) {

    // base case
    if(root == NULL) {
        pair<bool , int> p = make_pair(true , 0);
        return p;
    }

    if(root -> left == NULL && root -> right == NULL ) {
        pair<bool ,int > p = make_pair(true , root -> data);
        return p;
    }

    // recursive case
    pair<bool ,int > leftAns = isSumTreeFast(root -> left);
    pair<bool ,int > rightAns = isSumTreeFast(root -> right);

    bool isLeftSumTree = leftAns.first; // left subtree is true or false
    bool isRightSumTree = rightAns.first; // right subtree is true or false

    int leftSum = leftAns.second; // sum of left subtree
    int rightSum = rightAns.second; // sum of right subtree

    bool condition = root -> data == leftSum + rightSum; // root data is equal to sum of left and right subtree

    pair<bool , int> ans;
    
    if(isLeftSumTree && isRightSumTree && condition) { // left and right subtree is sum tree and root data is equal to sum of left and right subtree
        ans.first = true; // it is sum tree
        ans.second = root -> data + leftSum + rightSum; // 2 * root -> data
    } else {
        ans.first = false; // it is not sum tree
    }

    return ans;
}

int main() {

    Node *root = new Node(1);
    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right = new Node(3);
    root -> right = new Node(3);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);
    root -> right -> right -> left = new Node(8);
    root -> right -> right -> right = new Node(9);

    if(isSumTreeFast(root).first) {
        cout << "It is a sum tree" << endl;
    } else {
        cout << "It is not a sum tree" << endl;
    }

 return 0;
}