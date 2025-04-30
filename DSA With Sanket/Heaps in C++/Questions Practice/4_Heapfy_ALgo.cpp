#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Heapify {
    public:

    void heapifyAlgo(int arr[], int n , int i) {

        int parent = i;
        int parentLeft = 2 * i;
        int parentRight = 2 * i + 1;

        if(parentLeft <= n && arr[parentLeft] > arr[parent]) {
            parent = parentLeft;
        }

        if(parentRight <= n && arr[parentRight] > arr[parent]) {
            parent = parentRight;
        }

        if(parent != i) {
            swap(arr[parent] , arr[i]);
            heapifyAlgo(arr , n , parent);
        }
    }

};



int main() {

    int arr[] = {-1 , 54, 53, 55, 52, 50};

    int size = sizeof(arr)/sizeof(arr[0]);
    int n = size - 1;
    cout << "size of the array is : " << n << endl;

    for(int i = n/2; i > 0; i--) {
        heapifyAlgo(arr , n , i);

    }


 return 0;
}