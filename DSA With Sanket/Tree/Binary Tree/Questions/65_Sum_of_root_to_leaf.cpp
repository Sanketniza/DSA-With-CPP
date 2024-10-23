/* 
    ? Sum of nodes on the longest path from root to leaf node
    ? https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

    Given a binary tree having n nodes. Find the sum of all nodes on the longest path from root to any leaf node. If two or more paths compete for the longest path, then the path having maximum sum of nodes will be considered.

    Example 1:

    Input: 
             4        
           /   \       
          2     5      
         / \   / \     
        7   1 2   3    
           /
          6
    Output: 
    13
    Explanation:
             4        
           /   \       
          2     5      
         / \   / \     
        7   1 2   3  
           /
          6
    The highlighted nodes (4, 2, 1, 6) above are part of the longest root to leaf path having sum = (4 + 2 + 1 + 6) = 13 
 */

#include<iostream>
#include<vector>   
#include<climits>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }

};

void solve(Node* root, int l, int &ml, int sum, int &msum) {

    if(root == NULL) {
       
       if(l > ml){
        ml = l;
        msum = sum;
       }

       else if(l == ml) {
        msum = max(sum, msum);
       }

       return;
    }

    sum += root->data;
    solve(root->left, l+1, ml, sum, msum);
    solve(root->right, l+1, ml, sum, msum);

}

int sumOfLongRootToLeafPath(Node* root) {

    int l = 0;
    int ml = 0;

    int sum = 0;
    int msum = INT_MIN;

    solve(root, l, ml, sum, msum);

    return msum;
}

int main() {

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->left->right->left = new Node(6);
    root->right->left = new Node(2);
    root->right->right = new Node(3);

    cout << "Sum of nodes on the longest path from root to leaf node: " << sumOfLongRootToLeafPath(root) << endl;

 return 0;
}