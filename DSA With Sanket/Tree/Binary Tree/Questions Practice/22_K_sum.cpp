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

void findPath(Node *root , int k , int &count , vector<int> &ans) {
    
    if(root == NULL) {
        return;
    }

    ans.push_back(root -> data);

    findPath(root -> left , k , count , ans);
    findPath(root -> right , k , count , ans);

    int sum = 0;
    for(int i = ans.size() - 1 ; i >= 0 ; i--) {
        sum += ans[i];
        if(sum == k) {
            count++;
        } 
    }

    ans.pop_back();
}

int main() {
    Node *root = new Node(1);
    
    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    
    root -> right = new Node(3);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    int k = 7;
    int count = 0;
    vector<int> ans;

    findPath(root , k , count , ans);

    cout << "Count of paths with sum " << k << " is: " << count << endl;
    
    return 0;
}

