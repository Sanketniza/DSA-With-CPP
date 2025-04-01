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

bool isIdentical(node *root1 , node *root2) {
    
    if(root1 == NULL && root2 == NULL) {
        return true;
    }

    if(root1 == NULL && root2 != NULL) {
        return false;
    }

    if(root1 != NULL && root2 == NULL) {
        return false;
    }

    bool left = isIdentical(root1 -> left , root2 -> left);
    bool right = isIdentical(root1 -> right , root2 -> right);

    if(root1 -> data == root2 -> data && left && right) {
        return true;
    } else {
        return false;
    }
}

int main() {

     node *root1 = new node(1);
    root1 -> left = new node(2);
    root1 -> left -> left = new node(4);
    root1 -> left -> right = new node(5);
    root1 -> right = new node(3);
    root1 -> right -> left = new node(6);
    root1 -> right -> left -> left = new node(8);
    root1 -> right -> left -> right = new node(9);
    root1 -> right -> right = new node(7);


    node *root2 = new node(1);
    root2 -> left = new node(2);
    root2 -> left -> left = new node(4);
    root2 -> left -> right = new node(5);
    root2 -> right = new node(3);
    root2 -> right -> left = new node(6);
    root2 -> right -> left -> left = new node(8);
    root2 -> right -> left -> right = new node(9);
    root2 -> right -> right = new node(7);
    // root2 -> right -> right -> left = new node(10);
    // root2 -> right -> right -> right = new node(11);


    if(isIdentical(root1 , root2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


 return 0;
}