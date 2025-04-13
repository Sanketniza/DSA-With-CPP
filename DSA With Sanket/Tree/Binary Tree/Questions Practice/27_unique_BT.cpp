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

void printVector(vector<Node *> &ans) {
    for(auto it : ans) {
        cout << it -> data << " ";
    }
    cout << endl;
}

int main() {
    int n = 3;

   
    vector<Node *>ans = solve(n);

    printVector(ans);



    
    return 0;
}