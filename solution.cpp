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
class Solution {
public:

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
    
private:
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        // Base case: if the left index exceeds the right index, return nullptr
        if (left > right) {
            return nullptr;
        }
        
        // Find the middle element to use as the root
        int mid = left + (right - left) / 2; 
        
        // Create a new node with the middle element as the value
        TreeNode* root = new TreeNode(nums[mid]);
        
        // Recursively build the left subtree using elements before the middle
        root->left = buildBST(nums, left, mid - 1);
        
        // Recursively build the right subtree using elements after the middle
        root->right = buildBST(nums, mid + 1, right);
        
        return root;
    }
};