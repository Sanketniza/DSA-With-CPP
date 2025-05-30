//& Check if Array Is Sorted and Rotated
//* video = 21;
//^ link Check if Array Is Sorted and Rotated

/* 
  Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].
Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.
Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 */

#include<iostream>
#include<vector>
using namespace std;
 
int main() { 

    vector<int> v;  

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    int n = v.size();
    int count = 0;

    for(int i = 1 ; i<n ; i++) {
        
        // cout << v[i - 1] ;
        if(v[i - 1] > v[i]) {
            count ++;
        }
    }

    if(v[n - 1 ] > v[0]) {
        count++;
    }

    cout << count << endl;
    for(int i = 0 ; i < v.size() ; i++) {
        cout << v[i] << " ";
    }


    return count <= 1;
}