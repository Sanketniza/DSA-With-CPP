#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {1, 2, 12, 2, 11, -12, 2, -1, 2, 2, 11, 12, 2, -6};
    int n = arr.size();

    unordered_map<int, int> m;

   int maxf = 0;
   int ans = 0;

   for(auto i : arr) {
        m[arr[i]]++;
        maxf = max(maxf, m[arr[i]]);
    }

    cout << "Maximum frequency is " << maxf << endl;
    cout << "Maximum frequency element is " << ans << endl;

    for(int i = 0; i < n; i++) { 
        if(m[arr[i]] == maxf) {
            ans = arr[i];
            break;
        }
    }

    cout << "Maximum frequency element is " << ans << endl;
 return 0;
}