#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {6, 2, 8, 4, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < n; i++) {

        int minIndex = i;

        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[minIndex] , arr[i]);
    }

    cout << "Sorted array is : " << endl;

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
 return 0;
}