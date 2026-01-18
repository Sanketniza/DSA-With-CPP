#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }

};

Node *MinVal(Node *root) {
    Node *temp = root;
    while(temp -> left != NULL) {
        temp = temp -> left;
    }
    return temp;
}

Node *deleteNode(Node *root, int val) {

    // base case
    if(root == NULL) {
        return NULL;
    }

    if(root -> data == val) {

        // 0 child
            if(root -> left == NULL && root -> right == NULL) {
                delete root;
                return NULL;
            }  

        // 1 child present

            //? if left node is present
                if(root -> left != NULL && root -> right == NULL) {
                    Node *temp = root -> left;
                    delete root;
                    return temp;
                }

            //? if right node is present
                if(root -> left == NULL && root -> right != NULL) {
                    Node *temp = root -> right;
                    delete root;
                    return temp;
                }


        // 2 child present
            if(root -> left != NULL && root -> right != NULL) {
                int mini = MinVal(root -> right) -> data;
                root -> data = mini;
                root -> right = deleteNode(root -> right , mini);
                return root;
            }
    }

    else if( root -> data > val) {
        // visit left subpart of tree
        root -> left = deleteNode(root ->left , val);
        return root;
    }

    else {
        // visit right subpart of tree
        root -> right = deleteNode(root -> right , val);
        return root;
    }

}
    
void levelOrderTraversal(Node *root) {

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {

        Node *temp = q.front();
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

void Inorder(Node *root) {

    // base case 
    if(root == NULL) {
        return;
    }

    // LNR
    Inorder(root -> left);
    cout << root -> data << " ";
    Inorder(root -> right);
}

void PreOrder(Node *root) {

    // base case 
    if(root == NULL) {
        return;
    }

    // NLR
    cout << root -> data << " ";
    PreOrder(root -> left);
    PreOrder(root -> right);
}

void PostOrder(Node *root) {

    // base case 
    if(root == NULL) {
        return;
    }

    // LRN
    PostOrder(root -> left);
    PostOrder(root -> right);
    cout << root -> data << " ";
}

int main() {

    Node *root = new Node(4);
    root -> left = new Node(2);
    root -> right = new Node(6);
    root -> left -> left = new Node(1);
    root -> left -> right = new Node(3);
    root -> right -> left = new Node(5);
    root -> right -> right = new Node(7);

    // print the tree

    //^ Level Order Traversal
    cout << "Level Order Traversal : " << endl;
    levelOrderTraversal(root); cout << endl;

    //^ Inorder Traversal
    cout << "Inorder Traversal : " ;
    Inorder(root); cout << endl;

    //^ Preorder Traversal
    cout << "PreOrder Traversal : " ;
    PreOrder(root) ; cout << endl;

    //^ Postorder Traversal
    cout << "PostOrder Traversal : " ;
    PostOrder(root) ; cout << endl;

    // Delete a Node in BST

    root = deleteNode(root, 3);

    //^ After Deletion Level Order Traversal
    cout << "After Deletion Level Order Traversal : " << endl;
    levelOrderTraversal(root); cout << endl;

    //^ After Deletion Inorder Traversal
    cout << "After Deletion Inorder Traversal : " ;
    Inorder(root); cout << endl;

    //^ After Deletion Preorder Traversal
    cout << "After Deletion Preorder Traversal : " ;
    PreOrder(root) ; cout << endl;

    //^ After Deletion Postorder Traversal
    cout << "After Deletion Postorder Traversal : " ;
    PostOrder(root) ; cout << endl;

    root = deleteNode(root, 7);
    cout << "After Deletion Level Order Traversal : " << endl;
    levelOrderTraversal(root); cout << endl;


 return 0;
}