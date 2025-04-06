#include<iostream>
#include<bits/stdc++.h>
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

vector<int> verticalTraversal(Node* root) {
    
    // create map: <horizontal distance, <level, vector of node values>>
    map<int, map<int, vector<int>>> nodes;

    // create queue: <Node*, <horizontal distance, level>>
    queue<pair<Node*, pair<int, int>>> q;

    vector<int> ans;

    if(root == NULL) {
        return ans;
    }

    // Push root with hd=0, level=0
    q.push(make_pair(root, make_pair(0, 0)));

    while(!q.empty()) { // Bug fix: q.empty() is a function, not a variable

        // find front node
        pair<Node*, pair<int, int>> temp = q.front();
        q.pop();

        // get node
        Node* frontNode = temp.first;

        // get horizontal distance
        int hd = temp.second.first;

        // get level
        int level = temp.second.second;

        // Store node value in the map
        nodes[hd][level].push_back(frontNode->data); // Bug fix: using correct map structure

        // if left node is present
        if(frontNode->left) {
            q.push(make_pair(frontNode->left, make_pair(hd-1, level+1)));
        }

        // if right node is present (Bug fix: removed else, both conditions should be checked independently)
        if(frontNode->right) {
            q.push(make_pair(frontNode->right, make_pair(hd+1, level+1)));
        }
    }

    // iterate through the map to get the vertical traversal
    for(auto i : nodes) { // For each horizontal distance
        for(auto j : i.second) { // For each level at this horizontal distance
            for(auto k : j.second) { // For each node value at this level and horizontal distance
                ans.push_back(k);
            }
        }
    }

    return ans;
}

// Function to print vector
void printVector(vector<int>& v) {
    for(int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    // Create a sample tree
    Node* root = new Node(1);
    
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Perform vertical traversal
    vector<int> result = verticalTraversal(root);
    
    // Print the result
    cout << "Vertical Traversal: ";
    printVector(result);

    return 0;
    
}