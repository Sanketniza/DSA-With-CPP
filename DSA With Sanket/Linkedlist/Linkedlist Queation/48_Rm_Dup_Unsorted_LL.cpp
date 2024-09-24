/* 
   !lecture 48: Remove Duplicates from Unsorted Linked List
   link : https://www.naukri.com/code360/problems/remove-duplicates-from-unsorted-linked-list_1069331?source=youtube&campaign=YouTube_Lovebabbar29thJan

   Q1: Remove Duplicates from Unsorted Linked List

   Q2: Remove Duplicates from Sorted Linked List

   Q3: Remove Duplicates from Circular Linked List

   Q4: Remove Duplicates from Doubly Linked List


? Remove Duplicates From an Unsorted Linked List
Moderate

Problem statement
   ^ You are given a linked list of N nodes. Your task is to remove the    ^ duplicate nodes from the linked list such that every element in the    ^ linked list occurs only once i.e. in case an element occurs more than    ^ once, only keep its first occurrence in the list.
   ^ 
   ^ For example :
   ^ Assuming the linked list is 3 -> 2 -> 3 -> 4 -> 2 -> 3 -> NULL.
   ^ 
   ^ Number ‘2’ and ‘3’ occurs more than once. Hence we remove the    ^ duplicates and keep only their first occurrence. So, our list becomes :    ^ 3 -> 2 -> 4 -> NULL.
   ^ Detailed explanation ( Input/output format, Notes, Images )
   ^ Constraints :
   ^ 1 <= T <= 100   
   ^ 1 <= N <= 10 ^ 4
   ^ 1 <= data <= 10 ^ 5 
   ^ 
   ^ Where ‘N’ is the number of nodes in the list and 'data' is the value of    ^ list nodes.
   ^ 
   ^ Time Limit: 1sec
   ^ Sample Input 1 :
   ^ 2
   ^ 4 2 5 4 2 2 -1
   ^ 1 2 1 2 2 2 7 7 -1
   ^ Sample Output 1 :
   ^ 4 2 5 -1
   ^ 1 2 7 -1
   ^ Explanation of Sample Input1 :
   ^ For the first test case, the linked list is 4 -> 2 -> 5 -> 4 -> 2 -> 2    ^ -> NULL. Number ‘4’ and ‘2’ occurs more than once. Hence, we remove the    ^ duplicates and keep only their first occurrence. So, our list becomes :    ^ 4 -> 2 -> 5 -> NULL.
   ^ 
   ^ For the second test case, the linked list is 1 -> 2 -> 1 -> 2 -> 2 -> 2    ^ -> 7 -> 7 -> NULL. Number ‘1’, ‘2’ and ‘7’ occurs more than once.    ^ Hence, we remove the duplicates and keep only their first occurrence.    ^ So, our list becomes : 1 -> 2 -> 7 -> NULL.
   ^ Sample Input 2 :
   ^ 2
   ^ 3 3 3 3 3 -1
   ^ 10 20 10 20 30 10 20 30 -1
   ^ Sample Output 2 :
   ^ 3 -1
   ^ 10 20 30 -1



 */



#include<iostream>
#include<map>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// todo: first approach --> using two pointer and hashmap
void removeDuplicates(Node* &head) {

    if(head == NULL) {
        return;
    }

    Node* curr = head;

    while (curr != NULL) {

        Node* temp = curr -> next;
        Node* prev = curr; // Add this line

        while (temp != NULL) {

            if (curr -> data == temp -> data) {

                Node* nodeToDelete = temp;
                temp = temp -> next;
                prev -> next = temp; // Change this line
                delete(nodeToDelete);

            } else {

                prev = temp; // Add this line
                temp = temp -> next;
            }
            
        }

             curr = curr -> next;
    }
}

// todo: second approach --> using sort LL and then remove duplicates

void SortRemoveDuplicates(Node* &head) {
 
 cout << "check how to sort the LL" << endl;
}

// todo: third approach -> using map
void MapRemoveDuplicates(Node* &head) {

    cout << "check how to remove duplicates using map" << endl;

    map<int, bool> visited;

    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {

        if(visited[curr->data] == true) {
            Node* nodeToDelete = curr;
            curr = curr->next;
            prev->next = curr;
            delete(nodeToDelete);
        } 
        else {
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    } 
}

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << "  ->  ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {

    Node* head = new Node(10);
    Node* second = new Node(60);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(10);
    Node* sixth = new Node(60);
    Node* seventh = new Node(30);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = NULL;

    cout << "original LL" << endl;
    print(head);
    cout << "----------------------------------------" << endl;

// todo: first approach -> using two pointer and hashmap
    removeDuplicates(head);
    print(head);
    cout << "----------------------------------------" << endl;

// todo: second approach -> sort the LL and then remove duplicates
    SortRemoveDuplicates(head);
    // print(head);
    cout << "----------------------------------------" << endl;

// todo: third approach -> using map
    MapRemoveDuplicates(head);
    print(head);
    cout << "----------------------------------------" << endl;


 return 0;
}