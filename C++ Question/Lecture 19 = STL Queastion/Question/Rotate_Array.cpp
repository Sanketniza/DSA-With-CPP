//! Rotate Array
//* video = 21
// & link = https://www.youtube.com/watch?v=Z7_nMTHROZo&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=28

/* 
^      Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
^   
^    
^   
^   Example 1:
^   
^   Input: nums = [1,2,3,4,5,6,7], k = 3
^   Output: [5,6,7,1,2,3,4]
^   Explanation:
^   rotate 1 steps to the right: [7,1,2,3,4,5,6]
^   rotate 2 steps to the right: [6,7,1,2,3,4,5]
^   rotate 3 steps to the right: [5,6,7,1,2,3,4]
^   Example 2:
^   
^   Input: nums = [-1,-100,3,99], k = 2
^   Output: [3,99,-1,-100]
^   Explanation: 
^   rotate 1 steps to the right: [99,-1,-100,3]
^   rotate 2 steps to the right: [3,99,-1,-100]
 */

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
 
int main() { 

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    cout << "size of v = " << v.size() << endl;

    int k = 3;

    vector<int> temp(v.size());
    cout << "size of temp = " << temp.size() << endl;

    for(int i = 0; i < v.size(); i++) {
        
        temp[(i + k ) % v.size()] = v[i];
        cout << v[i]<< " ";
        // cout << endl;

        // cout << temp[i] << " ";
        // cout << endl;
    }

    cout << endl;
    v = temp;

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;

    return 0;
}