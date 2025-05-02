#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {0,1,2,3,4,5,6,1,2,5,4,1,2,3,1,5,4,1,2};
    int n = arr.size();

    // map<int , int> m;
    unordered_map<int , int> m;
    for(int i = 0; i < n; i++) {
        m[arr[i]]++;
    }

    for(auto i:m) {
        cout << i.first << " : " << i.second << endl;
    }

    int max = INT_MIN;
    int ans = -1;
    for(auto i : m) {
        if(i.second > max) {
            max = i.second;
            ans = i.first;
        }


    }

    cout <<     "Most repeated element is " << ans << endl;
    cout << "Maxi Occ No is " << max << endl;
    cout << endl;

 return 0;
}