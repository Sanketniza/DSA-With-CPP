#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        node *left;
        node *right;

        node(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

node *buildTree(node *root) {

    // take node data
    cout << "Enter the data : " << endl;
    int data;
    cin >> data;

    if(data == -1 ) {
        return NULL;
    }

    root = new node (data);

    cout << "Enter the data that you want to insert in left side :" << data << endl;
    root -> left = buildTree(root -> left);

    cout << "Enter the data that you want to insert in right side : " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

void print(node *root) {

    if(root == NULL) return;

    cout << root -> data << " : "; 
    print(root -> left);
    print(root -> right);
}

int main() {

    node *root = NULL;
    root = buildTree(root);

    //print the root data

    cout << "Printing the tree : " << endl;
    print(root);


 return 0;
}