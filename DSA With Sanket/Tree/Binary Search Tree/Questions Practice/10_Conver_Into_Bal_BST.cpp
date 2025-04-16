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

void solveInorder(Node* root, vector<int>& ans) {
    if (root == NULL) return;

    solveInorder(root->left, ans);
    ans.push_back(root->data);
    solveInorder(root->right, ans);
}

Node* balanceBSTheight(int start , int end , vector<int> ans) {

    // base case
    if(start > end) {
        return NULL;
    }

    int mid = start + (end - start) / 2;
    // int mid = (start + end) / 2; // This is also valid but can cause overflow

    Node *root = new Node(ans[mid]);
    root -> left = balanceBSTheight(start , mid - 1 , ans);
    root -> right = balanceBSTheight(mid + 1 , end , ans);

    return root;
}

Node *balanceBST(Node* root) {

    // Step 1: Store the inorder traversal of the BST in a vector
    vector<int> ans;
    solveInorder(root, ans);

    // Step 2: Construct a balanced BST from the sorted array
    int n = ans.size();
    return balanceBSTheight(0 , n - 1, ans);

}

void print(Node *root) {

    Node *temp = root;

    if(temp == NULL) {
        return;
    }

    print(temp -> left);
    cout << temp -> data << " ";
    print(temp -> right);
}

int main() {
    Node *root = new Node(4); 
    root -> left = new Node(2); 
    root -> right = new Node(6); 
    root -> left -> left = new Node(1); 
    root -> left -> right = new Node(3); 
    root -> right -> left = new Node(5); 
    root -> right -> right = new Node(7); 

    Node *balancedRoot = balanceBST(root);
    // You can add code here to print or verify the balanced BST

    cout << "Inorder Traversal of Balanced BST: ";
    print(balancedRoot);
    cout << endl;
    
    return 0;
}