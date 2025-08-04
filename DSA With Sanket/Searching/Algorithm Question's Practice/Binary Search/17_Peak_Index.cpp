#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findPivot(int arr[] , int size) {
    
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;

    while (s <= e) {

        if(arr[mid] < arr[mid + 1]) {
            s = mid + 1;
        }

        else {
            e = mid;
        }

        mid = s + (e - s) / 2;
    }

    return s;

}

int binarySearch(int arr[] , int s , int e , int key) {

    int start = s;
    int end = e;
    int mid = start + (end - start) / 2;

    while (start <= end) {

        if(arr[mid] == key) {
            return mid;
        }

        else if(arr[mid] < key) {
            start = mid + 1;
        }

        else {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    return -1;

}

int solve(int arr[] , int n, int k) {

    int pivot = findPivot(arr , n);

    cout << "The pivot index is : " << pivot << endl;

    if(k >= arr[pivot] && k <= arr[n - 1]) {
        return binarySearch(arr , pivot , n - 1 , k);
    }

    else {
        return binarySearch(arr , 0 , pivot - 1 , k);
    }

    
}

int main() {

    int arr[] = {7,8,2,4,5,6};
    int k = 5;
    int size = sizeof(arr) / sizeof(arr[0]);

    int a = solve(arr , size, k);
    cout << "The peak element is : " << a << endl;

 return 0;
}