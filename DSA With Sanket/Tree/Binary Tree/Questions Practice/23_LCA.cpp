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

Node *lca (Node *root , int n , int m) {

    //     1
    //    / \
    //   2   3
    //  / \ / \
    // 4  5 6  7

    // base case 
    if(root == NULL) {
        return NULL;
    }

    if(root -> data == n || root -> data == m) {
        return root;
    }

    Node *leftAns = lca(root -> left , n , m);
    Node *rightAns = lca(root -> right , n , m);

    //
    if(leftAns && rightAns) {  //  both are not null then return present root data
        return root;
    }

    return (leftAns != NULL) ? leftAns : rightAns;
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int n1 = 5;  // value of root->left->right
    int n2 = 7;  // value of root->right->left

    Node *ans = lca(root , n1 , n2);

    if(ans != NULL) {
        cout << "ansentor is :" << ans -> data;
    }
    else{
        cout << "Not found" << endl;
        
    }
    
    return 0;
}    