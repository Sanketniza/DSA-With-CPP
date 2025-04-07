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

pair<int , int> getMaxSum(Node *root) {

    if(root == NULL) {
        pair<int , int> p = make_pair(0 , 0);
        return p;
    }

    pair<int , int> left = getMaxSum(root -> left);
    pair<int , int> right = getMaxSum(root -> right);

    pair<int , int> res;
    res.first = root -> data + left.second + right.second; // include the current node
    res.second = max(left.first , left.second) + max(right.first , right.second); // exclude the current node

    return res;

}

int solve(Node *root) {

   pair<int , int> a = getMaxSum(root);

   return max(a.first , a.second);
}

int main() {
    Node *root = new Node(1);
    
    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> left -> right -> left = new Node(8);
    root -> left -> right -> right = new Node(9);
    
    root -> right = new Node(3);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    int ans = solve(root); 
    cout << ans << endl;
    
    return 0;
}