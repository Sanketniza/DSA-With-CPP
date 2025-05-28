
#include<iostream>
using namespace std;


class heapify {

    public:

    void heapifyAlgo(int arr[], int n, int i) {

        int parent = i; // Initialize parent as root , means i is the index of the root which is first element of the array
        int left = 2*i ; // left child of the root, if index is starting from 0 then left child is 2*i + 1 ,if index is starting from 1 then left child is 2*i
        int right = 2*i + 1; // right child of the root, if index is starting from 0 then right child is 2*i + 2 ,if index is starting from 1 then right child is 2*i + 1
        cout << "parent is :" << parent << " " << arr[parent] << endl;
        cout << "left is :" << left << " " << arr[left] << endl;
        cout << "right is :" << right << " " << arr[right] << endl;

        if(left <= n && arr[left] > arr[parent]) {
            // if left child is greater than the root && left child is in the range of the array
            parent = left;
        }

        if(right <= n && arr[right] > arr[parent]) {
            // if right child is greater than the root && right child is in the range of the array
            parent = right;
        }

        if(parent != i) { // if parent is not the root
            swap(arr[parent], arr[i]); // swap the root with the parent   
            heapifyAlgo(arr, n, parent); // call the function recursively for the parent index to check if it is following the heap property or not
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

  

    cout << "Printing the array after heapify" << endl;
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

 return 0;
}