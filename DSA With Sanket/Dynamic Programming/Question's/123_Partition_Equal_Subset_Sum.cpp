/* 
    ? 123: Partition Equal Subset Sum
    ? https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1

    Given an array arr[], return true if it can be partitioned into two subsets such that the sum of elements in both parts is the same, otherwise, false.
    Note: Each element is present in either the first subset or the second subset, but not in both.

    Examples:

    Input: arr = [1, 5, 11, 5]
    Output: true
    Explanation: The two parts are [1, 5, 5] and [11].
    Input: arr = [1, 3, 5]
    Output: false
    Explanation: This array can never be partitioned into two such parts.

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int index  , vector<int> &arr , int target , int size) {

    // base cases
    if(target == 0) {
        return 1;
    }

    if(index >= size) {
        return 0;
    }

    if(target < 0)
        return 0;

    // recursive cases
    int include = solve (index + 1, arr , target - arr[index] , size);
    int exclude = solve (index + 1, arr , target , size);

    return include || exclude;

}

int main() {

  vector<int> arr = {1, 5, 11, 5};
  int size = arr.size();

  int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }

    if(sum & 1) {
        cout << "false" << endl;
        return 0;
    }

    int target = sum / 2;

  //todo: Recursive Approach
  int ans = solve(0 , arr , target , size); // 0 is the index from where we are starting
    cout << "ans is : " << ans << endl;
 return 0;
} 