 /*
 ? https://leetcode.com/problems/intersection-of-two-arrays/description/ 

    Problem: Given two integer arrays nums1 and nums2, return an array of their intersection. 
    Each element in the result must be unique and you may return the result in any order.

    Example 1:
    Input: nums1 = [1,2,2,1], nums2 = [2,2]
    Output: [2]

    Example 2:
    

 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {

    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};

    int n = nums1.size();
    int m = nums2.size();

   int i = 0;
   int j = 0;

   vector<int> ans;

   while ( i < n && j < m ) {

        if(nums1[i] < nums2[j]) {
            i++;
        }

        else if(nums1[i] > nums2[j]) {
            j++;
        }

        else {
            ans.push_back(nums1[i]);
            i++;
            j++;
        }
    }

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

     return 0;
}

