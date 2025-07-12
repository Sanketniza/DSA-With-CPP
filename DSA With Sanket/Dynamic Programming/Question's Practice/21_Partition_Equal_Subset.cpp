#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int index , vector<int> &arr , int target , int n) {

    // base cases
    if(index >= n) return 0;

    if(target == 0) return 1;

    if(target < 0) return 0;

    // recursive cases

    int include = solve(index + 1 , arr , target - arr[index] , n);
    int exclude = solve(index + 1 , arr , target , n);

    return include || exclude;
}

int main() {

    vector<int> arr = {1, 5, 11, 5};
    int size = arr.size();

    int sum = 0;
    for(auto &a : arr) {
        sum += a;
    }

    if(sum & 1) {
        cout << "false" << endl;
        return 0;
    }

    int ans = solve(0 , arr , 0 , size); // 0 is the index from where we are starting and second 0 is the target sum we are looking for
    cout << (ans ? "true" : "false") << endl;

    //

 return 0;
}