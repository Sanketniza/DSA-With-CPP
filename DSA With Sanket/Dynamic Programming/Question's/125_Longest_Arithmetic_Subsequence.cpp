/* 
    ? 125: Longest Arithmetic Subsequence
    ? https://www.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1

    Given an array arr[] of sorted and distinct positive integers. The task is to find the length of the longest arithmetic progression in a given array.

    Note: A sequence seq is an arithmetic progression if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).

    Examples:

    Input:arr[] = [1, 7, 10, 13, 14, 19]
    Output: 4
    Explanation: The longest arithmetic progression is [1, 7, 13, 19].
    Input:arr[] = [2, 4, 6, 8, 10]
    Output: 5
    Explanation: The whole array is in AP.

    Expected Time Complexity: O(n2)
    Expected Auxiliary Space: O(n2)

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int index , int diff , vector<int> &arr) {

    // base cas
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

    vector<int> arr = {1, 7, 10, 13, 14, 19};
    int size = arr.size();

    if(size <= 2) {
        cout << size << endl;
        return 0;
    }

    int ans = 0;

    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            ans = max(ans , 2 + solve(i , arr[j] - arr[i] , arr));
        }
    }

    cout << "ans is : " << ans << endl;

    return 0;

}