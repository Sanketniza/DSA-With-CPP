#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *solve (Node *root , int n1 , int n2) {

    // base case
    if(root == NULL) {
        return NULL;
    }

    if(root -> data == n1 || root -> data == n2) {
        return root;
    }

    Node *l = solve(root -> left, n1 , n2);
    Node *r = solve (root -> right , n1 , n2);

    if(l != NULL && r == NULL) {
        return l;
    }

    else if(r != NULL && l == NULL) {
        return r;
    }

    else if (l != NULL && r != NULL) {
        return root;
    }

    else {
        return NULL;
    }
}

int main() {

    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->left->left = new Node(76);
    root->right->right = new Node(7);
    root->right->right->right = new Node(17);

   int n1 = 4;
   int n2 = 5;

   Node *ans = solve(root , n1 , n2);

   cout << ans -> data;

 return 0;
}