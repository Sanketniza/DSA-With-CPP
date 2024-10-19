#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
        int data;
        node *left;
        node *right;

        node (int d) {
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }

};

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

void CreateBtLevelOrder(node* &root) {

    queue<node *> q;
    cout << "Enter the data for root : " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty()) {

        node *temp = q.front();
        q.pop();

        cout << "Enter the left node for : " << temp -> data << endl;
        int leftData;
        cin >> leftData;

            if(leftData != -1) {
                temp -> left = new node(leftData);
                q.push(temp -> left);
            }

        cout << "Enter the right node for :" << temp -> data << endl;
        int rightData;
        cin >> rightData;

            if(rightData != -1) {
                temp -> right = new node (rightData);
                q.push(temp -> right);
            }
    }
}

int main() {

    node *root = NULL;

    //creating a Tree
    CreateBtLevelOrder(root);

    // printing the tree
    cout << "Printing the tree : " << endl;
    levelOrderTraversal(root);

 return 0;
}