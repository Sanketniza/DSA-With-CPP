/* 
    ? Huffman Encoding
    ? Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] has f[i] frequency. Your task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree.

    Note: While merging if two nodes have the same value, then the node which occurs at first will be taken on the left of Binary Tree and the other one to the right, otherwise Node with less value will be taken on the left of the subtree and other one to the right.

    Example 1:

    S = "abcdef"
    f[] = {5, 9, 12, 13, 16, 45}
    Output: 
    0 100 101 1100 1101 111
    Explanation:
    Steps to print codes from Huffman Tree
    HuffmanCodes will be:
    f : 0
    c : 100
    d : 101
    a : 1100
    b : 1101
    e : 111
    Hence printing

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


    class Node {

        public:
            int data;
            Node *left;
            Node *right;

            Node(int data) {
                this->data = data;
                left = right = NULL;
            }
    };

    class compare {
        public:
            bool operator()(Node* a, Node* b) {
                return a->data > b->data;
            }
    };

    void traversal(Node* root, string temp, vector<string> &ans) {

        if(root == NULL) {
            return;
        }

        if(root->left == NULL && root->right == NULL) {
            ans.push_back(temp);
            return;
        }

        traversal(root->left, temp + "0", ans);
        traversal(root->right, temp + "1", ans);
    }

int main() {

    string s = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};

    priority_queue<Node*, vector<Node*>, compare> q;

    for(int i = 0; i < s.length(); i++) {
        Node* temp = new Node(f[i]);
        q.push(temp);
    }

    while(q.size() > 1) {

        Node *first = q.top();
        q.pop();

        Node *second = q.top();
        q.pop();

        Node* newNode = new Node ( first->data + second->data);

        newNode->left = first;
        newNode->right = second;

        q.push(newNode);
    }

    Node* root = q.top();
    vector<string> ans;
    string temp = "";

    traversal(root, temp, ans);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
   
 return 0;
}