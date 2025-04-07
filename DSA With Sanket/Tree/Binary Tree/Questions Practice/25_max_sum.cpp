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

void solve(Node *root , int len , int mlen , int &sum , int &msum) {

    if(root == NULL) {

        if( len > mlen ) {
            mlen = len;
            msum = sum;
        }

        else if(len == mlen) {
            msum = max(sum , msum);
        }

        return;
    }

    sum += root -> data;

    solve(root -> left , len + 1 , mlen , sum , msum);
    solve(root -> right , len + 1 , mlen , sum , msum);
}

int done(Node *root) {

    int len = 0;
    int mlen = 0;

    int sum = 0;
    int msum = INT_MIN;

    solve(root ,len , mlen , sum , msum);
    return msum;
}

int main() {
    Node *root = new Node(1);
    
    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    // root -> left -> right -> left = new Node(8);
    // root -> left -> right -> right = new Node(9);
    
    root -> right = new Node(3);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    int ans = done(root);
    cout << "ans is : " << ans << endl;
    
    return 0;
}