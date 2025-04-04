/* 
    ? Bottom View of Binary Tree
    ? https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1


    Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

    Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level traversal is considered. For example, in the below diagram, 3 and 4 are both the bottommost nodes at a horizontal distance of 0, here 4 will be considered.

                          20
                        /    \
                      8       22
                    /   \     /   \
                  5      3 4     25
                         /    \      
                     10       14

    For the above tree, the output should be 5 10 4 14 25.

    Examples :

    Input:
           1
         /   \
        3     2
    Output: 3 1 2
 */

  #include<iostream>
  #include<map>
  #include<queue>
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

    vector<int> bottomViewOfBinaryTree(Node* root) {

        vector<int> ans;
        if(root == NULL) return ans;

        map<int , int> buttomNode;
        queue<pair<Node*, int>> q;

        q.push(make_pair(root, 0));

        while(!q.empty()) {

            pair<Node*,int> temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int hd = temp.second;

            buttomNode[hd] = frontNode -> data;

            if(frontNode -> left) q.push(make_pair(frontNode -> left, hd - 1));
            if(frontNode -> right) q.push(make_pair(frontNode -> right, hd + 1));


        }
        
        for(auto i : buttomNode) {
            ans.push_back(i.second);
        }

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

    vector<int> bottomView = bottomViewOfBinaryTree(root);
    for(int i = 0; i < bottomView.size(); i++) {
        cout << bottomView[i] << " ";
    }
  
   return 0;
  }