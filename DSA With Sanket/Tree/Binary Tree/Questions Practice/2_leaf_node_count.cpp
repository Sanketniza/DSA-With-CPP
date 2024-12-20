#include<iostream>
using namespace std;

class  Node{

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

void countLeafNodes(Node* root, int &count) {
    // Base case
    if (root == NULL) {
        return;
    }
    
    // If it's a leaf node
    if(root->left == NULL && root->right == NULL) {
        count++;
        return;
    }

    // Recursively count leaf nodes in left and right subtrees
    countLeafNodes(root->left, count);
    countLeafNodes(root->right, count);
}

int main() {

    Node *root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    int count = 0;
    countLeafNodes(root , count);
    cout << "count is :" << count << endl;


 return 0;
}