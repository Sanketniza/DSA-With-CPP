/*
    ? lecture : 47
    ? link :-https://www.naukri.com/code360/problems/interview-shuriken-42-detect-and-remove-loop_241049?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_codestudio_lovebabbar28thjan
 

    ! Detect and Remove Loop in Linkedlist

    Approach 1: Using Hashmap
    Approach 2: Using Floyd's Cycle Detection
    Approach 3: Using Modification of Linkedlist
    Approach 4: Using Visited Node
    Approach 5: Using Finding the Start Point of the Loop

    ^     Problem statement
    ^ Given a singly linked list, you have to detect the loop and remove the loop from the linked list, if present. You have to make changes in the given linked list itself and return the updated linked list.
    ^
    ^ Expected Complexity: Try doing it in O(n) time complexity and O(1) space complexity. Here, n is the number of nodes in the linked list.
    ^
   

    ^ Sample Input:
    ^ 6 2
    ^ 1 2 3 4 5 6
    ^ Sample Output:
    ^ 1 2 3 4 5 6
    ^ Explanation:
    ^ For the given input linked list, the last node is connected to the second node as:
    
 */


//~ Time Complexity: O(N)
//~ Space Complexity: O(1)

#include <iostream>
#include <map>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


// todo: Approach 2: Using Floyd's Cycle Detection

Node *FloydCycleDetection(Node *head) {
//? Node *xyz(){} -> you can not return the bool [true/false] value.YOu all way return node (address of node)

    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {

        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;

        if (slow == fast)
        {
            cout << "Loop is present at " << slow->data << endl;
            return slow;
        }
    }

    return NULL;
}


//todo: find starting node of LL 

Node *startingNode(Node *head) {

    if (head == NULL) {
        return NULL;
    }

    Node *intersection = FloydCycleDetection(head);

    Node *slow = head;

    while (slow != intersection) {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
    
}

// todo: Approach 1: Using Hashmap

bool detectLoop(Node *head)
{

    Node *temp = head;

    if (head == NULL)
    {
        return false;
    }

    map<Node *, bool> visited;

    while (temp != NULL)
    {

        if (visited[temp] == true)
        {
            cout << "Loop is present at " << temp->data << endl;
            return true;
        }

        visited[temp] = true; //* Mark the current node as visited -> This is the main logic of the approach -> true mark
        temp = temp -> next;
    }

    return false;
}


// todo: remove loop

void removeLoop(Node *head) {

    if (head == NULL) {
        return;
    }

    Node *startOfLoop = startingNode(head);
    // cout << "sanket " << startOfLoop -> data << endl;
    Node *temp = startOfLoop;

    while (temp -> next != startOfLoop) {
        temp = temp->next;
    }

    temp->next = NULL;
}

// todo: print LL

void printLL(Node *head) {

    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);
    Node *sixth = new Node(6);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = second; // Creating a loop

    /* 
       1 -> 2 -> 3 -> 4 -> 5 -> 6
            ^                   !
            |                   !
            |___________________!
     */

    // Q Detect and Remove Loop

    // todo: Approach 1: Using Hashmap

    if (detectLoop(head)) {
        cout << "Loop is present" << endl;
    }

    else {
        cout << "Loop is not present" << endl;
    }

    cout << "----------------------------------------" << endl;

    // todo: Approach 2: Using Floyd's Cycle Detection

    if (FloydCycleDetection(head)) {
        cout << "Loop is present" << endl;
    }

    else {
        cout << "Loop is not present" << endl;
    }

    cout << "----------------------------------------" << endl;

    //todo: find starting node of LL 

    Node *startNode = startingNode(head);
    cout << "Starting node of the loop is " << startNode->data << endl;

    cout << "----------------------------------------" << endl;


    //todo: remove loop

    removeLoop(head);
    printLL(head);

    cout << "----------------------------------------" << endl;

    return 0;
}
