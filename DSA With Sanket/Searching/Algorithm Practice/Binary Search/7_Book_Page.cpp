//^ Book Allocation Problem

#include<iostream>
using namespace std;

bool isPossible(int arr[] , int n , int k , int mid) {

    int studentCount = 1;
    int pageSum = 0;


    for(int i = 0 ; i < n ; i++) {
        if(pageSum + arr[i] <= mid) {

            pageSum += arr[i];
        }

        else {

            studentCount++;
            if(studentCount > k || arr[i] > mid) {
                return false;
            }
            pageSum = arr[i];
        }
    }

    return true;
}

int binary(int arr[] , int n , int k) {

    int start = 0;
    int sum = 0;
    for(int i = 0; i < n ; i++) {
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