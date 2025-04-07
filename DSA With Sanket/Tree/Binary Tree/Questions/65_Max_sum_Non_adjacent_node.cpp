/* 
    ? lecture 65 : Maximum sum of Non-adjacent nodes
    ? link :- https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

    Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.
       

Example 1:

Input:
     11
            
   1    2
Output: 11
Explanation: The maximum sum is sum of
node 11.

Example 2:

Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
Output: 16
Explanation: The maximum sum is sum of
nodes 1 4 5 6 , i.e 16. These nodes are
non adjacent.
 */


#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;

         Node (int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL; 
        }

};

pair <int , int > solve (Node *root) {

    // base case
    if(root == NULL) {
        pair <int ,int> p = make_pair(0 ,0);
        return p;
    }

    pair<int , int > l = solve (root -> left);
    pair<int , int > r = solve (root -> right);

    pair <int , int> res;
    res.first = root -> data + l.second + r.second;
    res.second = max(l.first , l.second) + max(r.first , r.second);

    return res;

//         1
//        / \
//       2   3
//      /   / \
//     4   5   6
//    /
//   7

}

int getMaxSum(Node *root) {

    pair <int , int > a = solve (root);
    return max(a.first , a.second);
}

int main() {

    Node *root = new Node(1);
    root -> left = new Node (2);
    root -> right = new Node (3);
    root -> left -> left = new Node (4);
    root -> right -> left = new Node (5);
    root -> right -> right = new Node (6);
    root -> left -> left -> left = new Node (7);

    int ans = getMaxSum(root) ;
    cout << ans << endl;

 return 0;
}