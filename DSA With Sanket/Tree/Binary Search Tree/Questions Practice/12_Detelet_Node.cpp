/*
    ? lecture 70:  Find K-th smallest Element in BST
    ? https://www.naukri.com/code360/problems/find-k-th-smallest-element-in-bst_1069333?leftPanelTab=0&leftPanelTabValue=PROBLEM

    Problem statement
    Given a binary search tree and an integer ‘K’. Your task is to find the ‘K-th’ smallest element in the given BST( binary search tree).

    BST ( binary search tree) -

    If all the smallest nodes on the left side and all the greater nodes on the right side of the node current node.

    Example -


    Order of elements in increasing order in the given BST is - { 2, 3, 4, 5, 6, 7, 8, 10 }

    Suppose given ‘K = 3’ then 3rd smallest element is ‘4’.

    Suppose given ‘K = 8’ then 8th smallest element is ‘10’.

    Note:
    1. You are not required to print the output explicitly, it has already been taken care of. Just implement the function and return the ‘K-th’ smallest element of BST.
    2. You don’t need to return ‘K-th’ smallest node, return just value of that node.
    3. If ‘K-th’ smallest element is not present in BST then return -1.

 */

#include <iostream>
using namespace std;

template <typename T>  // template for generic type , T can be int , char , float , double , etc.
class bst
{
    public:
        T data;
        bst *left;
        bst *right;

        bst(T data)
        {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

int kthSmallest(bst<int> *root, int k , int &i)
{
    // base case
    if(root == NULL) {
        return -1;
    }

    // recursive call

    int left = kthSmallest(root -> left , k , i);
    // cout << "left is : " << left << endl;

    if(left != -1) {
        // cout << "left is not -1" << endl;
        return left;
    }

    // N
    i++;

    if( i == k ) {
        return root -> data;
    }

    //R
    return kthSmallest(root -> right , k , i);

}

void solve(bst<int> *root , int k)
{
    static int count = 0; // static variable to keep track of the count of nodes visited
    static int result = -1;

    if(root == NULL) {
        return;
    }

    // Inorder Traversal
    solve(root -> left , k);

    count++;

    if(count == k) {
        result = root -> data;
        cout << "The " << k << " th smallest element in the BST is: " << result << endl;
        return;
    }

    solve(root -> right , k);
}


int main()
{

    bst<int> *root = new bst<int>(15);
    root->left = new bst<int>(10);
    root->right = new bst<int>(20);
    root->left->left = new bst<int>(8);
    root->left->left->left = new bst<int>(5);
    root->left->right = new bst<int>(12);
    root->left->right->left = new bst<int>(11);
    root->left->right->right = new bst<int>(13);

    // inorder traversal : 5 8 10 11 12 13 15 20

    int k = 4;
    int i = 0;
    cout << kthSmallest(root, k , i) << endl;

    // second approach
    solve(root , k);

    return 0;
}