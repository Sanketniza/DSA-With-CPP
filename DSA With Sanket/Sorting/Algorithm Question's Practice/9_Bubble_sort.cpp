#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n =sizeof(arr)/sizeof(arr[0]);

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n - i; j++) {
            if(arr[j] > arr[j + 1] ) {
                swap(arr[j] , arr[j + 1]);
            }
        }
    }

    cout << "Sorted array is : " << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

 return 0;
}