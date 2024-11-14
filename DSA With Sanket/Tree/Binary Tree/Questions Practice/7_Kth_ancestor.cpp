#include<iostream>
#include<vector>
#include<limits.h>

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

Node *kthAncestor(Node *root , int k , int node) {

    // base case
    if(root == NULL) {
        return NULL;
    }

    if(root -> data == node) {
        return root;
    }

   Node *l =  kthAncestor(root , k , node);
   Node *r =  kthAncestor(root , k , node);

   if(l != NULL && r == NULL) {

        k--;
         if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return l;
    }

    if(l == NULL && r != NULL) {

        k--;
          if(k <= 0) {
            k = INT_MAX;
            return root;
          }

          return r;
    } 

    return NULL;
}

int solve (Node *root , int k , int node) {
    Node * ans = kthAncestor(root , k , node);

      if(ans == NULL || ans->data == node)
       { return -1;}
    else
        {return ans->data;}

        cout << "kay " << ans -> data;
}

int main() {

    
     Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->left->left = new Node(76);
    root->right->right = new Node(7);
    root->right->right->right = new Node(17);

    int k = 1;
    int node = 3;

    solve(root , k , node );


 return 0;
}