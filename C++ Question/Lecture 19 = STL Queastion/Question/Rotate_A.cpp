/* 
    ?   https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1

    Given an array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. Do the mentioned change in the array in place.

Note: Consider the array as circular.

Examples :

Input: arr[] = [1, 2, 3, 4, 5], d = 2
Output: [3, 4, 5, 1, 2]
Explanation: when rotated by 2 elements, it becomes 3 4 5 1 2.

Input: arr[] = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20], d = 3
Output: [8, 10, 12, 14, 16, 18, 20, 2, 4, 6]
Explanation: when rotated by 3 elements, it becomes 8 10 12 14 16 18 20 2 4 6.

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> v{1, 2, 3, 4, 5};
    int d = 2;

    // revrser the first d elements
    reverse(v.begin(), v.begin() + d);

    // reverse the rest of the elements
    reverse(v.begin() + d, v.end());

    // reverse the entire array
    reverse(v.begin(), v.end());

    cout << "After rotating the array by " << d << " elements, the array is : ";
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;

     vector<int> nums = {1,2,3,4,5};
    int k1 = 2;
    int n1 = nums.size();
    cout << "n1 = " << n1 << endl;

        k1 = k1 % n1; // Calculate effective rotations
        cout << "k1 = " << k1 << endl;
        
        // Reverse the entire array
        reverse(nums.begin(), nums.end());
        
        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k1);
        
        // Reverse the remaining elements
        reverse(nums.begin() + k1, nums.end());

        cout << "After rotating the array by " << k1 << " elements, the array is : ";
        for(int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }

    cout << endl;

    return 0;
} 