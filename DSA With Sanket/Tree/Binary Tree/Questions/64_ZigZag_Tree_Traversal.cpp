/* 
    Topic :- Tree
    Subtopic :- ZigZag Tree Traversal
    Difficulty :- Medium
    ? ilnk : https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1
    Question Link :- https://www.codingninjas.com/studio/problems/zigzag-tree-traversal_920534?leftPanelTab=0

    Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.
    In zig zag traversal starting from the first level go from left to right for odd-numbered levels and right to left for even-numbered levels.

    Example 1:

    Input:
            1
          /   \
         2    3
        / \    /   \
       4   5 6   7
    Output:
    1 3 2 4 5 6 7
    Explanation:
    For level 1 going left to right, we get traversal as {1}.
    For level 2 going right to left, we get traversal as {3,2}.
    For level 3 going left to right, we get traversal as {4,5,6,7}.
    Merging all this traversals in single array we get {1,3,2,4,5,6,7}

 */

#include<iostream>
#include<queue>
#include<vector>
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

vector<int> zigZagTreeTraversal(Node *root) {

    vector<int> result;

    if(root == NULL) {
        return result;
    }

    queue<Node *> q;
    q.push(root);
    cout << "Queue is : ";
    

    bool leftToRight = true;

    while (!q.empty()) {

        cout << "Inside While Loop" << endl;

        int size = q.size();
        cout << "Size is : " << size << endl;
        vector<int> ans(size);

        for(int i = 0; i < size; i++) {
            cout << "i is : " << i << endl;
            cout << "size is : " << size << endl;

            Node *frontNode = q.front();
            cout << "Front Node is : " << frontNode -> data << endl;

            q.pop();
            cout << "After Popping Front Node is : " << q.front() << endl;

            cout << "Left to Right is : " << leftToRight << endl;
            int index = leftToRight ? i : size - i - 1;
            cout << "Index is : " << index << endl;
            ans[index] = frontNode -> data;
            cout << "Pushing in ans is---> : " << ans[index] << endl;

            if(frontNode -> left) {
                q.push(frontNode -> left);
                cout << "Pushing Left Node into to q is  : " << frontNode -> left -> data << endl;
            }

            if(frontNode -> right) {
                q.push(frontNode -> right);
                cout << "Pushing Right Node into to q is : " << frontNode -> right -> data << endl;
            }
        }

        cout << "-----------------------------------" << endl;

        leftToRight = !leftToRight;
        cout << "Left to Right is : " << leftToRight << endl;

        for(auto i : ans) {
            result.push_back(i);
            cout << "Pushing in Result is : " << i << endl;
        }

        cout << "-----------------------------------" << endl;
    }

    // cout << "Result is : ";
    // for(int i = 0; i < result.size(); i++) {
    //     cout << result[i] << " ";
    // }

    return result;
}

int main() {

    Node *root = new Node(1);
    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right = new Node(3);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    vector<int> ans = zigZagTreeTraversal(root);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

 return 0;
}