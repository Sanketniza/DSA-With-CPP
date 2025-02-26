/* 
    ? Second Largest
    ? http://geeksforgeeks.org/problems/second-largest3735/1?page=1&category=Arrays&sortBy=submissions

    Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

Note: The second largest element should not be equal to the largest element.

Examples:

Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.
Input: arr[] = [10, 5, 10]
Output: 5
Explanation: The largest element of the array is 10 and the second largest element is 5.
Input: arr[] = [10, 10, 10]
Output: -1
Explanation: The largest element of the array is 10 and the second largest element does not exist.


 */

#include<iostream>
#include<vector>
using namespace std;


int main() {

    vector<int> arr = {12, 35, 1, 10, 34, 1};
    int n = arr.size();

    int largest = arr[0];
    int secondLargest = -1;

    if(n > 2) return -1;

    for(int i = 0; i < n; i++) {

        if(arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }

        else if(arr[i] > secondLargest && arr[i] < largest){
            secondLargest = arr[i];
        }
    }

    cout << "second largest element is : " << secondLargest << endl;

 return 0;
} 