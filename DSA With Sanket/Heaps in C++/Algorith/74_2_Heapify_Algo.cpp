
#include<iostream>
using namespace std;

/* 
    Heapify is the process of converting a binary tree into a heap data structure.
    It is used to create a Max-Heap or Min-Heap from an array.

    ? In a Max-Heap, the parent node is always greater than its child nodes.
    ? In a Min-Heap, the parent node is always smaller than its child nodes.

    Heapify is used to create a heap from an array.
    Heapify is used to maintain the heap property of the heap.

    todo: time complexity of heapify is = O(log n)
    todo: space complexity of heapify is = O(1)
    where n is the number of elements in the heap.

 */

class heapify {

    public:

    void heapifyAlgo(int arr[], int n, int i) {

        int largest = i; // Initialize largest as root , means i is the index of the root which is first element of the array
        int left = 2*i ; // left child of the root, if index is starting from 0 then left child is 2*i + 1 ,if index is starting from 1 then left child is 2*i
        int right = 2*i + 1; // right child of the root, if index is starting from 0 then right child is 2*i + 2 ,if index is starting from 1 then right child is 2*i + 1
        cout << "parent is :" << largest << " " << arr[largest] << endl;
        cout << "left is :" << left << " " << arr[left] << endl;
        cout << "right is :" << right << " " << arr[right] << endl;

        if(left <= n && arr[left] > arr[largest]) {
            // if left child is greater than the root && left child is in the range of the array
            largest = left;
        }

        if(right <= n && arr[right] > arr[largest]) {
            // if right child is greater than the root && right child is in the range of the array
            largest = right;
        }

        if(largest != i) { // if largest is not the root
            swap(arr[largest], arr[i]); // swap the root with the largest   
            heapifyAlgo(arr, n, largest); // call the function recursively for the largest index to check if it is following the heap property or not
        }

    }

};

int main() {

    int arr[] = {-1 , 54, 53, 55, 52, 50};
    cout << "size of the array is : " << sizeof(arr)/sizeof(arr[0]) << endl;

    /* 
        -1 is used to make the calculations easier, it is not part of the array

        tree representation of the array is :

                54
               /  \
              53   55
             /  \
            52   50
     */
    int n = 5; // size of the array

    heapify h;
    for(int i = n/2; i > 0; i--) { // start from the last non-leaf node, because the leaf nodes are already heapified
        cout << "i is : " << i << endl;
        h.heapifyAlgo(arr, n, i); // call the heapify function for the non-leaf nodes
    }

    /* 
       ? for (int i = n/2 - 1; i >= 0; i--) {
       ?     h.heapifyAlgo(arr, n, i);
       ? }

       ? then :
       ? int left = 2*i + 1;
       ? int right = 2*i + 2;

        ? if(left < n && arr[left] > arr[largest])  // indexing is starting from 0

        ? if(right < n && arr[right] > arr[largest]) // indexing is starting from 0
    
     */

    /* 
        tree representation of the array after heapify is :

                55
               /  \
              53   54
             /  \
           52   50

           array representation of the tree is :
           -1, 55, 53, 54, 52, 50
     */

    cout << "Printing the array after heapify" << endl;
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

 return 0;
}