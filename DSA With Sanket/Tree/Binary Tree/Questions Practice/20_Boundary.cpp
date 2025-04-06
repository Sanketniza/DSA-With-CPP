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

void LeafNodeTraversal(Node *root , vector<int> &ans) {

    // base case
    if(root == NULL) {
        return;
    }

    // push the root node to the ans vector
    if(root -> left == NULL && root -> right == NULL) {
        ans.push_back(root -> data);
        return;
    }

    // recursive call
    LeafNodeTraversal(root -> left, ans);
    LeafNodeTraversal(root -> right, ans);

}

void leftSideTraversal(Node *root , vector<int> &ans) {

    //base case
    if(root == NULL || ( root -> left == NULL && root -> right == NULL)) {
        return;
    }

    // push the root node to the ans vector
    ans.push_back(root -> data);

    // recursive call
    if(root -> left) {
        leftSideTraversal(root -> left, ans);
    }

    else {
        leftSideTraversal(root -> right, ans);
    }

}

void rightSideTraversal(Node *root , vector<int> &ans) {

    // base case
    if(root == NULL || ( root -> left == NULL && root -> right == NULL)) {
        return;
    }

    ans.push_back(root -> data);

    // recursive call

    if(root -> right) {
        rightSideTraversal(root -> right, ans);
    }

    else {
        rightSideTraversal(root -> left, ans);
    }

}

vector<int> solve (Node *root ) {

    // create ans vector to store the boundary
    vector<int> ans;

    if(root == NULL) {
        return ans;
    }

    ans.push_back(root -> data);

    // left boundary
    leftSideTraversal(root -> left, ans);

    // leaf node
    LeafNodeTraversal(root -> left, ans);
    LeafNodeTraversal(root -> right, ans);

    //right boundary
    rightSideTraversal(root -> right, ans);


    return ans;
}

int main() {

    Node *root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    vector<int> ans = solve(root);

    for(auto i : ans) {
        cout << i << " ";
    }

    cout << endl;
    
    return 0;
}