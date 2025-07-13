#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveM(vector<int>&nums1 , vector<int>& nums2 , bool swapped , int index , vector<vector<int>>& dp) {

    // base case
    if(index == nums1.size()) {
        return 0;
    }

    if(dp[index][swapped] != -1) {
        return dp[index][swapped];
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
        ans = min(ans , solveM(nums1 , nums2 , 0 , index + 1 , dp));
    }

    // case 2: if we swap the elements
    if(nums1[index] > prev2 && nums2[index] > prev1) {
        ans = min(ans , 1 + solveM(nums1 , nums2 , 1 , index + 1 , dp));
    }

    dp[index][swapped] = ans;
    return dp[index][swapped];

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

    
    //todo: Memoization Approach (Top Down) (Memoization + Recursion)
    vector<vector<int>> dp(size + 1 , vector<int> (2 , -1));
    int ans1 = solveM(nums1 , nums2 , swapped , 1 , dp);
    cout << "ans is : " << ans1 << endl;


 return 0;
}