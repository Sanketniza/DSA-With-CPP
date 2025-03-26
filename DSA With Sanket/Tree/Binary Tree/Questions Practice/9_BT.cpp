
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Root {
    public:
        int data;
        Root *left;
        Root *right;

        Root(int d) {
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }

};

Root *buildTree(Root *root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new Root(data);

    if(data == -1) {
        return NULL;
    }

    //left side

    cout << "Enter data for inserting in left of : " << data << endl;
    root -> left = buildTree(root -> left);

    //right side

    cout << "Enter data for inserting in right of : " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

void Inorder(Root *root) {
    if(root == NULL) {
        return;
    }

    Inorder(root -> left);
    cout << root -> data << " ";
    Inorder(root -> right);
}

void Preorder(Root *root) {
    if(root == NULL) {
        return;
    }

    cout << root -> data << " ";
    Preorder(root -> left);
    Preorder(root -> right);
}

int main() {

    Root *root = NULL;

    root = buildTree(root);

    Inorder(root);

 return 0;
}