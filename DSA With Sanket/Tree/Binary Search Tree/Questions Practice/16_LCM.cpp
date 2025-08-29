
#include<iostream>
using namespace std;

 /* 
    ? Two ways to solve this problem

        * Recursive way
            ^ - Time Complexity = O(n);
            ^ - space Complexity = O(n);

        * Iterative way
            ^ - Time Complexity = O(n);    
            ^ - Time Complexity = O(1);     
 
  */

class  bst {
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

//todo: Recursive way

bst * lcaOfBST(bst *root , int p , int q) {

    if(root == NULL) {
        return NULL;
    }

    if(root -> data > p && root -> data > q) {
        return lcaOfBST(root -> left , p , q );
    }

    if(root -> data < p && root -> data < q) {
        return lcaOfBST (root -> right , p , q);
    }

    return root;

}

//todo: Iterative way
bst * lcaOfBST_Iterative(bst *root , int p , int q) {

    while (root != NULL) {

        if(root -> data > p && root -> data > q) {
             root = lcaOfBST_Iterative(root -> left , p , q );
        }

        else if (root -> data < p && root -> data < q) {
             root = lcaOfBST_Iterative (root -> right , p , q);
        }

        else {
            return root;
        }
    }
}
 

int main() {

    
    bst *root = new bst(15);
    root -> left = new bst(10);
    root -> right = new bst(20);
    root -> left -> left = new bst(8);
    root -> left -> right = new bst(12);
    root -> right -> left = new bst(16);
    root -> right -> right = new bst(25);

    int p = 10;
    int q = 25;

    bst *ans = lcaOfBST(root , p , q);
    cout << "Recursive way: " << ans -> data << endl;

    bst *ans2 = lcaOfBST_Iterative(root , p , q);
    cout << "Iterative way: " << ans2 -> data << endl;

 return 0;
}