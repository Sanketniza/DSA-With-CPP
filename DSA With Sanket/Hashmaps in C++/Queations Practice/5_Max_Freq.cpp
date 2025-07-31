#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {1, 2, 1 , 2,1,1,2,3,2,1,5,5,1,2,2 };
    int n = sizeof(arr)/sizeof(arr[0]);

    unordered_map<int , int> mp;

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

    for(int i = 0; i < n; i++) {
        if(mp[arr[i]] == maxi) {
            cout << arr[i] << " ";
            break;
        }
    }
 return 0;
}