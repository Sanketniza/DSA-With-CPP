#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{ 
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

void done(Node *root , vector<int> &ans , int level) {

    if(root == NULL) return;

    if(level == ans.size()) {
        ans.push_back(root -> data);
    }

    done(root -> right , ans , level + 1);
    done(root -> left , ans , level + 1);
}

vector<int> solve(Node* root) {

    vector<int> ans;
    int level = 0;
    done(root, ans, level);
    return ans;
}

int main() {

     Node* root = new Node(1);
    root->left = new Node(2);
    // root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);

    vector<int> ans;
    ans = solve(root);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }


 return 0;
}

/* 

     

      I'll dry run the program line by line to show how the right view of a binary tree is calculated.

The tree structure based on the code is:

    1
   /
  2
 / \
4   5

Copy

Insert

Let's trace through the execution:

main() creates the tree structure as shown above
Then it would call solve(root) (though this call isn't shown in the snippet)
Let's trace through what would happen in solve(root):

vector<int> solve(Node* root) {
    vector<int> ans;  // Initialize empty vector
    int level = 0;    // Start at level 0
    done(root, ans, level);  // Call helper function
    return ans;  // Return the result
}

Copy

Insert

Now let's trace through the done() function:

First call: done(root, ans, 0)
root is Node with value 1
ans is empty vector
level is 0
level == ans.size() is true (0 == 0)
Add 1 to ans, so ans becomes [1]
Call done(root->right, ans, 1) - but root->right is NULL
Call done(root->left, ans, 1)


Call: done(root->left, ans, 1)
root->left is Node with value 2
ans is [1]
level is 1
level == ans.size() is true (1 == 1)
Add 2 to ans, so ans becomes [1, 2]
Call done(root->left->right, ans, 2)
Call done(root->left->left, ans, 2)


Call: done(root->left->right, ans, 2)
root->left->right is Node with value 5
ans is [1, 2]
level is 2
level == ans.size() is true (2 == 2)
Add 5 to ans, so ans becomes [1, 2, 5]
Call done(root->left->right->right, ans, 3) - but this is NULL
Call done(root->left->right->left, ans, 3) - but this is NULL


Call: done(root->left->left, ans, 2)
root->left->left is Node with value 4
ans is [1, 2, 5]
level is 2
level == ans.size() is false (2 != 3)
No value is added to ans
Call done(root->left->left->right, ans, 3) - but this is NULL
Call done(root->left->left->left, ans, 3) - but this is NULL
After all recursive calls complete, ans contains [1, 2, 5], which is returned by solve().

The key insight here is that the algorithm visits the right child first at each level. The first node encountered at each level (which will be the rightmost visible node from that level) is added to the result. This gives us the right view of the binary tree.

 */