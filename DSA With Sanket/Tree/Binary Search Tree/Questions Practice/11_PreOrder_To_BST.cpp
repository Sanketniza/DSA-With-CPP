#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

Node *solveTree(vector<int> &preorder , int min , int max , int &i) {

    if( i >= preorder.size()) {
        return NULL;
    }

    if(preorder[i] < min || preorder[i] > max) return NULL;

    Node *root = new Node (preorder[i++]);

    root -> left = solveTree(preorder , min , root -> data , i);
    root -> right = solveTree(preorder , root -> data , max , i);

    return root;
}

Node *preorderToBST(vector<int> preorder) {

    int min = INT_MIN;
    int max = INT_MAX;
    int i = 0;

    return solveTree(preorder , min , max , i);
}

void inorderTraversal(Node *root) {

    // Inorder traversal : left , root , right

    // base case 
    if(root == NULL) {
        return;
    }

    inorderTraversal(root -> left);
    cout << root -> data << " ";
    inorderTraversal(root -> right);
}

int main() {
    
    vector<int> preorder = {20, 10, 5, 15, 13, 35, 30, 42};

    Node *ans = preorderToBST(preorder);

    inorderTraversal(ans);
    cout << endl;
    
    return 0;
}