#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {1, 2, 3, 4};
    int diff = 2;
    int n = arr.size();

    unordered_map<int, int> dp;

    int ans = 0;

    for(int i = 0; i < n; i++) {

        int temp = arr[i] - diff;
        int tempAns = 0;

        if(dp.count(temp)  ) {
            tempAns = dp[temp];
        }

        dp[arr[i]] = 1 + tempAns;

        ans = max(ans , dp[arr[i]]);
    }

    cout << "ans is : " << ans << endl;

 return 0;
 
}