#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node() {
        this->data = 0;
        next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

#include <queue>

class compare {
public:
    bool operator()(Node *a, Node *b) {
        return a->data > b->data;
    }
};

Node* mergeKLists(vector<Node*> &listArray) {
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    int k = listArray.size();

    if (k == 0)
        return NULL;

    // Step 1: Push the first node of each list into the min heap
    for (int i = 0; i < k; i++) {
        if (listArray[i] != NULL) {
            minHeap.push(listArray[i]);
        }
    }

    Node *head = NULL;
    Node *tail = NULL;

    while (!minHeap.empty()) {
        Node *top = minHeap.top();
        minHeap.pop();

        if (top->next != NULL) {
            minHeap.push(top->next);
        }

        if (head == NULL) {
            head = top;
            tail = top;
        } else {
            tail->next = top;
            tail = top;
        }
    }

    return head;
}

int main() {
    Node *list1 = new Node(1, new Node(4, new Node(5)));
    Node *list2 = new Node(1, new Node(3, new Node(4)));
    Node *list3 = new Node(2, new Node(6));

    vector<Node*> listArray = {list1, list2, list3};

    Node *mergedHead = mergeKLists(listArray);

    Node *temp = mergedHead;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}