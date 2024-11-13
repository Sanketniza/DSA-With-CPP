#include<iostream>
using namespace std;

class node {
    public:

        int data;
        node *left;
        node *right;

        node (int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

int height(node *root) {

    if(root == NULL) {
        return 0;
    }

    int l = height(root -> left);
    int r = height(root -> right);

    int ans = max(l , r) + 1;

    return ans;
}

bool BalanceHeight(node *root ) {

    if(root == NULL) {
        return true;
    }

    bool l = BalanceHeight(root -> left  );
    bool r = BalanceHeight(root -> right );
    bool d = abs (height (root -> left ) - height (root -> right)) <= 1;

    if(l && r && d) {
        return 1;
    }

    else {
        return 0;
    }


}

int main() {

    node *root = new node(1);
    root -> left = new node(2);
    root -> right = new node(3);
    root -> left -> left = new node(4);
    root -> left -> left -> left = new node(4);
    root -> left -> left -> left -> left = new node(4);
    root -> left -> right = new node(5);
    // root -> right -> left = new node(6);
    // root -> right -> right = new node(7);

    if(BalanceHeight) {
        cout << "true" << endl;
    }

    else {
        cout << "false" << endl;
    }

 return 0;
}