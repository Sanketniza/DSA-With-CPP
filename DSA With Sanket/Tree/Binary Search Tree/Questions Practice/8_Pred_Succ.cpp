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

pair<int , int> solve(Node *root , int key) {

    if(root == NULL) {
        return {-1 , -1};
    }

    Node *temp = root;
    int pred = -1;
    int succ = -1;

    while (temp -> data != key) {

        if(temp -> data > key) {
            succ = temp -> data;
            temp = temp -> left;
        }

        else {
            pred = temp -> data;
            temp = temp -> right;
        }
    }

    Node *leftT = temp -> left;
    while(leftT != NULL) {
        pred = leftT -> data;
        leftT = leftT -> right;
    }

    Node *rightT = temp -> right;
    while(rightT != NULL) {
        succ = rightT -> data;
        rightT = rightT -> left;
    }

    return {pred , succ};
}

int main() {
    Node *root = new Node(4); 
    root -> left = new Node(2); 
    root -> right = new Node(6); 
    root -> left -> left = new Node(1); 
    root -> left -> right = new Node(3); 
    root -> right -> left = new Node(5); 
    root -> right -> right = new Node(7); 

    int key = 2;

    pair<int , int> ans = solve(root , key);
    cout << "Predecessor: " << ans.first << endl;
    cout << "Successor: " << ans.second << endl;
    
    return 0;
}