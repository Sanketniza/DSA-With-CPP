#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:

    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data) {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }

};

TreeNode *createTree(TreeNode *root) {

        int data;
        cout << "Enter the data: " << endl;
        cin >> data;
        root = new TreeNode(data);

        if(data == -1) {
            return NULL;
        }

        cout << "Enter the left child of " << data << endl;
        root -> left = createTree(root -> left);

        cout << "Enter the right child of " << data << endl;
        root -> right = createTree(root -> right);

        return root;
}

int countLeafNodes(TreeNode *root) {

    if(root == NULL) {
        return 0;
    }

    if(root -> left == NULL && root -> right == NULL) {
        return 1;
    }

    else {
        return countLeafNodes(root -> left) + countLeafNodes(root -> right);
    }
    
       
}


void print(TreeNode *root) {
    
    if(root == NULL) {
        return;
    }

    cout << root -> data << " ";
    print(root -> left);
    print(root -> right);
}

int main() {

    TreeNode *root = NULL;
    root = createTree(root);
    print(root);

    countLeafNodes(root);

 return 0;
}