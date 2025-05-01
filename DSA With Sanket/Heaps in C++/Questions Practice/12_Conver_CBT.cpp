#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node (int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

void inorder(Node *root, vector<int> &inorderArr) {

    if(root == NULL) return;

    inorder(root -> left, inorderArr);
    inorderArr.push_back(root -> data);
    inorder(root -> right, inorderArr);
}

void preorderFill(Node *root , vector<int> &inorderArr , int &index) {

    if(root == NULL) return;

    root -> data = inorderArr[index];
    index++;
    // root -> data = inorderArr[index++];
    
    preorderFill(root -> left , inorderArr , index);
    preorderFill(root -> right , inorderArr , index);
}


void convertBSTtoMinHeap(Node *root) {

    // step 1
    vector<int> inorderArr;

    inorder(root, inorderArr);

    // step 2
    int index = 0;
    preorderFill(root, inorderArr, index);
}

void print(Node *root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

int main() {

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    print(root);
    cout << endl;

    //step 1
    convertBSTtoMinHeap(root);

    print(root);
    cout << endl;


 return 0;
}