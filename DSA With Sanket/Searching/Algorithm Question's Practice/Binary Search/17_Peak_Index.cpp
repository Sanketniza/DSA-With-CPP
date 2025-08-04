#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int arr[] , int n) {

    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while (start < end) {

        if(arr[mid] < arr[mid + 1]){
            start = mid + 1;
        }

        else {
            end = mid;
        }

        mid = start + (end - start) / 2;
    }
    return start;
}

int main() {

    int arr[] = {1,2,3,2,1};
    int size = sizeof(arr) / sizeof(arr[0]);

    int a = solve(arr , size);
    cout << "The peak element is : " << a << endl;

 return 0;
}