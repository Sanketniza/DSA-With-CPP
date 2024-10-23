/* 
    ? Right View of Binary Tree
    ? https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1
 */


#include<iostream>
#include<vector>
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

void solve(Node* root, vector<int> &ans, int level) {

    if(root == NULL) return;

    if(level == ans.size()) ans.push_back(root->data);

    solve(root->right, ans, level + 1);
    solve(root->left, ans, level + 1);
}

vector<int> rightViewOfBinaryTree(Node* root) {

    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> rightView = rightViewOfBinaryTree(root);
    for(int i = 0; i < rightView.size(); i++) {
        cout << rightView[i] << " ";
    }

    return 0;

}

