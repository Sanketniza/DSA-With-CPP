#include<iostream>
#include<bits/stdc++.h>
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

 int solve(Node *root , vector<int> &ans) {
    if(root == NULL) {
        return 0;
    }
    
    int left = solve(root -> left , ans);
    int right = solve(root -> right , ans);

    if(root -> left == NULL || root -> right == NULL) {
        ans.push_back(root -> data);
    }
 
}

int main() {

    Node *root = new Node(44);
    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right = new Node(3);

    vector<int> anss;
    solve(root , anss);

    for(int i = 0; i < anss.size(); i++) {
        cout << anss[i] << " ";
    }



 return 0;
}