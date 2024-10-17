#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
        int data;
        node *left;
        node *right;

        node(int d ) {
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }
};

node *buildTree(node *root) {

    cout << "Enter the data : " << endl;
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
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {

        node *temp = q.front();
        q.pop();

        if(temp == NULL) {

            cout << endl;

            if(!q.empty()) {
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

void Inorder(node *root) {

    //base case
    if(root == NULL) {
        return;
    }

    //LNR
      //^ L -> Go to left
      //^ N -> Print
      //^ R -> Go to right

    //Recursive call
        Inorder(root -> left);
        cout << root -> data << " ";
        Inorder(root -> right);
    
}

void Preorder(node *root) {

    // base 
    if(root == NULL) {
        return;
    }

    //NLR
      //^ N -> Print
      //^ L -> Go to left
      //^ R -> Go to right

    //Recursive call
        cout << root -> data << " ";
        Preorder(root -> left);
        Preorder(root -> right);
}

void Postorder(node *root) {

    //base case
    if(root == NULL) {
        return;
    }

    //LRN
      //^ L -> Go to left
      //^ R -> Go to right
      //^ N -> Print

    //Recursive call
        Postorder(root -> left);
        Postorder(root -> right);
        cout << root -> data << " ";
}

int main() {

    node *root = NULL;

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    //creating a Tree
    root = buildTree(root);

    //level order
    levelOrderTraversal(root);

    //Inorder traversal
    cout << "Printing Inorder traversal : " ;
    Inorder(root);

    cout << endl;

    //Preorder traversal
    cout << "Printing Preorder traversal : " ;
    Preorder(root);

    cout << endl;

    //Postorder traversal
    cout << "Printing Postorder traversal : ";
    Postorder(root);

    cout << endl;

 return 0;
}