#include<iostream>
#include<bits/stdc++.h>
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

Node *reverseBetween(Node *head, int left, int right) {
    
        if (!head || left == right) {
            return head;
        }

        Node* dummy = new Node(0);
        dummy->next = head;
        Node* prevLeft = dummy;
/* 
        dummy   head
          |      |
         [0] -> [10] -> [20] -> [30] -> [40] -> [50] -> NULL
          ^
        prevLeft
 */

        // Find the node before the left position
        for (int i = 1; i < left; i++) {
            prevLeft = prevLeft->next;
        }

/* 
        dummy  prevLeft
          |       |
         [0] -> [10] -> [20] -> [30] -> [40] -> [50] -> NULL
        
*/

        Node* curr = prevLeft->next;
        Node* prev = nullptr;
        Node* next = nullptr;

/* 
               prevLeft   curr
                  |        |
        [0] -> [10] -> [20] -> [30] -> [40] -> [50] -> NULL
        
*/

        // Reverse the sublist
        for (int i = left; i <= right; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

/* 
               prevLeft   prev    curr
                  |        |       |
        [0] -> [10]      [20]    [30] -> [40] -> [50] -> NULL
                            |
                           NULL

    --------------------------------------------------------                        
        
              prevLeft           prev    curr
                 |                |       |
        [0] -> [10]      [20] <- [30]    [40] -> [50] -> NULL
                           |
                          NULL
        
    ----------------------------------------------------------                      

               prevLeft                   prev    curr
                  |                        |       |
         [0] -> [10]      [20] <- [30] <- [40]    [50] -> NULL
                            |
                           NULL
                                              
*/

        // Connect the reversed sublist
        prevLeft->next->next = curr;
/* 
               prevLeft                   prev    curr
                  |                        |       |
         [0] -> [10]      [20] <- [30] <- [40]    [50] -> NULL
                            |                      ^
                            |______________________|
        
 */                   
        prevLeft->next = prev;

/* 
               prevLeft    |---------------------> prev
                  |        |                        |
         [0] -> [10]      [20] <- [30] <- [40]     [50] -> NULL
                           |                ^
                           |________________| (Logic: 20 points to 50)
        
 */
        return dummy->next;
/* 
        dummy
          |
         [0] -> [10] -> [40] -> [30] -> [20] -> [50] -> NULL
 */
        
} 

void print(Node* head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {

    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    print(head);

    Node *ans = reverseBetween(head, 2, 4);
    print(ans);
    
 return 0;
}