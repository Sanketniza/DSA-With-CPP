#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr , int start , int end) {

    int mid = (start + end) / 2;

    int leng1 = mid - start + 1;
    int leng2 = end - mid;

    int *first = new int[leng1];
    int *second = new int[leng2];

    // copy the first array
    int mainArrayIndex = start;
    for(int i = 0; i < leng1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    // copy the second array
    mainArrayIndex = mid + 1;
    for(int i = 0; i < leng2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    // merge two array
    int index1 = 0; // for first array
    int index2 = 0; // for second array

    mainArrayIndex = start;

    while(index1 < leng2 && index2 < leng2) {
        
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }

        else {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    // copy the remaining elements in first array
    while (index1 < leng1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    // copy the remaining elements in second array
    while (index2 < leng2) {
        arr[mainArrayIndex++] = second[index2++];
    }

    // delete the arrays (free the memory) which we created dynamically
    delete[] first;
    delete[] second;

    

}

void solve(vector<int> &arr , int start , int end) {

    // base case
    if(start >= end) {
        return;
    }

    int mind = (start + end) / 2;

    // recursive case
        //left 
        solve(arr , start , mind);

        //right
        solve(arr , mind + 1 , end);

    // merge the arrays
    merge(arr , start , end);    
}

int main() {

    vector<int> arr = {1, 25, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = arr.size();

    solve(arr , 0 , size - 1);

    cout << "After sorting : " << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

 return 0;
}