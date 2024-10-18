#include<iostream>
#include<queue>
using namespace std;

class Node   {
    public:
        int data;
        Node *left;
        Node *right;

        Node (int data) {
            this -> data = data;
            this -> left = NULL;
            
        }
};

Node *buildTree(Node *root) {

    cout << "Enter the data : " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of : " << data << endl;
    root -> left = buildTree(root -> left);

    cout << "Enter data for inserting in right of : " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
    

}

void Inorder (Node *root ) {

    // base case

    if(root == NULL) {
        return;
    }

    // LNR

    Inorder (root -> left);
    cout << root -> data << " ";
    Inorder (root -> right);
}

void Preorder (Node *root ) {

    // base case 

    if(root == NULL) {

        return;
    }

    // NLR

    cout << root -> data << " ";
    Preorder (root -> left);
    Preorder (root -> right);
}

void Postorder (Node *root) {

    // base caes
    if(root == NULL) {
        return;
    }

    // LRN

    Postorder (root -> left);
    Postorder (root -> right);
    cout << root -> data << " ";
}


int main() {

    Node *root = NULL;

    root = buildTree(root);

    // levelOrderTraversal(root);

    cout << "Printing the Inorder traversal : " << endl;
    Inorder (root);
    cout << endl;

    cout << "Printing the Preorder traversal : " << endl;
    Preorder (root);
    cout << endl;

    cout << "Printing the Postorder traversal : " << endl;
    Postorder (root);
    cout << endl;
    

 return 0;
}