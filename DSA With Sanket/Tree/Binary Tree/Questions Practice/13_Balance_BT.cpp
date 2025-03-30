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

};

pair<bool , int> isBalancedFast(Node *root) {

    // base case
    if(root == NULL) {
        pair<bool , int > p = make_pair(true , 0);
        return p;
    }

    pair <bool ,int> left = isBalancedFast(root -> left);
    pair <bool , int > right = isBalancedFast(root -> right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool , int> ans;
    ans.second = max(left.second , right.second) + 1;

    if(leftAns && rightAns && diff) {
        ans.first = true;
    }

    else {
        ans.first = false;
    }


}

bool isBalanced(Node *root) {

    return isBalancedFast(root).first;
}

int main() {

    Node *root = NULL;

    // creating a tree
    root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    // cout << " hello ans is : " << height(root);

    if(isBalanced) {
        cout << "ans is true " << endl;
    }

    else {
        cout << "ans is false " << endl;
    }

    return 0;


 return 0;
}