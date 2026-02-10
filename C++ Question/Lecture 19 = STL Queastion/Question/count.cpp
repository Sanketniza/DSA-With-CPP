
/*  

    ? Sort Array by Increasing Frequency
    ? https://leetcode.com/problems/sort-array-by-increasing-frequency/description/?envType=problem-list-v2&envId=array

    Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

 

Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]
 

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Function to solve the problem
vector<int>solve (vector<int> &v) {

    // Create a map to store the frequency of each element in the vector
    map<int,int> m;

    // Loop through the vector and increment the frequency of each element in the map
    for(int i = 0; i < v.size(); i++) {
        m[v[i]]++;
    }

    // Sort the vector in descending order of frequency, and if frequencies are equal, in descending order of element value
    sort(v.begin() , v.end() , [&](int a , int b) {
        if(m[a] == m[b]) {
            return a > b;
        }

        return m[a] < m[b];
    });

    // Return the sorted vector
    return v;
}

 
int main() {

    vector<int> v{1,1,2,2,2,3};
    //task is to count each element in the vector how many times it is present or repeated

    map<int,int> m;

    for(int i = 0; i < v.size(); i++) {
        // m[v[i]]++;
        m[v[i]] = m[v[i]] + 1;
    }

    for(auto i : m) {
        cout << i.first << " -> " << i.second << endl;
    }
    cout << endl;

    //Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

    //^ solution 1

    vector<int> ans = solve(v);
    cout << endl;

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

 return 0;
}