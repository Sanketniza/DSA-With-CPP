#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , int currLane , int currPos) {

    // base case
    if(currPos >= arr.size() - 1) return 0;

    // condition
    if(arr[currPos + 1] != currLane) {
        return solve(arr , currLane , currPos + 1);
    }

    else {
        int ans = INT_MIN;
        for(int i = 1; i <= 3; i++) {
            if(currLane != i && arr[currPos] != i) {
                ans = max(ans , 1 + solve(arr , i , currPos));
            }
        }
        return ans;
    }

    
}

int main() {

    vector<int> arr = {0,2,1,0,3,0};
    int size = arr.size();

    // normal way
    int ans = solve(arr , 2 , 0);
    cout << "Minimum Sideways Jump: " << ans << endl;

 return 0;
}