
/* 

    ? leacture : 62 -> Height of binary tree
    ? link : https://www.geeksforgeeks.org/problems/height-of-binary-tree/1

    Given a binary tree, find its height.

        example 1:

        nput:
            1
           /  \
          2    3
        Output: 2
 */

#include<iostream>
using namespace std;

class  Node {
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

int height (Node *root) {

    // base case 
    if (root == NULL) {
        return 0;
    }

    // recursive case

        int leftHeight = height(root -> left);
        int rightHeight = height(root -> right);

        int ans = max(leftHeight , rightHeight) + 1;
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
    root -> right -> right -> left = new Node(10);
    root -> right -> right -> right = new Node(11);

    cout << "Height of the binary tree is: " << height(root) << endl;


 return 0;
}