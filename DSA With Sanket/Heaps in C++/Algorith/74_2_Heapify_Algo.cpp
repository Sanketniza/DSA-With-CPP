
#include<iostream>
using namespace std;

class heapify {
    public:

    void heapifyAlgo(int arr[], int n, int i) {

        int largest = i; // Initialize largest as root , means i is the index of the root which is first element of the array
        int left = 2*i + 1; // left child of the root
        int right = 2*i + 2; // right child of the root

        if(left < n && arr[left] > arr[largest]) {
            // if left child is greater than the root && left child is in the range of the array
            largest = left;
        }

        if(right < n && arr[right] > arr[largest]) {
            // if right child is greater than the root && right child is in the range of the array
            largest = right;
        }

        if(largest != i) { // if largest is not the root
            swap(arr[i], arr[largest]); // swap the root with the largest   
            heapifyAlgo(arr, n, largest); // call the function recursively for the largest index to check if it is following the heap property or not
        }

    }

};

int main() {

    int arr[] = {-1 , 54, 53, 55, 52, 50};

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
    for(int i = n/2 - 1; i >= 0; i--) { // start from the last non-leaf node, because the leaf nodes are already heapified
        h.heapifyAlgo(arr, n, i); // call the heapify function for the non-leaf nodes
    }

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
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

 return 0;
}