#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> nums1 = {1,2,2,1 , 3 ,5,4,8,6,5,4,2,3,6,4};
    vector<int> nums2 = {2,2};

    int n = nums1.size();
    int m = nums2.size();

    int i = 0;
    int j = 0;

    unordered_set<int> ans;

    while (i < n && j < m) {

        if(nums1[i] < nums2[j]) {
            i++;
        }

        else if(nums1[i] > nums2[j]) {
            j++;
        }

        else {
            ans.insert(nums1[i]);
            i++;
            j++;
        }
    }

    for(auto x : ans) {
        cout << x << " ";
    }
 return 0;
}