/* 
    ? lecture 62 > diameter of binary tree
    ? link : https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1

    ^ The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes). 

        Example 1:

        Input:
               1
             /  \
            2    3
        Output: 3
        Example 2:

        Input:
                 10
                /   \
              20    30
            /   \ 
           40   60
        Output: 4

 */

 //! First Approach with TIme Complexicity O(n * n)
 //! second Approach with TIme Complexicity O(n)

/* 
 //^ First Approach with TIme Complexicity O(n * n)
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

int height(Node *root) {

    // it mejor the height of tree
    // base case
        if(root == NULL) {
            return 0;
        }

        // recursive call

        int left = height (root -> left);
        int right = height (root -> right );

        int ans = max(left , right) + 1;

        return ans;
}
 

int diameter(Node *root) {

    // base case 
    if(root == NULL) {
        return 0;
    }

    // recursive call

    int op1 = diameter(root -> left);
    int op2 = diameter(root -> right);
    int op3 = height(root -> left ) + height(root -> right ) + 1;
    
    int ans = max(op1 , max(op2 , op3));
    return ans;
}


 int main() {
 
    Node *root = new Node(1);

    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    root -> right = new Node(3);
    root -> right -> left = new Node(6);
    root -> right -> left -> left = new Node(8);
    root -> right -> left -> right = new Node(9);

    root -> right -> right = new Node(7);
    root -> right -> right -> left = new Node(10);
    root -> right -> right -> right = new Node(11);

    cout << "Diameter of binary tree is : " << diameter(root) << endl; 


  return 0;
} 
*/

 //^ second Approach with TIme Complexicity O(n)

 #include<iostream>
 using namespace std;
 
 class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node (int data ) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }

};

pair<int , int> diameterFast(Node *root) {

    // base case
    if(root == NULL) {
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int , int> left = diameterFast(root -> left);
    pair<int ,int> right = diameterFast(root -> right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int , int> ans;
     
     ans.first = max(op1 , max(op2 , op3));
     ans.second = max(left.second , right.second) + 1;

     return ans;
    
    
}
 
 int main() {
 
    Node *root = new Node(1);

    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    root -> right = new Node(3);
    root -> right -> left = new Node(6);
    root -> right -> left -> left = new Node(8);
    root -> right -> left -> right = new Node(9);

    root -> right -> right = new Node(7);
    root -> right -> right -> left = new Node(10);
    root -> right -> right -> right = new Node(11);

    cout << "Diameter of binary tree is : " << diameterFast(root).first << endl; 
 
  return 0;
}