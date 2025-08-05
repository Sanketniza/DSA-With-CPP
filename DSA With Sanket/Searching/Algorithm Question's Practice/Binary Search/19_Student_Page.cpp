#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPossible(int arr[] , int n , int student , int mid) {

    int studentCount = 1;
    int pageSum = 0;

    for(int i = 0; i < n; i++) {

        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }

        else {
            studentCount++;

            if(studentCount < student || arr[i] > mid) {
                return false;
            }

            pageSum = arr[i];
        }
    }
}

int Allocation(int arr[] , int n , int student) {

    int start = 0;
    int sum = 0;

    int ans = -1;

    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int end = sum;
    int mid = start + (end - start) / 2;

    while(start <= end) {

        if(isPossible(arr , n , student , mid)) {
            ans = mid;
            end = mid - 1;
        }

        else {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }

    return ans;
}

int main() {

    int arr[] = {10,20,30,40};
    int n = 4;
    int student = 2;

    int result = Allocation(arr , n , student);
    cout << "The minimum number of pages allocated to a student is " << result << endl;
 return 0;
}