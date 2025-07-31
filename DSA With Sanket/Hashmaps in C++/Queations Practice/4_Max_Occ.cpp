#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {1,4,2,1,3,6,2,1,4,3,2,5,3,21,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    unordered_map<int, int> mp;


    for(int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    int maxi = INT_MIN;
    int ans = 0;

    for(auto i : mp) {
        if(i.second > maxi) {
            maxi = i.second;
            ans = i.first;
        }
    }

    cout << "Most repeated element is " << ans << endl;
    cout << "Maxi Occ No is " << maxi << endl;
 return 0;
}