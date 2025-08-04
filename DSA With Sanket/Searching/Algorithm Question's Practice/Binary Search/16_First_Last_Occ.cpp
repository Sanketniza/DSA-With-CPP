#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int FirstOccurrence(int arr[] , int size , int key) {

    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end) {

        if(arr[mid] == key) {
            ans = mid;
            end = mid - 1;
        }

        else if(arr[mid] < key) {
            start = mid + 1;
        }

        else if(arr[mid] > key) {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }
    return ans;
}

int secondOccurrence(int arr[] , int size , int key) {

    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end) {

        if(arr[mid] == key) {
            ans = mid;
            start = mid + 1;
        }

        else if(arr[mid] < key) {
            start = mid + 1;
        }

        else  {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    return ans;
}  

int main() {

    int arr[] = {0,1,1,2,3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k  = 1;

    int a = FirstOccurrence(arr , size , k);
    int b = secondOccurrence(arr , size , k);

    cout << "first occ is : " << a << " and second occ is : " << b << endl;    


 return 0;
}