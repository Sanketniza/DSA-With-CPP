#include<iostream>
using namespace std;

class node {

    public:
        int data;
        node *left;
        node *right;

        node(int d) { // constructor
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }

};

node *buildTree(node *root) {  // here I return node to the int main function , that why node * i written 

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);


    // base case
    if(data == -1) {
        return NULL;
    }

    // recursive case
    cout << "Enter data for inserting in left of : " << data << endl;
    root -> left = buildTree(root -> left);

    cout << "Enter data for inserting in right of : " << data << endl;
    root -> right = buildTree(root -> right);
    
    return root;
}

int main() {

    // node *root = new node(1);

    node *root = NULL;
    root = buildTree(root);

 return 0;
}