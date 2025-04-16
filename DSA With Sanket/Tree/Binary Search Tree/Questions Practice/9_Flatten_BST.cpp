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

Node *flatten(Node *root , vector<int> &v) {
    
    Node *newNode = new Node(v[0]);

    Node *curr = newNode;
    for(int i = 1; i < v.size(); i++) {
        Node *temp = new Node (v[i]);

        curr -> left = NULL;
        curr -> right = temp;
        curr = temp;
    }

    curr -> left = NULL;
    curr -> right = NULL;
    return newNode;
}

void solve(Node *root , vector<int> &v) {
    if(root == NULL) 
        return;

    solve(root -> left , v);
    v.push_back(root -> data);
    solve(root -> right , v);
}

int main() {
    Node *root = new Node(4); 
    root -> left = new Node(2); 
    root -> right = new Node(6); 
    root -> left -> left = new Node(1); 
    root -> left -> right = new Node(3); 
    root -> right -> left = new Node(5); 
    root -> right -> right = new Node(7); 

    vector<int>ans;
    solve(root, ans);

    // Flatten the BST
    Node *flattened = flatten(root , ans);
    

    
    return 0;
}