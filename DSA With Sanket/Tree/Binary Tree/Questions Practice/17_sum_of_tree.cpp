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

    ans.first = isLeft && isRight && condition;
    ans.second = root -> data + leftSum + rightSum;

    return ans;
}

int main() {

    Node *root = new Node(44);
    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right = new Node(3);

    pair<bool , int> ans = isSum(root);

    if(ans.first) {
        cout << "It is a sum tree" << endl;
    }
    else {
        cout << "It is not a sum tree" << endl;
    }


 return 0;
}