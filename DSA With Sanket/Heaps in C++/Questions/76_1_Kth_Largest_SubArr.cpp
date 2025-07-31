/* 
	? lecture: 76 : kth largest subarray
	? link: https://www.naukri.com/code360/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION

	Problem statement
Given an array of integers, find the Kth largest sum subarray For example, given the array [1, -2, 3, -4, 5] and K = 2, the 2nd largest sum subarray would be [3, -4, 5], which has a sum of 4.

Please note that a subarray is the sequence of consecutive elements of the array.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :

3 3
3 -2 5

2 2
4 1
Sample output 1 :
3
4
Explanation of Sample output 1 :
For the first test case, 
Sum of [0, 0] = 3
Sum of [0, 1] = 1
Sum of [0, 2] = 6
Sum of [1, 1] = -2
Sum of [1, 2] = 3
Sum of [2, 2] = 5
All sum of subarrays are {6, 5, 3, 3, 1, -2} where the third largest element is 3.

 */#include <vector>
#include <queue>
#include <climits>
#include <iostream>

using namespace std;

int getKthLargest(vector<int> &arr, int k) {
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> minHeap; // min-heap
    
    // Generate all possible subarray sums
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            
            // If heap has less than k elements, push the current sum
            if (minHeap.size() < k) {
                minHeap.push(sum);
            } 
            // If current sum is larger than the smallest in heap, replace it
            else if (sum > minHeap.top()) {
                minHeap.pop();
                minHeap.push(sum);
            }
        }
    }
    
    // The root of the heap is the kth largest element
    return minHeap.top();
}

int main() {
    // Test case 1
    vector<int> arr1 = {1 , -2 , 3, -4 , 5};
    int k1 = 2;
    cout << getKthLargest(arr1, k1) << endl; // Output: 3
    
    // Test case 2
    vector<int> arr2 = {4, 1};
    int k2 = 2;
    cout << getKthLargest(arr2, k2) << endl; // Output: 4
    
    return 0;
}
