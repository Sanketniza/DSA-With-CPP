#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int BubbleSort(vector<int> &arr , int size) {

    // base case
    if(size == 0 || size == 1) {
        return 0;
    }

    for(int i = 0; i < size - 1; i++) {
        if(arr[i] > arr[i + 1] ) {
            swap(arr[i] , arr[i+1]);
        }
    }

    // recursive case
    BubbleSort(arr, size - 1);
    
    cout << "After sorting : " << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {

    vector<int> arr = {1, 25, 13, 4, 5, 6, 7, 8, 9, 10};
    int size = arr.size();

    BubbleSort(arr, size);
 return 0;
}