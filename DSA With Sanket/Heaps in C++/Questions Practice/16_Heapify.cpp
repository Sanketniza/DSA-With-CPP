#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class heap {
    public:

    void heapified(int arr[], int n, int i) {

        int parent = i;
        int leftIndex = 2 * i;
        int rightIndex = 2 * i + 1;

        if(leftIndex <= n && arr[parent] < arr[leftIndex]) {
            parent = leftIndex;
        }

        if(rightIndex <= n && arr[parent] < arr[rightIndex]) {
            parent = rightIndex;
        }

        if(parent != i) {
            swap(arr[parent], arr[i]);
            heapified(arr, n, parent);
        }
    }

};

int main() {

    int arr[] = {-1, 54, 53, 55, 52, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    heap h;

    for(int i = n / 2; i >  0; i--) {
        h.heapified(arr, n, i);
    }

    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }


 return 0;
}