
//!  Search In Rotated Sorted Array

//* https://www.naukri.com/code360/problems/search-in-rotated-sorted-array_1082554?source=youtube&campaign=love_babbar_codestudio2
//^ Lecture No : 14

/*  
^   Problem statement
^   You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.
  
^   Now the array is rotated at some pivot point unknown to you.
^   
 
^   For example, if 'arr' = [ 1, 3, 5, 7, 8], then after rotating 'arr' at index 3, the array will be 'arr' = [7, 8, 1, 3, 5].
^   
  
^   Now, your task is to find the index at which ‘k’ is present in 'arr'.
  
^   Note :
^   1. If ‘k’ is not present in 'arr', then print -1.
^   2. There are no duplicate elements present in 'arr'. 
^   3. 'arr' can be rotated only in the right direction.
^   
^   
^   Example:
^   Input: 'arr' = [12, 15, 18, 2, 4] , 'k' = 2
^   
^   Output: 3
^   
^   Explanation:
^   If 'arr' = [12, 15, 18, 2, 4] and 'k' = 2, then the position at which 'k' is present in the array is 3 (0-indexed).
  
^   Detailed explanation ( Input/output format, Notes, Images )
^   Sample Input 1:
^   4 3
^   8 9 4 5
^    
^   Sample output 1:
^   -1 

^   Explanation of Sample Output 1:
^   For the test case, 3 is not present in the array. Hence the output will be -1.
^     
^   Sample Input 2:
^   4 3
^   2 3 5 8
^   
^   
^   Sample output 2:
^   1
^   
  Expected Time Complexity:
^   Try to do this in O(log(n)). 
^     
^   Constraints:
^   1 <= n <= 10^5
^   0 <= k <= 10^9
^   0 <= arr[i] <= 10^9
 */

#include <iostream>
using namespace std;

// ?time complexity : O(log n)

// Function to find the pivot index
int findPivot(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }

        else
        {
            e = mid;
        }

        mid = s + (e - s) / 2;
    }
    return s;
}

// Function to perform binary search
int binarySearch(int arr[], int s, int e, int key)
{
    cout << "The index  of s : " << s << endl;
    cout << "The index  of e : " << e << endl; 
    
    int start = s;
    int end = e;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }

        else if (arr[mid] < key)
        {
            start = mid + 1;
        }

        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    return -1;
}

// Function to search for an element in a rotated sorted array.

int search(int arr[], int n, int k)
{
    int pivot = findPivot(arr, n); // pivot index -> index of smallest element in the array 

    cout << "The pivot index is :" << pivot << endl;
    cout << "The pivot element is :" << arr[pivot] << endl;
    cout << "The value of arr[n - 1] is :" << arr[n - 1] << endl;

    if (k >= arr[pivot] && k <= arr[n - 1])
    {
        return binarySearch(arr, pivot, n - 1, k);
    }
    
    else
    {
        return binarySearch(arr, 0, pivot - 1, k);
    }


}

int main()
{
    // int arr[] = {7, 9, 1, 2, 3};
    int arr[] = {7,8,2,4,5,6};
    // int arr[] = {0,1,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5; // Example key to search for

    cout << "The value in arr :  " << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int result = search(arr, n, k);

    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }

    else
    {
        cout << "Element not found" << endl;
    } 

    cout << "The value of result is : " << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}


