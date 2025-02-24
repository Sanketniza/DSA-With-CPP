/* 
    ? Merging two unsorted arrays in sorted order
    ? https://www.geeksforgeeks.org/problems/merging-two-unsorted-arrays-in-sorted-order1020/1

    Given two different arrays arr1[] and arr2[], the task is to merge the two unsorted arrays and return a sorted array.

Examples:

Input: arr1[] = [10, 5, 15] , arr2[] = [20, 3, 2]
Output: [2, 3, 5, 10, 15, 20]
Explanation: After merging both the array's and sorting it with get the desired output.  
Input: arr1[] = [1, 10, 5, 15] , arr2[] = [20, 0, 2]
Output: [0, 1, 2, 5, 10, 15, 20]

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> sort(vector<int> arr1, vector<int> arr2, vector<int> res) {
    
    for(int i = 0; i < arr1.size(); i++) {
        res.push_back(arr1[i]);
    }

    for(int i = 0; i < arr2.size(); i++) {
        res.push_back(arr2[i]);
    }

    sort(res.begin(), res.end());

    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return res;


     /* // Initialize res with the size of arr1 and arr2
        res.resize(arr1.size() + arr2.size());

        Merge arr1 and arr2 into res
        for (int i = 0; i < arr1.size(); i++) {
            res[i] = arr1[i];
        }
        for (int i = 0; i < arr2.size(); i++) {
            res[arr1.size() + i] = arr2[i];
        }
        
        
       
        
        
        // Sort the merged vector
        sort(res.begin(), res.end()); */
}

int main() {

    vector<int> arr1 = {10, 5, 15};
    vector<int> arr2 = {20, 3, 2};
    vector<int>res;

    vector<int> arr3 = sort(arr1 , arr2, res);

    

 return 0;
} 