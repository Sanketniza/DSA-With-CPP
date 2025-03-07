#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int start , int size, vector<int> &nums1 , int target ) {


    //base cas
    if(start > size) {
        return -1;
    }

    int mid = start + (size - start) / 2;

    if(nums1[mid] == target) {
        return mid;
    }

    if(nums1[mid] > target) {
        return solve(start , mid - 1 , nums1 , target );
    }

    if(nums1[mid] < target) {
        return solve(mid + 1 , size , nums1 , target );
    }


}

int main() {

   vector<int> nums1 = {1,2,3,4,5,6,7,8,9,10};
    int target = 5;
    int size = nums1.size();

    int ans = solve(0 , size ,nums1, target);
    cout << ans << endl;
 return 0;
}