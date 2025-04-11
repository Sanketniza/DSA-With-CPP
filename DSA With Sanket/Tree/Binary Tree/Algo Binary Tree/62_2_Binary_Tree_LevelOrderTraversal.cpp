#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
        int data;
        node *left;
        node *right;

        node(int d) {

            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }

};

node *buildTree(node *root) {

    cout << "Enter the data : "  << endl;
    int data;
    cin >> data;

    root = new node (data);

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of : " << data << endl;
    root -> left = buildTree(root -> left);

    cout << "Enter data for inserting in right of : " << data << endl;
    root -> right = buildTree(root -> right);
    return root;

}

void levelOrderTraversal(node *root) {

    queue<node*> q;
    // cout << "root : " << root -> data << endl;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {

        node *temp = q.front();
        // cout << "temp : " << temp -> data << endl;
        q.pop();

        if(temp == NULL) {
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) {
              //queue still has some child nodes
              q.push(NULL);
            }
        }

        else {

            cout << temp -> data << " ";

            if(temp -> left) {
                q.push(temp -> left);
            }

            if(temp -> right) {
                q.push(temp -> right);
            }
        }
    }
}

vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        // q.push(NULL);

        while(!q.empty()) {

           int levelSize = q.size();
           vector<int> currLevel;

           for(int i = 0; i < levelSize; i++) {
              TreeNode* front = q.front();
              q.pop();

              currLevel.push_back(front -> val);

              if(front -> left) {
                q.push(front -> left);
              }

              if(front -> right) {
                q.push(front -> right);
              }

            }

           ans.push_back(currLevel);
        }

        return ans;

        //  ans = Input: root = [3,9,20,null,null,15,7]
                // Output: [[3],[9,20],[15,7]]
    }

int main() {
 
    // node *root = new node (1);
    
    node *root = NULL;

    //creating a Tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    root = buildTree(root);

    cout << "Printing the level order traversal output " << endl;
    levelOrderTraversal(root);

    return 0;
}