#include<iostream>
#include<bits/stdc++.h>
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

vector<Node *> generateSubtrees(int start, int end) {

    vector<Node *> ans;
    
    // base case
    if(start > end) {
       ans.push_back(NULL);
       return ans;
    }

    // iterate through all the numbers from start to end
    for(int i = start; i <= end; i++) {
        
        //left subtree
        vector<Node *> leftSubtrees = generateSubtrees(start, i - 1);

        // right subtree
        vector<Node *> rightSubtrees = generateSubtrees(i + 1, end);

        // connect left and right subtree to the root i
        for(auto left : leftSubtrees) {
            for(auto right : rightSubtrees) {
                Node *root = new Node (i);
                root -> left = left;
                root -> right = right;
                ans.push_back(root);
            }
        }
    }

    return ans;
};

vector<Node *> solve(int n) {
    
    if(n == 0) {
        return vector<Node *>();
    }

    return generateSubtrees(1, n);
};


vector<int> traversalBT(Node *root) {

    vector<int> ans;

    if(root == NULL) {
        return ans;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        
        Node *front = q.front();
        q.pop();

        if(front == NULL) {
            ans.push_back(-1);

            if(!q.empty()) {
                q.push(NULL);
            }
            
        }

        else {
            ans.push_back(front -> data);

            if(front -> left) {
                q.push(front -> left);
            }

            if(front -> right) {
                q.push(front -> right);
            }
        }
    }
}



int main() {
    int n = 3;

   
    vector<Node *>ans = solve(n);
    
    return 0;
}