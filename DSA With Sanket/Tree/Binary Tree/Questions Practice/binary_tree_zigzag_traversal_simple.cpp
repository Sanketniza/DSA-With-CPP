vector<int> zigZagTraversal(Node* root) {
    vector<int> result;
    
    // If tree is empty, return empty result
    if (root == NULL) {
        return result;
    }
    
    // Queue for level order traversal
    queue<Node*> q;
    q.push(root);
    
    // Flag to track level number (odd or even)
    bool isOddLevel = true;
    
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> currentLevel;
        
        // Process all nodes at current level
        for (int i = 0; i < levelSize; i++) {
            Node* current = q.front();
            q.pop();
            
            // Add current node's value to current level
            currentLevel.push_back(current->data);
            
            // Add children to queue for next level
            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }
        }
        
        // If even level, reverse the current level (right to left)
        if (!isOddLevel) {
            reverse(currentLevel.begin(), currentLevel.end());
        }
        
        // Add current level nodes to result
        for (int val : currentLevel) {
            result.push_back(val);
        }
        
        // Toggle level parity
        isOddLevel = !isOddLevel;
    }
    
    return result;
}