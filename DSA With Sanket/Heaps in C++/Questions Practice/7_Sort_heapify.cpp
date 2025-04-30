// step 1: you have given an array.
// step 2: convert that array into a heap array.
// step 3: sort the heap array.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;



void heapify(vector<int> &arr, int n, int i) {
    
    int parent = i;
    int left = 2*i;
    int right = 2 * i + 1;

    if(left <= n && arr[left] > arr[parent]) {
        parent = left;
    } 

    if(right <= n && arr[right] > arr[parent]) {
        parent = right;
    }

    if(parent != i) {
        swap(arr[i], arr[parent]);
        heapify(arr, n, parent);
    }
}

void heapSort(vector<int> &arr, int n) {

    int size = n;

    while (size > 1) {

        swap(arr[size] , arr[1]);
        size--;

        heapify(arr, size, 1);
    }
    
}

int main() {

    vector<int> arr = {-1, 54, 53, 55, 52, 50};
    int n = arr.size() - 1;
    cout << "size of the array is : " << n << endl;

    cout << "Original array: " << endl;
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Build heap <max heap> (rearrange array)
    for(int i = n /2; i > 0; i-- ) {
        heapify(arr , n , i);
    }

    cout << "Heapified array: " << endl;
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sorting the heap
    // 1. swap the first and last element
    // 2. reduce the size of heap by 1
    // 3. heapify the root element
    // 4. repeat step 1 to 3 until size of heap is greater than 1

    // 1* you can directly use sort stl function to sort the heap array
    sort(arr.begin() + 1, arr.end());

    cout << "Sorted array: " << endl;
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 2* you can use the heapify function to sort the heap array
    heapSort(arr, n);
    cout << "Sorted heap array: " << endl;
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


 return 0;
}