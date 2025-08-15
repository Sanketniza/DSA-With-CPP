
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int index , int diff , int arr[]) {

    // base case
    if(index < 0) {
        return 0;
    }

    int include = 0;

    for(int j = index - 1; j >= 0; j--) {
        if(arr[index] - arr[j] == diff) {
            include = max(include , 1 + solve(j , diff , arr));
        }
    }

    return include;
} 

int main() {

    int arr[] = {1, 7, 10, 13, 14, 19};
    int size = sizeof(arr) / sizeof(arr[0]);

    // base case
    if(size <= 2) {
        cout << size << endl;
    }

    int ans = 0;

    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; ) {
            int diff = arr[j] - arr[i];
            ans = max(ans , 2 + solve(i , diff , arr));
        }
    }

    cout << "ans is : " << ans << endl;

 return 0;
}