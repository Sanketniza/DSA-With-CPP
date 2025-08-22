#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        
        Node(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }

        void addNode(int data) {

            if(data < this -> data) {
                // here this is the root node

                if(this -> left == NULL) {
                    this -> left = new Node(data);
                }
                else {
                    this -> left -> addNode(data);
                }
            }

            else {
                if(this -> right == NULL) {
                    this -> right = new Node(data);
                }
                else {
                    this -> right -> addNode(data);
                }
            }
        }
};

void printTree(Node *root) {

    if(root == NULL) {
        return;
    }

    cout << root -> data << " ";
    printTree(root -> left);
    printTree(root -> right);
}

int main() {

    Node *root = new Node(12);
    root -> addNode(10);
    root -> addNode(15);
    root -> addNode(11);
    root -> addNode(13);
    root -> addNode(14);
    root -> addNode(16);
    root -> addNode(17);

    printTree(root);


 return 0;
}