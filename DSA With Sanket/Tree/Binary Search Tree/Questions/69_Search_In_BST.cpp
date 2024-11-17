/* 
    ? lecture 69 : Search in BST
    ? https://www.naukri.com/code360/problems/search-in-bst_1402878?count=25&page=2&search=&sort_entity=order&sort_order=ASC&attempt_status=NOT_ATTEMPTED&leftPanelTabValue=PROBLEM

    Problem statement
    There is a Binary Search Tree (BST) consisting of ‘N’ nodes. Each node of     this BST has some integer data.
    
    
    
    You are given the root node of this BST, and an integer ‘X’. Return true     if there is a node in BST having data equal to ‘X’, otherwise return false.
    
    
    
    A binary search tree (BST) is a binary tree data structure that has the     following properties:
    
    1. The left subtree of a node contains only nodes with data less than the     node’s data.
    
    2. The right subtree of a node contains only nodes with data greater than     the node’s data.
    
    3. The left and right subtrees must also be binary search trees.
    Note:
    It is guaranteed that all nodes have distinct data.
    Detailed explanation ( Input/output format, Notes, Images )
    Sample Input 1:
    7 8
    4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    Sample Output 1:
    False
    Explanation For Sample Input 1:
    There is no node having data 8. See the problem statement for the picture     of this BST.
    Sample Input 2:
    4 1
    3 1 5 -1 2 -1 -1 -1 -1
    Sample Output 2:
    True
    Explanation For Sample Input 1:
    There is a left node, and it has data 1. Thus, we should print ‘True’. 
 */



 // todo: Here are two ways to solve this problem

 //* 1. Recursive way
    //^ Time Complexity : O(N)
    //^ Space Complexity : O(N)

 //* 2. Iterative way
    //^ Time Complexity : O(N)
    //^ Space Complexity : O(1)


#include<iostream>
#include<vector>
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

 //* 1. Recursive way
bool SearchInBST(Node *root , int x) {

    if(root == NULL) {
        return false;
    }

    if (root -> data == x) {
        return true;
    }

    // recursive call
    if( root -> data > x) {
        return SearchInBST(root -> left , x);
    } else {
        return SearchInBST(root -> right , x);
    }
}

 //* 2. Iterative way
 void storeInorder(Node *root , vector<int> &v) {

    if(root == NULL) {
        return;
    }

    storeInorder(root -> left , v);
    v.push_back(root -> data);
    storeInorder(root -> right , v);
 }

bool Iterativeway(Node *root, vector<int> &v, int x) {
    Node *temp = root;
    
    while (temp != NULL) {
        if (temp->data == x) {
            return true;    // Found the value
        }
        
        if (x < temp->data) {
            temp = temp->left;   // Go to left subtree
        } else {
            temp = temp->right;  // Go to right subtree
        }
    }
    
    return false;   // Value not found
}

int main() {

    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    int x = 25;

    //* 1. Recursive way
    cout << "Recursive Search in BST : " << SearchInBST(root, x) << endl;

    //* 2. Iterative way
    vector<int> v;
    storeInorder(root, v);
    
    // Call Iterativeway correctly
    bool result = Iterativeway(root, v, x);
    cout << "Iterative Search in BST : " << (result ? "True" : "False") << endl;

    return 0;
}
