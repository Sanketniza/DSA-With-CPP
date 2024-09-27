/*
 
 * lecture 50
 * link:-https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

  Palindrome Linked List
Difficulty: MediumAccuracy: 41.48%Submissions: 340K+Points: 4
Given a singly linked list of integers. The task is to check if the given linked list is palindrome or not.

Examples:

Input: LinkedList: 1->2->1->1->2->1
Output: true
Explanation: The given linked list is 1->2->1->1->2->1 , which is a palindrome and Hence, the output is true.

*/





#include<iostream>
#include<vector>
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

    while (i < j) {
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
    Node* fifth = new Node(10);

    one->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    Node* head = one;

    // create one vector and push all the data of the linked list in the vector

    vector<int> arr;
    Node* temp = head;

    while (temp != NULL) {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    if(isPalindrome(arr)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }
    
    
 return 0;
}