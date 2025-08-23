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

Node *MinVal(Node *root) {
    Node *temp = root;
    while(temp -> left != NULL) {
        temp = temp -> left;
    }
    return temp;
}

Node *deleteNode(Node *root , int key) {

    if(root == NULL) {
        return NULL;
    }

    if(root -> data == key) {

        if(root -> left == NULL && root -> right == NULL) {
            delete root;
            return NULL;
        }  

    // 1 child present

        //? if left node is present
            if(root -> left != NULL && root -> right == NULL) {
                Node *temp = root -> left;
                delete root;
                return temp;
            }

        //? if right node is present
            if(root -> left == NULL && root -> right != NULL) {
                Node *temp = root -> right;
                delete root;
                return temp;
            }


    // 2 child present
        if(root -> left != NULL && root -> right != NULL) {
            int mini = MinVal(root -> right) -> data;
            root -> data = mini;
            root -> right = deleteNode(root -> right , mini);
            return root;
        }
    }

    else if(root -> data > key) {
        root -> left = deleteNode(root -> left , key);
    }

    else {
        root -> right = deleteNode(root -> right , key);
    }
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

    root = deleteNode(root , 3);
    
    return 0;
}