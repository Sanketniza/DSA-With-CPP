#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{ 
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }

};

int solve(Node* root, vector<int> &ans) {
    
    if(root == NULL) {
        return 0;
    }

    ans.push_back(root -> data);
    int right = solve(root -> right, ans);
}

int main() {

     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans;
    solve(root, ans);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }


 return 0;
}