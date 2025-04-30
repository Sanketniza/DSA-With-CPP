#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void build(vector<int> &arr , int n , int i) {

    int parent = i;
    int leftParent = 2 *i + 1;
    int rightParent = 2 * i + 2;

    if(leftParent < n && arr[leftParent] < arr[parent]) {
        parent = leftParent;
    }

    if(rightParent < n && arr[rightParent] < arr[parent]) {
        parent = rightParent;
    }

    if(parent != i) {
        swap(arr[parent] , arr[i]);
        build(arr , n , parent);
    }


}

vector<int> buildMinHeap(vector<int> &arr , int n) {

    for(int i = n /2 - 1; i >= 0; i--) {
        build(arr , n , i);
    }

    return arr;
}

int main() {

    vector<int> arr = { 9, 3, 2, 6, 7 };
    int n = arr.size();

    cout << "Original array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<int> minHeap = buildMinHeap(arr, n);

    cout << "Min Heap: ";
    for(int i = 0; i < n; i++) {
        cout << minHeap[i] << " ";
    }
    cout << endl;


 return 0;
}