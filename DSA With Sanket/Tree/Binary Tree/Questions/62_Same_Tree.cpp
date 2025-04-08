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

bool isSame(Node *p , Node *q) {

    // base case
    if(p == NULL && q == NULL) {
        return true;
    }

    if(p == NULL || q == NULL) {
        return false;
    }

    if(p -> data != q -> data) {
        return false;
    }

    return isSame(p -> left, q -> left) && isSame(p -> right, q -> right);

}

int main() {
    Node *root = new Node(1);
    root -> left = new Node(2);
    // root -> right = new Node(3);

    Node *root2 = new Node(1);
    // root2 -> left = new Node(2);
    root2 -> right = new Node(2);

    if(isSame(root, root2)) {
        cout << "Both trees are same" << endl;
    } 
    
    else {
        cout << "Both trees are not same" << endl;
    }
    
    return 0;
}