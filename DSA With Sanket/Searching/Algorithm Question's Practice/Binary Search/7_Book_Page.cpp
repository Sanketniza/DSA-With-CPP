//^ Book Allocation Problem

#include<iostream>
using namespace std;

bool isPossible(int arr[] , int n , int k , int mid) {

    int studentCount = 1;  //? initial student count is 1.
    int pageSum = 0;  //? initial page sum is 0.


    for(int i = 0 ; i < n ; i++) {  //? for loop for traversing the array.
        if(pageSum + arr[i] <= mid) {  //? if the page sum is less than the mid then add the pages to the page sum.

            pageSum += arr[i];  // adding the pages to the page sum.
        }

        else {

            studentCount++;  //? incrementing the student count.
            if(studentCount > k || arr[i] > mid) {  //? if the student count is greater than the number of students or the page sum is greater than the mid then return false.   
                return false;
            }
            pageSum = arr[i];  //? if the page sum is greater than the mid then set the page sum to the current page.
            cout << "pageSum is " << pageSum << endl;
        }
    }

    return true;
}

int binary(int arr[] , int n , int k) {

    int start = 0;  //? initial start is 0.
    int sum = 0;  //? initial sum is 0.
    for(int i = 0; i < n ; i++) {  //? for loop for calculating the sum of the array.
        sum += arr[i];
    }

    int end = sum;
    int mid = start + (end - start)/2;
    int ans = -1;

    while(start <= end) {
        
        if(isPossible(arr,n,k,mid)) {
            ans = mid;
            end = mid - 1;
        } 

        else {
            start = mid + 1;
        }

        mid = start + (end - start)/2;
    }
    return ans;
}

int main() {
 
  int arr[4] = {10,20,30,40};
  int n = 4;
  int k = 2;

  int result = binary (arr,n,k);

  cout << "The result is " << result << endl;
  
  // ek number bhava ky vishay nai hay. good luck and good night.
 return 0;
}