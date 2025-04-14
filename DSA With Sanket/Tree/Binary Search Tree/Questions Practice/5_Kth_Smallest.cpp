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

void Inorder(Node* root , vector<int> &ans) {

    // base case
    if(root == NULL) {
        return;
    }

    // recursive call
    Inorder(root -> left , ans);
    Inorder(root -> right , ans);
    ans.push_back(root -> data);
    // return ans;
}

void solve(Node *root , int k) {

    vector<int> inorder; 
    Inorder(root ,  inorder);

    // cout << "Inorder Traversal: ";
    // for(auto i : inorder) {
    //     cout << i << " ";
    // }

    cout << endl;
    sort(inorder.begin() , inorder.end());

    // cout << "The " << k << "th smallest element in the BST is: " << inorder[k - 1] << endl;
    // return inorder[k - 1];                                   
}

void oneMode(Node *root , int k) {

   static int count = 0;
   static int result = -1;

    if(root == NULL) {
        return;
    }

    // Inorder Traversal
    oneMode(root -> left , k);

    count++;

    if(count == k) {
        result = root -> data;
        cout << "The " << k << " th smallest element in the BST is: " << result << endl;
        return;
    }

    oneMode(root -> right , k);

    // return result;
}

int main() {

    Node *root = new Node(4); 
    root -> left = new Node(2); 
    root -> right = new Node(6); 
    root -> left -> left = new Node(1); 
    root -> left -> right = new Node(3); 
    root -> right -> left = new Node(5); 
    root -> right -> right = new Node(7); 

    int k = 3; // Example value for k
    solve(root , k);
    // int ans = solve(root , k);
    // cout << "The " << k << "th smallest element in the BST is: " << ans << endl;
    
    oneMode(root , k);
    return 0;
}