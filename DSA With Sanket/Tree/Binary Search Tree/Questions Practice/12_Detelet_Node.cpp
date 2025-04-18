/* 
    ? lecture 70 : Partial BST
    ? https://www.naukri.com/code360/problems/validate-bst_799483?leftPanelTab=0&leftPanelTabValue=PROBLEM

    Problem statement
Given a binary tree with N number of nodes, check if that input tree is Partial BST (Binary Search Tree) or not. If yes, return true, return false otherwise.

A binary search tree (BST) is said to be a Partial BST if it follows the following properties.

• The left subtree of a node contains only nodes with data less than and equal to the node’s data.
• The right subtree of a node contains only nodes with data greater than and equal to the node’s data.
• Both the left and right subtrees must also be partial binary search trees.
Example:
Input:


Answer:

Level 1: 

All the nodes in the left subtree of 4 (2, 1, 3) are smaller 
than 4, all the nodes in the right subtree of the 4 (5) are 
larger than 4.

 */

#include<iostream>
#include<climits>
using namespace std;

template <typename T>

class Node {

    public:

        T data;
        Node *left;
        Node *right;

        Node (int d) {
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }

};

bool isSolve(Node<int> *root , int min , int max) {

    // base case
    if(root == NULL) {
        return true;
    }

    if(root -> data >= min && root -> data <= max) {

        bool left = isSolve(root -> left , min , root -> data);
        bool right = isSolve(root -> right , root -> data , max);
    }

    else {
        return false;
    }

    // if(root == NULL) return true;

    // if(root -> data <= min || root -> data >= max) return false;

    // return isPartialBST(root -> left , min , root -> data) && isPartialBST(root -> right , root -> data , max);

}

bool isPartialBST(Node<int> *root) {

    return isSolve(root , INT_MIN , INT_MAX);
    
}

int main() {

    Node<int> *root = new Node<int>(4);
    root -> left = new Node<int>(2);
    root -> right = new Node<int>(5);
    root -> left -> left = new Node<int>(1);
    root -> left -> right = new Node<int>(3);

    if(isPartialBST(root)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;

}

/* 

    ! imp theory

   ^ BinaryTreeNode<int> *root , here why we use <int> 
   ^ we can directly write like this BinaryTreeNode *root:
   ^ also tell what is diff between them 

       The use of BinaryTreeNode<int> *root versus BinaryTreeNode *root depends on whether the BinaryTreeNode class is defined as a template or not. Let's clarify the differences:
    1. Template Class Definition:
    If BinaryTreeNode is defined as a template class, it allows you to create nodes that can hold different data types. The syntax for defining a template class looks like this:
    
    
  *  template <typename T>
    class BinaryTreeNode {
    public:

        T data; // This can hold any data type specified when creating the node.
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
    
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };
    
    
    2. Using the Template:
    When you declare BinaryTreeNode<int> *root, you are specifying that this particular instance of BinaryTreeNode will hold integer values. This means that the data member of this node will be of type int.
    3. Non-Template Class:
    If you were to define BinaryTreeNode without templates, like this:
    
    
  *  class BinaryTreeNode {
    public:
        int data; // Fixed to hold only integers.
        BinaryTreeNode *left;
        BinaryTreeNode *right;
    
        BinaryTreeNode(int data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };
    
    In this case, you would declare BinaryTreeNode *root without the <int>, because the class is not templated and is specifically designed to hold integers.
    Differences:
    Flexibility:
    BinaryTreeNode<int> *root: This allows you to create nodes that can hold integers. You can also create nodes for other data types (e.g., BinaryTreeNode<double>, BinaryTreeNode<string>, etc.) by specifying a different type.
    BinaryTreeNode *root: This would only work if BinaryTreeNode is defined to hold a specific type (like int), and you cannot change the type without modifying the class definition.
    Type Safety:
    Using templates provides type safety, ensuring that the data type is consistent throughout the tree. If you try to insert a different type into a BinaryTreeNode<int>, the compiler will give you an error.
    Summary:
    Use BinaryTreeNode<int> *root if BinaryTreeNode is a template class that can hold various data types.
    Use BinaryTreeNode *root if BinaryTreeNode is a non-template class that is fixed to a specific data type (like int).
 */