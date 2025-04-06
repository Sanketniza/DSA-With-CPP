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

void findPath(Node *root , int k , int &count , vector<int> &ans) {
    
    if(root == NULL) {
        return;
    }

    ans.push_back(root -> data);

    findPath(root -> left , k , count , ans);
    findPath(root -> right , k , count , ans);

    int sum = 0;
    for(int i = ans.size() - 1 ; i >= 0 ; i--) {
        sum += ans[i];
        if(sum == k) {
            count++;
        } 
    }

    ans.pop_back();
}

int main() {
    Node *root = new Node(1);
    
    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    
    root -> right = new Node(3);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    int k = 7;
    int count = 0;
    vector<int> ans;

    findPath(root , k , count , ans);

    cout << "Count of paths with sum " << k << " is: " << count << endl;
    
    return 0;
}

/* 

        'll dry run the program line by line to help you understand how it works. The program is designed to count the number of paths in a binary tree that sum up to a given value k.

        First, I notice there's a small error in the code. The function is defined as findPath() but called as pathfind() in the main() function. Let's assume it should be findPath() for our dry run.

        Dry Run
        Program starts execution from main()
        Create the binary tree:
            1
            / \
        2   3
        / \ / \
        4  5 6  7

        Copy

        Insert

        Initialize variables:
        k = 7 (target sum)
        count = 0 (counter for paths with sum k)
        ans (empty vector to track current path)
        Call findPath(root, k, count, ans)

        Enter findPath() with root = Node(1), k = 7, count = 0, ans = []
        Check if root is NULL: No, continue
        Push root->data (1) to ans: ans = [1]
        Recursively call findPath(root->left, k, count, ans)

        Enter findPath() with root = Node(2), k = 7, count = 0, ans = [1]
        Check if root is NULL: No, continue
        Push root->data (2) to ans: ans = [1, 2]
        Recursively call findPath(root->left, k, count, ans)

        Enter findPath() with root = Node(4), k = 7, count = 0, ans = [1, 2]
        Check if root is NULL: No, continue
        Push root->data (4) to ans: ans = [1, 2, 4]
        Recursively call findPath(root->left, k, count, ans)

        Enter findPath() with root = NULL, k = 7, count = 0, ans = [1, 2, 4]
        Check if root is NULL: Yes, return to previous call

        Back to findPath() with root = Node(4), continue after recursive call
        Recursively call findPath(root->right, k, count, ans)

        Enter findPath() with root = NULL, k = 7, count = 0, ans = [1, 2, 4]
        Check if root is NULL: Yes, return to previous call

        Back to findPath() with root = Node(4), continue after recursive calls
        Calculate sum from the end of ans:
        i = 2: sum = 4, 4 != 7
        i = 1: sum = 4 + 2 = 6, 6 != 7
        i = 0: sum = 6 + 1 = 7, 7 == 7, increment count to 1
        Pop back from ans: ans = [1, 2]
        Return to previous call

        Back to findPath() with root = Node(2), continue after first recursive call
        Recursively call findPath(root->right, k, count, ans)
        Enter findPath() with root = Node(5), k = 7, count = 1, ans = [1, 2]
        
        Check if root is NULL: No, continue
        Push root->data (5) to ans: ans = [1, 2, 5]
        Recursively call findPath(root->left, k, count, ans)

        Enter findPath() with root = NULL, k = 7, count = 1, ans = [1, 2, 5]
        Check if root is NULL: Yes, return to previous call

        Back to findPath() with root = Node(5), continue after first recursive call
        Recursively call findPath(root->right, k, count, ans)
        Enter findPath() with root = NULL, k = 7, count = 1, ans = [1, 2, 5]
        Check if root is NULL: Yes, return to previous call

        Back to findPath() with root = Node(5), continue after recursive calls
        Calculate sum from the end of ans:
        i = 2: sum = 5, 5 != 7
        i = 1: sum = 5 + 2 = 7, 7 == 7, increment count to 2
        i = 0: sum = 7 + 1 = 8, 8 != 7
        Pop back from ans: ans = [1, 2]
        Return to previous call
        Back to findPath() with root = Node(2), continue after recursive calls
        Calculate sum from the end of ans:
        i = 1: sum = 2, 2 != 7
        i = 0: sum = 2 + 1 = 3, 3 != 7
        Pop back from ans: ans = [1]
        Return to previous call

        Back to findPath() with root = Node(1), continue after first recursive call
        Recursively call findPath(root->right, k, count, ans)

        Enter findPath() with root = Node(3), k = 7, count = 2, ans = [1]
        Check if root is NULL: No, continue
        Push root->data (3) to ans: ans = [1, 3]
        Recursively call findPath(root->left, k, count, ans)

        Enter findPath() with root = Node(6), k = 7, count = 2, ans = [1, 3]
        Check if root is NULL: No, continue
        Push root->data (6) to ans: ans = [1, 3, 6]
        Recursively call findPath(root->left, k, count, ans)

        Enter findPath() with root = NULL, k = 7, count = 2, ans = [1, 3, 6]
        Check if root is NULL: Yes, return to previous call

        Back to findPath() with root = Node(6), continue after first recursive call
        Recursively call findPath(root->right, k, count, ans)

        Enter findPath() with root = NULL, k = 7, count = 2, ans = [1, 3, 6]
        Check if root is NULL: Yes, return to previous call

        Back to findPath() with root = Node(6), continue after recursive calls
        Calculate sum from the end of ans:
        i = 2: sum = 6, 6 != 7
        i = 1: sum = 6 + 3 = 9, 9 != 7
        i = 0: sum = 9 + 1 = 10, 10 != 7
        Pop back from ans: ans = [1, 3]
        Return to previous call

        Back to findPath() with root = Node(3), continue after first recursive call
        Recursively call findPath(root->right, k, count, ans)

        Enter findPath() with root = Node(7), k = 7, count = 2, ans = [1, 3]
        Check if root is NULL: No, continue
        Push root->data (7) to ans: ans = [1, 3, 7]
        Recursively call findPath(root->left, k, count, ans)

        Enter findPath() with root = NULL, k = 7, count = 2, ans = [1, 3, 7]
        Check if root is NULL: Yes, return to previous call

        Back to findPath() with root = Node(7), continue after first recursive call
        Recursively call findPath(root->right, k, count, ans)

        Enter findPath() with root = NULL, k = 7, count = 2, ans = [1, 3, 7]
        Check if root is NULL: Yes, return to previous call

        Back to findPath() with root = Node(7), continue after recursive calls
        Calculate sum from the end of ans:
        i = 2: sum = 7, 7 == 7, increment count to 3
        i = 1: sum = 7 + 3 = 10, 10 != 7
        i = 0: sum = 10 + 1 = 11, 11 != 7
        Pop back from ans: ans = [1, 3]
        Return to previous call
        Back to findPath() with root = Node(3), continue after recursive calls
        Calculate sum from the end of ans:
        i = 1: sum = 3, 3 != 7
        i = 0: sum = 3 + 1 = 4, 4 != 7
        Pop back from ans: ans = [1]
        Return to previous call
        Back to findPath() with root = Node(1), continue after recursive calls
        Calculate sum from the end of ans:
        i = 0: sum = 1, 1 != 7
        Pop back from ans: ans = []
        Return to main()
        Back to main(), print the result:
        Output: "Count of paths with sum 7 is: 3"
        Paths with sum 7:
        1 → 2 → 4 (1+2+4 = 7)
        2 → 5 (2+5 = 7)
        7 (7 = 7)
        The algorithm works by:

        Traversing the tree in a depth-first manner
        Keeping track of the current path in the ans vector
        At each node, checking if any suffix of the current path sums to k
        Incrementing count for each valid path found
        Note: There's a bug in the original code where the function is called as pathfind() instead of findPath(). This would cause a compilation error in a real execution.

 */