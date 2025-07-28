#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class heap {
    public:

    void minHeap(int arr[], int n, int i) {
        
        int parent = i;
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;

        if(leftIndex < n && arr[parent] > arr[leftIndex]) {
            parent = leftIndex;
        }

        if(rightIndex < n && arr[parent] > arr[rightIndex]) {
            parent = rightIndex;
        }

        if(parent != i) {
            swap(arr[parent], arr[i]);
            minHeap(arr, n, parent);
        }
    }

};

int main() {

    int arr[] = {3,5,11,61,4,42,13,6,14};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Orinal array: " << endl;

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    heap h;

    for(int i = n/2 - 1; i >= 0; i--) {
        h.minHeap(arr, n, i);
    }

    cout << "Min Heap: " << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


 return 0;
}