
//!  Peak Index in a Mountain Array

// todo : link ;- - https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
    
    /*   


   ^  You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
   ^  
   ^  Return the index of the peak element.
   ^  
 
      Example 1:
    
      Input: arr = [0,1,0]
      Output: 1
    
      Example 2:
     
      Input: arr = [0,2,1,0]
      Output: 1
     
      Example 3:

      Input: arr = [0,10,5,2]
      Output: 1
 */

#include<iostream>
using namespace std;

int BinarySearch(int arr[] , int n ) {
    int start = 0 ;
    int end  = n - 1; 
    int mid = start + (end - start) / 2;

    while ( start < end ) {  //* while (start <= end ) --> give an run time error .

        cout << "mid is :" << arr[mid] << endl;
        cout << "mid + 1 is : " << arr[mid + 1] << endl;

        if(arr[mid] < arr[mid + 1] ) {
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

    // int arr[] = {2,3,5,6,5,7,8,9,4,2};
        int arr[] = {2,4,6,8,1,3,5};
    // int arr[] = {12,13,14,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);

    int result = BinarySearch(arr , size );

    cout << "The Highest Index element in array is " << result << " element value is " << arr[result] << endl;

    return 0;
}