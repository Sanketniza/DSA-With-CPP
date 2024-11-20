
/* 
        ? lecture 71: Flatten BST to Sorted List
        ? https://www.naukri.com/code360/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=0&leftPanelTabValue=PROBLEM

        Problem statement
You have been given a Binary Search Tree (BST). Your task is to flatten the given BST to a sorted list. More formally, you have to make a right-skewed BST from the given BST, i.e., the left child of all the nodes must be NULL, and the value at the right child must be greater than the current node.

A binary search tree (BST), also called an ordered or sorted binary tree, is a rooted binary tree whose internal nodes each store a value greater than all the values in the node's left subtree and less than those in its right subtree.

Follow Up :
Can you solve this in O(N) time and O(H)  space complexity?
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 100
1 <= N <= 5000
0 <= node.data <= 10^9, (where node data != -1)

Where 'N' denotes the number of nodes in the given tree.

Time Limit: 1 second
Sample Input 1
2
10 6 12 2 8 11 15 -1 -1 -1 -1 -1 -1 -1 -1
5 -5 8 -1 -1 -1 -1
Sample Output 1
2 -1 6 -1 8 -1 10 -1 11 -1 12 -1 15 -1 -1
-5 -1 5 -1 8 -1 -1
Explanation for Sample Input 1
For the first test case, the given BST is depicted below.

So, after flattening, the BST is transposed as the below figure.


For the second test case, the given BST is depicted below.

So, after flattening, the BST is transposed as the below figure.


Sample Input 2
2
5 3 7 -1 -1 6 8 -1 -1 -1 -1
2 1 -1 -1 -1
Sample output 2
3 -1 5 -1 6 -1 7 -1 8 -1 -1
1 -1 2 -1 -1

 */

#include<iostream>
#include<vector>
using namespace std;

class bst{
    public:
        int data;
        bst *left;
        bst *right;

        bst(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }

};

void solve(bst *root , vector<int> &v) {

    if(root == NULL) 
        return;

    solve(root -> left , v);
    v.push_back(root -> data);
    solve(root -> right , v);

}

bst *flatten(bst *root) {

    vector<int> v;
    solve(root , v);
    int n = v.size();

    bst *newNode = new bst(v[0]);
    bst *curr = newNode;

    for(int i = 1; i < n; i++) {

        bst *temp = new bst(v[i]);
        
        curr -> left = NULL;
        curr -> right = temp;
        curr = temp;       
    }

    curr -> left = NULL;
    curr -> right = NULL;

    return newNode;
}

int main() {

    bst *root = new bst(10);
    root -> left = new bst(6);
    root -> right = new bst(12);
    root -> left -> left = new bst(2);
    root -> left -> right = new bst(8);
    root -> right -> left = new bst(11);
    root -> right -> right = new bst(15);

    bst *ans = flatten(root);

    while(ans != NULL) {
        cout << ans -> data << " ";
        ans = ans -> right;
    }
    cout << endl;


 return 0;
}