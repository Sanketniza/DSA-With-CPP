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

pair<bool , int> isSum(Node *root) {

    if(root == NULL) {
        pair<bool , int> p = make_pair(true , 0);
        return p;
    }

    if(root -> left == NULL && root -> right == NULL) {
        pair<bool , int> p = make_pair(true , root -> data);
        return p;
    }

    pair<bool , int> left = isSum(root -> left);
    pair<bool , int> right = isSum(root -> right);

    bool isLeft = left.first;
    bool isRight = right.first;

    int leftSum = left.second;
    int rightSum = right.second;

    int condition = root -> data == leftSum + rightSum;

    pair<bool , int> ans;

    if(isLeft && isRight && condition) {
        ans.first = true;
        ans.second = root -> data + leftSum + rightSum;
    }

    else {
        ans.first = false;
    }
}

int main() {

    // Node *root = new Node(44);
    // root -> left = new Node(2);
    // root -> left -> left = new Node(4);
    // root -> left -> right = new Node(5);
    // root -> right = new Node(3);
    // root -> right -> left = new Node(6);
    // root -> right -> left -> left = new Node(8);
    // root -> right -> left -> right = new Node(9);
    // root -> right -> right = new Node(7);

    Node *root = new Node(3);
    root -> left = new Node(1);
    root -> right = new Node(2);

    if(isSum(root).first) {
        cout << "Yes";
    }
    
     else {
        cout << "No";
    }


 return 0;
}