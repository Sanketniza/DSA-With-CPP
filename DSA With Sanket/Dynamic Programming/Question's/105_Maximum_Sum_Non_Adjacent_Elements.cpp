/* 
 ? Maximum sum of non-adjacent elements
 ? https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0

    Problem statement
You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.

Note:
A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the array/list, leaving the remaining elements in their original order.


Where 'ARR[i]' denotes the 'i-th' element in the array/list.

Time Limit: 1 sec.
Sample Input 1:
2
3
1 2 4
4
2 1 4 9
Sample Output 1:
5
11
Explanation to Sample Output 1:
In test case 1, the sum of 'ARR[0]' & 'ARR[2]' is 5 which is greater than 'ARR[1]' which is 2 so the answer is 5.

In test case 2, the sum of 'ARR[0]' and 'ARR[2]' is 6, the sum of 'ARR[1]' and 'ARR[3]' is 10, and the sum of 'ARR[0]' and 'ARR[3]' is 11. So if we take the sum of 'ARR[0]' and 'ARR[3]', it will give the maximum sum of sequence in which no elements are adjacent in the given array/list.
Sample Input 2:
2
5
1 2 3 5 4
9
1 2 3 1 3 5 8 1 9
Sample Output 2:
8
24
Explanation to Sample Output 2:
In test case 1, out of all the possibilities, if we take the sum of 'ARR[0]', 'ARR[2]' and 'ARR[4]', i.e. 8, it will give the maximum sum of sequence in which no elements are adjacent in the given array/list.

In test case 2, out of all the possibilities, if we take the sum of 'ARR[0]', 'ARR[2]', 'ARR[4]', 'ARR[6]' and 'ARR[8]', i.e. 24 so, it will give the maximum sum of sequence in which no elements are adjacent in the given array/list.
 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums , int n) {

    // base case 
    if(n == 0) {
        return nums[0];
    }

    if(n < 0) {
        return 0;
    }

    int inclu = solve(nums , n - 2) + nums[n];
    int exclu = solve(nums , n - 1) + 0;

    return max(inclu , exclu);
}

int solve1(vector<int> &nums , int n , vector<int> &dp) {

    // base case 

    if(n == 0){
        return nums[0];
    }

    if(n < 0) {
        return 0;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    // recursive call

    int inclu = solve1(nums , n - 2 , dp) + nums[n];
    int exclu = solve1(nums , n - 1 , dp) + 0;

    dp[n] = max(inclu , exclu);

    return dp[n];
}

int solve2(vector<int> &nums ) {
    int n = nums.size();

    vector<int> dp(n , 0);

    dp[0] = nums[0];

    // base case
    if(n < 0) {
        return 0;
    }

    for(int i = 1; i < n; i++) {
        // int inclu = dp[i - 2] + nums[i];
         int inclu = (i-2 >= 0) ? dp[i - 2] + v[i] : 0;
        int exclu = dp[i - 1] + 0;
        dp[i] = max(inclu , exclu);
    }

    return dp[n -1];
}

int solve3(vector<int> &nums) {

    int n = nums.size();

    int a = 0;
    int b = nums[0];

    for(int i = 1; i < n; i++) {
        int inclu = a + nums[i];
        int exclu = b + 0;

        int ans = max(inclu , exclu);
        a = b;
        b = ans;
    }

    return b;
}
 
int main() { 

    vector<int> nums = {1, 2, 3, 5, 4};
   

    // way 1 = recursive
    int n = nums.size();
    int ans = solve(nums , n - 1); // n - 1 is the last index
    return ans;

   // way 2 = R + M

    // int n = nums.size();
    // vector<int> dp(n , -1);
    // int ans = solve1(nums , n - 1 , dp);
    // return ans;

    // way 3 = T
    // return solve2(nums);

    // way 4 = Space Opt
      //  return solve3(nums);

    return 0;
}