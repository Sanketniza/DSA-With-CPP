/* 
    ? LECTURE nO : 75
    ? Kth Smallest Element in an Array
    ? LINK : https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

    Given an array arr[] and an integer k where k is smaller than the size of the array, the task is to find the kth smallest element in the given array.

Follow up: Don't solve it using the inbuilt sort function.

Examples :

Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output:  7
Explanation: 3rd smallest element in the given array is 7.
Input: arr[] = [2, 3, 1, 20, 15], k = 4 
Output: 15
Explanation: 4th smallest element in the given array is 15.
Expected Time Complexity: O(n+(max_element) )
Expected Auxiliary Space: O(max_element)

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main() { 

// todo: solution 1
    int arr[] = {5,1,2,3,77,8,4,5,9,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    int k = 3;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    cout << arr[k-1] << endl;


// todo: solution 2
//? time complexity is O(nlogk)
//? space complexity is O(k)

    vector<int> v = {5,1,2,3,77,8,4,5,9,4};

    int l = 3;
    int m = v.size();

    priority_queue<int> q;

// step 1: 
    for(int i = 0; i <= l; i++) {
        q.push(i);
        // q.push(v[i]);
    }

// step 2: 
    for(int i = k; i < m; i++) {
        if(v[i] < q.top()) {
            q.pop();
            q.push(v[i]);
        }
    }

// step 3:
    cout << "Kth smallest element is: " << q.top() << endl;  

    return 0;
}