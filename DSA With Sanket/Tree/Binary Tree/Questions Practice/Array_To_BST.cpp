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

Node *solve(vector<int> arr , int start , int end) {

    // base case
    if( start > end) {
        return NULL;
    }    

    int mid = start + (end - start) / 2;

    Node *root = new Node(arr[mid]);

    // left subtree
    root -> left = solve(arr , start , mid - 1);

    // right subtree
    root -> right = solve(arr , mid + 1 , end);

    return root;
}

void print(Node *root) {

    if (root == NULL) {
        return;
    }

    print(root -> left);
    print(root -> right);
    cout << root -> data << " ";
}

int main() {
   
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    Node *ans = solve(arr , 0 , arr.size() - 1);

    print(ans);
    
    return 0;
}