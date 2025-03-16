#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

bool isPalindrome(vector<int> arr) {

   int i = 0;
   int j = arr.size() - 1;

   while (i < j){

        if(arr[i] != arr[j]) {
            return false;
        }

        i++;
        j--;
    }    

    return true;
}

int main() {

    Node* one = new Node(10);
    Node* second = new Node(200);
    Node* third = new Node(300);
    Node* fourth = new Node(200);
    Node* fifth = new Node(100);

    one->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    Node* head = one;

    // create one vector and push all the data of the linked list in the vector

    vector<int> v;
    Node *temp = head;

    while (temp != NULL) {
        v.push_back(temp -> data);
        temp = temp -> next;
    }
    

    if(isPalindrome(v)) {
        cout << "Yes, it is a palindrome" << endl;
    }
    else {
        cout << "No, it is not a palindrome" << endl;
    }


 return 0;
}