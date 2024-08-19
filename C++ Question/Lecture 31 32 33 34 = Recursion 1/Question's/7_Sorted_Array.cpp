#include<iostream>
using namespace std;
 
 //! check given array is sorted or nat 
 // check isSorted array or not ..........
   
    bool sorted(int arr[] , int n) {
    // bool sorted (int *arr, int n) {
    
    
        // base case 
    
        if(n == 0 || n == 1) {
            return true;
        }
    
        if(arr[0] > arr[1]) {
            return false;
        }
        else {
            // recursive case
            bool remainingPart = sorted(arr + 1, n - 1);
            return remainingPart;       
        }
    }

int main() { 

    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int ans = sorted(arr, size);

    if(ans) {
        cout << "Array is sorted" << endl;
    }

    else {
        cout << "Array is not sorted" << endl;
    }

    return 0;
}