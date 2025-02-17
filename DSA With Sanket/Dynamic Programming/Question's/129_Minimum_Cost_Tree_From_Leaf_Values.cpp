/* 
  ? 129 Minimum Cost Tree From Leaf Values
  ?  https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/

  Given an array arr of positive integers, consider all binary trees such that:

    Each node has either 0 or 2 children;
    The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
    The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
    Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

    A node is a leaf if and only if it has zero children.

    

    Example 1:


    Input: arr = [6,2,4]
    Output: 32
    Explanation: There are two possible trees shown.
    The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.
    Example 2:


    Input: arr = [4,11]
    Output: 44

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Function to solve the problem
int solve(vector<int> &arr , map<pair<int,int>,int> &maxi , int start , int end) {

    // Base case: if the start and end indices are the same, return 0
    if(start  == end) {
        return 0;
    }

    // Initialize the answer to the maximum possible integer value
    int ans = INT_MAX;

    // Iterate through the array from the start index to the end index
    for(int i = start; i < end; i++) {

        // Recursively solve the problem for the left and right subarrays
        int left = solve(arr , maxi , start , i);
        int right = solve(arr , maxi , i + 1 , end);

        // Get the maximum values in the left and right subarrays
        int leftMax = maxi[{start , i}];
        int rightMax = maxi[{i + 1 , end}];

        // Update the answer with the minimum value of the current answer and the sum of the left, right and product of the maximum values
        ans = min(ans , left + right + leftMax * rightMax);
    }

    // Return the final answer
    return ans;
}

int solveM(vector<int> &arr , map<pair<int, int> , int> &maxi , int start , int end , vector<vector<int>> &dp)  {

    // base casee
    if(start == end) {
        return 0;
    }

    int ans = INT_MAX;

    for(int i = start; i < end ; i++) {

        int left = solveM(arr , maxi , start , i , dp);
        int right = solveM(arr , maxi , i + 1 , end  ,dp);

        int leftMax = maxi[{start , i}];
        int rightMax = maxi[{i + 1 , end}];

        ans = min(ans , left + right + leftMax * rightMax);

    }

    return dp[start][end] = ans;
}

int solveT(vector<int> &arr , map<pair<int, int> , int> &maxi , int start , int end) {

    int n = arr.size();
    vector<vector<int>> dp(n , vector<int>(n , 0));

    for(int i = n - 1; i >= 0; i--) {
        for(int j = i + 1; j < n; j++) {

                int ans = INT_MAX;

            for(int k = i; k < j; k++) {

                int left = dp[i][k];
                int right = dp[k + 1][j];
                int leftMax = maxi[{i , k}];
                int rightMax = maxi[{k + 1 , j}];

                ans = min(ans , left + right + leftMax * rightMax);
            }

            dp[i][j] = ans;
        }
    }

    return dp[0][n - 1];

}


int main() {

    vector<int> arr = {6,2,4};
    int n = arr.size();

    map<pair<int,int>,int> maxi;

    for(int i = 0; i < n; i++) {

        maxi[{i , i}] = arr[i]; // {i , i} is the range of the leaf node

        for(int j = i + 1; j < n; j++){
            maxi[{i , j}] = max(maxi[{i , j - 1}], arr[j]); // {i , j} is the range of the leaf node , max of the leaf node ex : 6,2,4 -> 6,6,6
        }
    }

    // cout << "print the max of the leaf node" << endl;
    // for(auto i : maxi) {
    //     cout << i.first.first << " " << i.first.second << " " << i.second << endl;
    // }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << "i : " << i << " j :" << j << " maxi : " << maxi[{i , j}] << " ";
    //     }
    //     cout << endl;
    // }

    //todo: Recursive approach
    int ans = solve(arr , maxi , 0 , n - 1);
    cout << "ans is : " << ans << endl;

    //todo: Memoization approach
    vector<vector<int>> dp(n , vector<int>(n , -1));
    int ansM = solveM(arr , maxi , 0 , n - 1 , dp);
    cout << "ansM is : " << ansM << endl;

    //todo: Tabulation approach
    int ans2 = solveT(arr , maxi , 0 , n - 1);
    cout << "ans2 is : " << ans2 << endl;

 return 0;
} 