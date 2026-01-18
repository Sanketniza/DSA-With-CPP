
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Node {

    public:
        T data;
        Node* left;
        Node *right;

        Node(T data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

bool isPartialBST(Node<int> *root , int min , int max) {

    if(root == NULL) {
        return true;
    }

    if(root -> data >= min && root -> data <= max) {
        bool left = isPartialBST(root -> left , min , root -> data);
        bool right = isPartialBST(root -> right , root -> data , max);
    }

    else {
        return false;
    }
}

bool solve(Node<int> *root ) {
    return isPartialBST(root , INT_MIN , INT_MAX);
}

int main() {

    Node<int> *root = new Node<int>(10);
    
    root -> left = new Node<int>(5);
    root -> right = new Node<int>(15);
    root -> left -> left = new Node<int>(3);
    root -> left -> right = new Node<int>(7);
    root -> right -> left = new Node<int>(13);

    if(solve(root)) {
        cout << "Yes" << endl;
    }

    else {
        cout << "No" << endl;
    }

    return 0;
}