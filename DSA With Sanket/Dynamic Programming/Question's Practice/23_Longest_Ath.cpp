#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int index , int diff , vector<int> &arr) {

    // base case
    if(index < 0) return 0;

    int include = 0;

    for(int i = index; i >= 0; i--) {
        if(arr[index] - arr[i] == diff) {
            include = max(include , 1 + solve(i , diff , arr));
        }
    }

    return include;
}

int main() {

    vector<int> arr = {1, 7, 10, 13, 14, 19};
    // cout << "size is : " << arr.size() << endl;

    if(arr.size() <= 2) {
        cout << arr.size() << endl;
        return 0;
    }

    int ans = 0;
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            ans = max(ans , 2 + solve(i , arr[j] - arr[i] , arr));
        }
    }

    cout << "ans is : " << ans << endl;

 return 0;
}