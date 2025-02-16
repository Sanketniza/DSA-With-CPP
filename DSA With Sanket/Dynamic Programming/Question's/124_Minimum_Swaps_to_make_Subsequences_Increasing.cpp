/* 
    ? 124: Minimum Swaps to make Subsequences Increasing
    ?  https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/

    You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].

    For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
    Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. The test cases are generated so that the given input always makes it possible.

    An array arr is strictly increasing if and only if arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1].

    

    Example 1:

    Input: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
    Output: 1
    Explanation: 
    Swap nums1[3] and nums2[3]. Then the sequences are:
    nums1 = [1, 3, 5, 7] and nums2 = [1, 2, 3, 4]
    which are both strictly increasing.
    Example 2:

    Input: nums1 = [0,3,5,8,9], nums2 = [2,1,4,6,9]
    Output: 1

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums1 , vector<int>& nums2 , bool swapped , int index) {

    // base case
    if(index == nums1.size()) {
        return 0;
    }

    int ans = INT_MAX;

    int prev1 = nums1[index - 1];
    int prev2 = nums2[index - 1];

    // catch the case when the previous element is swapped
    if(swapped){
        swap(prev1 , prev2);
    }

    // case 1: if both elements are strictly increasing
    if(nums1[index] > prev1 && nums2[index] > prev2) {
        ans = min(ans , solve(nums1 , nums2 , 0 , index + 1));
    }

    // case 2: if we swap the elements
    if(nums1[index] > prev2 && nums2[index] > prev1) {
        ans = min(ans , 1 + solve(nums1 , nums2 , 1 , index + 1));
    }

    return ans;
    
}

int main() {

    vector<int> nums1 = {1,3,5,4};
    vector<int> nums2 = {1,2,3,7};

    int size = nums1.size();

    //step1 : insert -1 into both vectors
    nums1.insert(nums1.begin() , -1);
    nums2.insert(nums2.begin() , -1);

    //It indicate the previous element is swapped or not
    bool swapped = 0;

    //todo: Recursive Approach
    int ans = solve(nums1 , nums2 , swapped ,1);
    cout << "ans is : " << ans << endl;

   /*  int size = nums1.size();
    vector<vector<int>> dp(size , vector<int> (2 , 0));

    // base case
    dp[0][0] = 0;
    dp[0][1] = 1;

    for(int i = 1; i < size; i++) {
        if(nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
            if(nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
                dp[i][0] = min(dp[i - 1][0] , dp[i - 1][1]);
                dp[i][1] = min(dp[i - 1][0] , dp[i - 1][1]) + 1;
            } else {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1] + 1;
            }
        } else {
            if(nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
                dp[i][0] = dp[i - 1][1];
                dp[i][1] = dp[i - 1][0] + 1;
            } else {
                cout << "Not Possible" << endl;
                return 0;
            }
        }
    }

    cout << "ans is : " << min(dp[size - 1][0] , dp[size - 1][1]) << endl; 
 
    */

 return 0;

}
