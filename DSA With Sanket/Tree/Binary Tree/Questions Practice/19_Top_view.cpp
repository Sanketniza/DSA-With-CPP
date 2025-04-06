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

vector<int> solve(Node *root ) {

    //create ans vector
    vector<int> ans;
    
    if(root == NULL) {
        return ans;
    }
 

    //create a map to store the top view
    map<int , int> topNode;

    // create queue to do level order traversal
    queue<pair<Node* , int>> q;
   // push the root node with horizontal distance 0 and level 0

   // push the root node with horizontal distance 0 and level 0
    q.push(make_pair(root , 0));

    while(!q.empty()) {

        // get the front node and its horizontal distance
        pair<Node* , int> temp = q.front();
        q.pop();

        // create a pointer to the front node
        Node* frontNode = temp.first;

        // get the horizontal distance of the front node
        int hd = temp.second;

        // if the horizontal distance is not present in the map
        // then add the front node to the map

        if(topNode.find(hd) == topNode.end()) {
            topNode[hd] = frontNode -> data;
        }

        // if the left child is present then push it to the queue
        if(frontNode -> left) {
            q.push(make_pair(frontNode -> left , hd - 1));
        }

        // if the right child is present then push it to the queue
        if(frontNode -> right) {
            q.push(make_pair(frontNode -> right , hd + 1));
        }

    }

    // iterate the map and push the values to the ans vector
    for(auto i : topNode) {
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

    vector <int> ans;
    ans =  solve(root);
    cout << "Top view of the binary tree is: ";
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }


 return 0;
}