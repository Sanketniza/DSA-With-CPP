
/* 
    ? lecture 72: Merge Two BSTs
    ? https://www.naukri.com/code360/problems/h_920474?leftPanelTab=0&leftPanelTabValue=PROBLEM


    Problem statement
You are given two binary search trees of integers having ‘N’ and ‘M’ nodes. Return an array that contains elements of both BST in sorted order.



A binary search tree (BST) is a binary tree data structure with the following properties.

• The left subtree of a node contains only nodes with data less than the node’s data.

• The right subtree of a node contains only nodes with data greater than the node’s data.

• Both the left and right subtrees must also be binary search trees.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
2 1 3 -1 -1 -1 -1
4 -1 -1
Sample Output 1:
1 2 3 4 
Explanation For Sample Output 1:
 The given BST are:-


The output will be 1 2 3 4
Sample Input 2:
4 2 7 -1 3 -1 -1 -1 -1  
5 1 7 -1 -1 -1 -1
Sample Output 2:
1 2 3 4 5 7 7 

 */

#include<iostream>
#include<vector>
using namespace std;

// Approach 1:
// 1. Convert both BSTs into sorted arrays
        // 1.1. Inorder traversal of BST gives sorted array
        // 1.2. Do inorder traversal of both BSTs and store the elements in two separate arrays
// 2. Merge both sorted arrays
        // 2.1. Use two pointer technique to merge two sorted arrays
// 3. Convert the merged sorted array into a BST
        // 3.1. Use the concept of balanced BST from lecture 69 to convert the sorted array into a balanced BST

class bst {
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

void inorder(bst *root , vector<int> &v) {

    if(root == NULL)
        return;

    inorder(root -> left , v);
    v.push_back(root -> data);
    inorder(root -> right , v);

}

vector<int> MergeArray(vector<int> &a , vector<int> &b) {

    vector<int> ans(a.size() + b.size());

    int i = 0;
    int j = 0;
    int k = 0;

    while ( i < a.size() && j < b.size()) {

        if(a[i] < b[j]) {
            ans[k++] = a[i];
            i++;
        }

        else {
            ans[k++] = b[j];
            j++;
        }
    }

    while( i < a.size()) {
        ans[k++] = a[i];
        i++;
    }

    while ( j < b.size()) {
        ans[k++] = b[j];
        j++;
    }

    return ans;
}

vector<int> mergeBSTs(bst *root1, bst *root2) {
    // todo: return merged array or vector not need to return tree

// step 1: 

    vector<int> bst1 , bst2;
    inorder(root1 ,bst1);
    inorder(root2 , bst2);

    cout << "Inorder of BST1: " << endl;
    for(int i = 0; i < bst1.size(); i++) {
        cout << bst1[i] << " ";
    }
    cout << endl;


    cout << "Inorder of BST2: " << endl;
    for(int i = 0; i < bst2.size(); i++) {
        cout << bst2[i] << " ";
    }

    cout << endl << endl;

// step 2:
    vector<int> mergeBST = MergeArray(bst1 , bst2);    

// step 3: 
    return mergeBST; 
}

bst *bstTree(int s , int e , vector<int> &v) {

        // -> creating bst tree from Inorder vector..

    // base case
    if(s > e) {
        return NULL;
    }

    int mid = (s + e) / 2;

    bst *root = new bst(v[mid]); // creating node with element is mid 

    // recursive call
    root -> left = bstTree(s , mid - 1 , v); 
    root -> right = bstTree(mid + 1 , e , v);

    return root;

}

bst* inOr(bst *root) {

    if(root == NULL) 
        return NULL;

    inOr(root -> left);
    cout << root -> data << " ";
    inOr(root -> right);    
}

bst *Tree(bst *root1  , bst *root2) {
    // todo: return binary tree

    // step 1: 
    vector<int> bst1 , bst2;
    inorder(root1 ,bst1);
    inorder(root2 , bst2);

    // step 2:
    vector<int> mergeBST = MergeArray(bst1 , bst2);  

    // step 3:

    int s = 0;
    int e = mergeBST.size() - 1;

    bst *ans = bstTree(s , e , mergeBST);

     inOr(ans);
    
}


int main() {

    bst *root1 = new bst(2);
    root1 -> left = new bst(1);
    root1 -> right = new bst(3);

    bst *root2 = new bst(4);
    root2 -> left = new bst(5);
    root2 -> right = new bst(7);

    vector<int> ans = mergeBSTs(root1, root2);

    cout << "Merged Array: " << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << endl << endl;

    cout << "Binary Tree in Inorder form: " << endl;
    // todo: print binary tree in inorder form
    bst *BSTTree = Tree(root1 , root2);

 return 0;
 
}