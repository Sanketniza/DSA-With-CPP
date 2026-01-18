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

bool solve(Node *root , int x) {

    //  x = 12
    //                 10 <- root 
    //                /  \
    //       root -> 8    15 <- root  
    //              / \   /  \
    //     root -> 5   9 12   20

    if(root == NULL) return false;

    if(root -> data == x) return true;

    if(root -> data > x){
        return solve(root -> left , x);
    }
    else {
        return solve(root -> right , x);

    }
}

int main() {
    Node *root = new Node(4); 
    root -> left = new Node(2); 
    root -> right = new Node(6); 
    root -> left -> left = new Node(1); 
    root -> left -> right = new Node(3); 
    root -> right -> left = new Node(5); 
    root -> right -> right = new Node(7); 

    int x = 2;

    if(solve(root , x)) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    //   12
    //                 10 
    //                /  \
    //               8    15  
    //              / \   /  \
    //             5   9 12   20



    
    return 0;
}