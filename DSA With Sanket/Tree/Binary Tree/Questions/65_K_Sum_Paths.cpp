/*

? K Sum Paths
? https://www.geeksforgeeks.org/problems/k-sum-paths/1


Given a binary tree and an integer k, the task is to count the number of paths in the tree such that the sum of the nodes in each path equals k. A path can start from any node and end at any node and must be downward only.

Examples:

Input: Tree =  1  k = 3                               
             /   \                          
           2     3
Output: 2
Explanation:
Path 1 : 1 + 2 = 3
Path 2 : only leaf node 3

Input: Tree = 8  k = 7  
            /   \
          4      5
         /   \       \
       3     2       2                        
      /   \     \                    
    3    -2    1       
Output: 3
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Define the structure for a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};


void solve (Node *root , int k , vector<int> path , int &count) {
      
         if(root == NULL) {
           return;
        }
      
      path.push_back(root -> data);
      
      solve(root -> left , k , path , count);
      solve(root -> right , k , path , count);
      
      int s = path.size();
      int sum = 0;
      
      for(int i = s - 1; i>= 0; i--) {
          sum += path[i];
          if(sum == k) {
               count++;
          }
      }
      
      path.pop_back();
}



int main() {
    // Example usage:

    Node *root = new Node(8);
    root -> left = new Node(4);
    root -> right = new Node(5);
    root -> left -> left = new Node(3);
    root -> left -> right = new Node(2);
    root -> left -> left -> left = new Node(3);
    root -> left -> left -> right = new Node(-2);
    root -> right -> right = new Node(2);

    int k = 3;
    int count = 0;

     vector<int> ans ;
    solve (root , k  , ans , count);

    cout << "Count is : " << count << endl;

  
    return 0;
}
