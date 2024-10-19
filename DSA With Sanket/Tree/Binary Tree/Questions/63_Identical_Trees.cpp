/* 
    lecture 63 : Identical Trees
    ?link - https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

    Given two binary trees, the task is to find if both of them are identical or not.
Note: You need to return true or false, the printing is done by the driver code.

Examples:

Input:
     1          1
   /   \      /   \
  2     3    2     3
Output: Yes
Explanation: 
There are two trees both having 3 nodes and 2 edges, both trees are identical having the root as 1, left child of 1 is 2 and right child of 1 is 3.
Input:
    1       1
  /  \     /  \
 2    3   3    2
Output: No
Explanation: There are tw

 */

#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node *left;
    node *right;

    node(int data) {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
    

};

bool isIdentical(node *r1 , node *r2) {

    // base case
    if(r1 == NULL && r2 == NULL) {
        return true;
    }

    if(r1 == NULL && r2 != NULL) {
        return false;
    }

    if(r1 != NULL && r2 == NULL) {
        return false;
    }

    bool left = isIdentical(r1 -> left , r2 -> left);
    bool right = isIdentical(r1 -> right , r2 -> right);

    bool value = r1 -> data == r2 -> data;
    
    
    if(left && right && value) {
        return true;
    } else {
        return false;
    }
    
}

int main() {

    node *root1 = new node(1);
    root1 -> left = new node(2);
    root1 -> left -> left = new node(4);
    root1 -> left -> right = new node(5);
    root1 -> right = new node(3);
    root1 -> right -> left = new node(6);
    root1 -> right -> left -> left = new node(8);
    root1 -> right -> left -> right = new node(9);
    root1 -> right -> right = new node(7);


    node *root2 = new node(1);
    root2 -> left = new node(2);
    root2 -> left -> left = new node(4);
    root2 -> left -> right = new node(5);
    root2 -> right = new node(3);
    root2 -> right -> left = new node(6);
    root2 -> right -> left -> left = new node(8);
    root2 -> right -> left -> right = new node(9);
    root2 -> right -> right = new node(7);


    if(isIdentical(root1 , root2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

 return 0;
}