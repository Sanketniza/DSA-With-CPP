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

int solve(Node *root) {

    // base case
    if(root == NULL) return 0;

    // recursive case
    int left = solve(root -> left);
    int right = solve(root -> right);

    return max(left , right) + 1;
}

int main() {
    Node *root = new Node(1);
    
    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> left -> right -> left = new Node(8);
    root -> left -> right -> right = new Node(9);
    
    root -> right = new Node(3);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    int ans = solve(root);
    cout << "Answer is : " << ans << endl;
    
    return 0;
}
