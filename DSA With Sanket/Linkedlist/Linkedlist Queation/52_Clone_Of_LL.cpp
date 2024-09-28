/* 
    Clone a linked list with random pointer
    link- 

    Approach:   
    1. Create a map to store the mapping of original nodes to their corresponding cloned nodes.
    2. Traverse the original linked list and create a new node for each original node.
    3. Set the next and random pointers for the cloned nodes using the map.
    4. Return the head of the cloned linked list.

    TC - O(N)
    SC - O(N)

    Note: This approach assumes that the random pointer points to a node in the original linked list.
    If the random pointer points to a node outside the original linked list, the approach will not work.

    Edge Case:
    If the linked list is empty, return NULL.
    If the linked list has only one node, return the same node as the cloned node.

    Example:
    Input: 1 -> 2 -> 3 -> 4 -> 5
    Output: 1 -> 2 -> 3 -> 4 -> 5

    Input: 1 -> 2 -> 3 -> 4 -> 5
    Output: 1 -> 2 -> 3 -> 4 -> 5

    Input: 1 -> 2 -> 3 -> 4 -> 5
    Output: 1 -> 2 -> 3 -> 4 -> 5

    Input: 1 -> 2 -> 3 -> 4 -> 5
    Output: 1 -> 2 -> 3 -> 4 -> 5


*/

#include<iostream>
using namespace std;

class  Node{
    public:
    int data;
    Node* next;
    Node* random;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }

};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
}



int main() {

    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    print(head);


 return 0;
}