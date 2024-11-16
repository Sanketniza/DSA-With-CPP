
#include<iostream>
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

Node *MinValue(Node *root) {
    Node *temp = root;
    while(temp -> left != NULL) {
        temp = temp -> left;
    }
    return temp;
}

Node *MaxValue(Node *root) {
    Node *temp = root;
    while(temp -> right != NULL) {
        temp = temp -> right;
    }
    return temp;
}

int main() {

    Node *root = new Node(4);
    root -> left = new Node(2);
    root -> right = new Node(6);
    root -> left -> left = new Node(1);
    root -> left -> right = new Node(3);
    root -> right -> left = new Node(5);
    root -> right -> right = new Node(7);

    cout << "Minimum value in BST is : " << MinValue(root) -> data << endl;
    cout << "Maximum value in BST is : " << MaxValue(root) -> data << endl;


 return 0;
}