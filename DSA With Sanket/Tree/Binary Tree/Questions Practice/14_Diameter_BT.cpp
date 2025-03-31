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

int height(Node *root) {

    // it mejor the height of tree
    // base case


        if(root == NULL) {
            return 0;
        }

        // recursive call
        int left = height (root -> left);
        int right = height (root -> right);

        int ans = max(left , right) + 1;

        return ans;

}

int diameter(Node *root) {

    // base case
    if(root == NULL) {
        return 0;
    }

    // recursive call


    int op1 = diameter(root -> left);
    int op2 = diameter(root -> right);
    int op3 = height(root -> left ) + height(root -> right ) + 1;

    int ans = max(op1 , max(op2 , op3));
    return ans;
}

int main() {

    Node *root = new Node(1);

    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    root -> right = new Node(3);
    root -> right -> left = new Node(6);
    root -> right -> left -> left = new Node(8);
    root -> right -> left -> right = new Node(9);
    root -> right -> right = new Node(7);

    // cout << " hello ans is : " << height(root);

    cout << "Diameter of the tree is : " << diameter(root) << endl;

   
 return 0;
}