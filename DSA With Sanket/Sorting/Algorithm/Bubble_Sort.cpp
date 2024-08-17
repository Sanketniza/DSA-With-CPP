//* Bubble sort
//^ Lecture No : 17
//& use case = In bubble sort , In 'i'th round me 'i'th largest element will be placed in its right position.

//? Time Complexity : O(n^2)
//? Space Complexity : O(1)
//? Best Case : O(n)
//? Average Case : O(n^2)
//? Worst Case : O(n^2)

#include<iostream>
#include <bits/stdc++.h>
using namespace std;
 

 void PrintArray(int arr[], int n) {
       for(int i = 0 ; i < n ; i++) {
               cout << arr[i] << " ";
            }
          cout << endl;
 }

int main() { 

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i = 1 ; i < n ; i++) {

        for(int j = 0 ; j < n-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }

        cout << "After pass " << i << ": ";
        PrintArray(arr, n);
    }
    
    cout << endl;
    cout << "Sorted array: ";
    PrintArray(arr, n);

    return 0;
}