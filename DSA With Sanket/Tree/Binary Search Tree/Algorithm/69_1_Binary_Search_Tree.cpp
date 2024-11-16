
#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int d ) {
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }

};

void PostOrder(Node *root) {

    if(root == NULL) {
        return;
    }    

    // LRN
    PostOrder(root -> left);
    PostOrder(root -> right);
    cout << root -> data << " " ;
}
void PreOrder(Node *root) {

    if(root == NULL) {
        return;
    }

    //NLR
    cout << root -> data << " ";
    PreOrder(root -> left);
    PreOrder(root -> right);
}
void InOrder(Node *root) {

    if(root == NULL) {
        return;
    }

    // LNR
    InOrder(root -> left);
    cout << root -> data << " ";
    InOrder(root -> right);
}

void levelOrderTraversal(Node *root) {

    queue<Node*> q;
    // cout << "root : " << root -> data << endl;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {

        Node *temp = q.front();
        // cout << "temp : " << temp -> data << endl;
        q.pop();

        if(temp == NULL) {
            //purana level complete traverse ho chuka hai
            cout << endl;
              if(!q.empty()) {
                //queue still has some child nodes
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

Node *InsertIntoBST (Node *root , int data) {

    if(root == NULL) {
        root = new Node(data) ;
        return root;
    }

    if(data > root -> data ) {
        // insert the data at right side 
        root -> right = InsertIntoBST(root -> right , data);
    }

    else {
        // insert the data at left side of root (parent node)
        root -> left = InsertIntoBST(root -> left , data);
    }

    return root;
}

void takeInput(Node *&root) {
    
    int data;
    cin >> data;

    while (data != -1) {

        root = InsertIntoBST(root , data);
        cin >> data;
    }
}

int main() {

    // creating an empty Node
    Node *root = NULL;

    cout << "Enter a data for binary search tree : " << endl;

    takeInput(root);

    // print the tree using levelOrder traversal , Inorder , Post Order and Pre Order Traversal Techniques
    cout << "Binary search tree data : " << endl;
    levelOrderTraversal(root);

    cout << "Inorder Traversal : " << endl; 
        InOrder(root);
        cout << endl;

    cout << "PreOrder Traversal : " << endl; 
        PreOrder(root);
        cout << endl;

    cout << "PostOrder Traversal : " << endl; 
        PostOrder(root);

 return 0;
}