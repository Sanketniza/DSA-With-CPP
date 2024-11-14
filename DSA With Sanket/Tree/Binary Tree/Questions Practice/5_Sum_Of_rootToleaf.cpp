#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class node {
    public:

        int data;
        node *left;
        node *right;

        node(int d) {
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }

};

void solve (node *root , int len , int mlen , int sum , int &msum) {

    if(root == NULL) {

        if(len > mlen) {
            mlen = len;
            msum = sum;
        }

        else if (len == mlen) {
            msum = max(len , mlen);
        }

        return;
    }

    sum += root -> data;

     solve (root -> left , len + 1 , mlen , sum , msum);
     solve (root -> right , len + 1 , mlen , sum , msum);


}

int sumofnode(node *root) {

    int len = 0;
    int mlen = 0;
    int sum = 0;
    int msum = INT_MIN;

    solve (root , len , mlen , sum , msum);

    return msum;
}

int main() {

        node* root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(7);
    root->left->right = new node(1);
    root->left->right->left = new node(6);
    root->right->left = new node(2);
    root->right->right = new node(3);


    cout << "hello " << sumofnode(root) << endl;


 return 0;
}