/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Define TreeNode if not already defined
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return generateSubtrees(1, n);
    }
    
    vector<TreeNode*> generateSubtrees(int start, int end) {
        vector<TreeNode*> result;
        
        // Base case: If start > end, return null (empty tree)
        if (start > end) {
            result.push_back(nullptr);
            return result;
        }
        
        // Try each number from start to end as the root
        for (int i = start; i <= end; i++) {
            // Generate all possible left subtrees
            vector<TreeNode*> leftSubtrees = generateSubtrees(start, i - 1);
            
            // Generate all possible right subtrees
            vector<TreeNode*> rightSubtrees = generateSubtrees(i + 1, end);
            
            // Connect left and right subtrees to the root i
            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    // Create a new root with the current value
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        
        return result;
    }
    
    // Helper function to print a tree in level order
    void printTree(TreeNode* root) {
        if (!root) {
            cout << "[null]";
            return;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        cout << "[";
        
        bool first = true;
        while (!q.empty()) {
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if (!first) {
                    cout << ",";
                }
                first = false;
                
                if (node) {
                    cout << node->val;
                    q.push(node->left);
                    q.push(node->right);
                } else {
                    cout << "null";
                }
            }
        }
        cout << "]";
    }
    
    // Helper function to free memory of a tree
    void deleteTree(TreeNode* root) {
        if (!root) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};

int main() {
    Solution solution;
    int n = 3; // Example input
    vector<TreeNode*> trees = solution.generateTrees(n);
    
    // Print the number of unique BSTs generated
    cout << "Number of unique BSTs: " << trees.size() << endl;
    
    // Print each tree
    cout << "Trees:" << endl;
    for (int i = 0; i < trees.size(); i++) {
        cout << i + 1 << ": ";
        solution.printTree(trees[i]);
        cout << endl;
    }
    
    // Clean up memory
    for (TreeNode* tree : trees) {
        solution.deleteTree(tree);
    }
    
    return 0;
}
