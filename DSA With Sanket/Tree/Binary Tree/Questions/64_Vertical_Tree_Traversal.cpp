/* 
    Topic :- Tree
    Subtopic :- Vertical Tree Traversal
    Difficulty :- Medium
    ? ilnk :  https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

    Question Link :- https://www.codingninjas.com/studio/problems/vertical-traversal-of-binary-tree_920533?leftPanelTab=0

    Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
    If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

    Example 1:

    Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9           
    Output: 
    4 2 1 5 6 3 8 7 9 

    Explanation:
    Vertical-Line 1: 4
    Vertical-Line 2: 2
    Vertical-Line 3: 1 5 6
    Vertical-Line 4: 3 8
    Vertical-Line 5: 7
    Vertical-Line 6: 9
 */

#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node(int d) {
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }

};

vector<int> verticalOrderTraversal(Node *root) {

    // map to store the nodes and their horizontal distance and level
     map<int, map<int,vector<int> > > nodes;
     // map to store < int = horizontal distance ,  int = level , vector<int> = nodes >

     // queue to store the nodes and their horizontal distance and level
        cout << "value in Node * is : " << root << endl;
        queue< pair<Node*, pair<int,int> > > q;

    // vector to store the result
    vector<int> ans;
        
        if(root == NULL)
            return ans;
            
        q.push(make_pair(root, make_pair(0,0)));

        cout << endl << " ----------------------------------- " << endl;
        
        while(!q.empty()) {
            
            cout << "Inside While Loop" << endl;
            cout << "size of q is : " << q.size() << endl;
            cout << "queue is : " << q.front().first -> data << endl;

            pair<Node*, pair<int,int> > temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            cout << "value in frontNode is : " << frontNode -> data << endl;

            int hd = temp.second.first;
            cout << "value in horizontal distance is : " << hd << endl;

            int lvl = temp.second.second;
            cout << "value in level is : " << lvl << endl;
            
            nodes[hd][lvl].push_back(frontNode->data);
            cout << "value in nodes is : " << nodes[hd][lvl][0] << endl;
            
            if(frontNode->left) {
                q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1) ));
                cout << "value in left node is : " << frontNode->left -> data << endl;
            }
                
            if(frontNode->right) {
                q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
                cout << "value in right node is : " << frontNode->right -> data << endl;
            }
            cout << endl;
        }

        cout << endl << " ----------------------------------- " << endl;
        
        for(auto i: nodes) {
            cout << "value in nodes is : " << i.first << endl;
            
            for(auto j:i.second) {
                cout << "value in nodes is : " << j.first << endl;

                for(auto k:j.second) {
                    cout << "value in nodes is : " << k << endl;
                    ans.push_back(k);
                    cout << "value in ans is : " << ans[0] << endl;
                }
            }
        }

        cout << endl << " ----------------------------------- " << endl;

        return ans;
}


int main() {

    Node *root = new Node(1);
    cout << "value in root is : " << root << endl;
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);
    root -> right -> left -> right = new Node(8);
    root -> right -> right -> right = new Node(9);

    vector<int> result = verticalOrderTraversal(root);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

 return 0;
}