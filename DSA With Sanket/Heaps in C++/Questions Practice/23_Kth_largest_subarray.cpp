#include <vector>
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
