#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int index , vector<int> &nums1, int target) {
    if(index == nums1.size()) {
        return -1;
    }

    if(nums1[index] == target) {
        cout << "Element found at index: " << index << endl;
        return index;
    }

    return solve(index + 1, nums1, target);
}

int main() {

    vector<int> nums1 = {1,2,2,1,3,4,5,6,7,8,9,10};
    int target = 5;

    int ans = solve(0 ,nums1, target);
    // cout << ans << endl;

 return 0;
}