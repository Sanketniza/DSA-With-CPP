
#include<iostream>
using namespace std;

class  bst{
    public:
        int data;
        bst *left;
        bst *right;

        bst(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

pair<int , int> predecessorAndSuccessor(bst *root , int key){

    // key is present in the tree
    bst *temp = root;
    int pred = -1;
    int succ = -1;

    while(temp -> data != key) {

       if(temp -> data > key) {
            succ = temp -> data;
            temp = temp -> left;
        }

        else {
            pred = temp -> data;
            temp = temp -> right;
        }

    }

    bst *leftT = temp -> left;
       while (leftT != NULL) {
            pred = leftT -> data;
            leftT = leftT -> right;
        }

    bst *rightT = temp -> right;
        while (rightT != NULL) {
            succ = rightT -> data;
            rightT = rightT -> left;
        }


    return {pred , succ};
}

int main() {


    bst *root = new bst(15);
    root -> left = new bst(10);
    root -> right = new bst(20);
    root -> left -> left = new bst(8);
    root -> left -> right = new bst(12);
    root -> right -> left = new bst(16);
    root -> right -> right = new bst(25);

    int key = 10;

    pair<int , int> ans = predecessorAndSuccessor(root , key);
    cout << ans.first << " " << ans.second << endl;

 return 0;
}