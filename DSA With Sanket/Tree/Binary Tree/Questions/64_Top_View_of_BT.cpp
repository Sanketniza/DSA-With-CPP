/* 
    ? Top View of Binary Tree
    ? https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

    ? Problem Statement:

        Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

           1
        /     \
       2       3
      /  \    /   \
    4    5  6      7

    Top view will be: 4 2 1 3 7
    Note: Return nodes from leftmost node to rightmost node. Also if 2 nodes are outside the shadow of the tree and are at same position then consider the left ones only(i.e. leftmost). 
    For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. Here 8 and 9 are on the same position but 9 will get shadowed.

    Example 1:

    Input:
          1
        /   \
       2     3
    Output: 2 1 3
    Example 2:

    Input:
           10
         /    \
       20      30
     /   \    /    \
    40   60  90    100
    Output: 40 20 10 30 100
 */

#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

vector<int> topView(Node* root) {

    vector<int> ans;
    
    if(root == NULL) 
    {
        return ans;
    }
    
    map<int,int> topNode;
    queue<pair<Node*, int> > q;
    
    q.push(make_pair(root, 0));
    
    while(!q.empty()) {

        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;
        
        //if one value is present for a HD, then do nothing
        if(topNode.find(hd) == topNode.end())
            topNode[hd] = frontNode -> data;
            
        if(frontNode->left)
            q.push(make_pair(frontNode->left, hd-1));

        if(frontNode->right)
            q.push(make_pair(frontNode->right, hd+1));
    }
    
    for(auto i:topNode) 
    {
        ans.push_back(i.second);
    }

        return ans;
}

int main() {

    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right = new Node(3);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    vector<int> ans = topView(root);

    for(auto i: ans) {
        cout << i << " ";
    }

 return 0;
}