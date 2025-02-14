
/* 
    ? 121: Pizza with 3n Slices
    ? https://leetcode.com/problems/pizza-with-3n-slices/description/  

    There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:

You will pick any pizza slice.
Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
Your friend Bob will pick the next slice in the clockwise direction of your pick.
Repeat until there are no more slices of pizzas.
Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.

 

Example 1:


Input: slices = [1,2,3,4,5,6]
Output: 10
Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively. Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.
Example 2:


Input: slices = [8,9,8,6,1,1]
Output: 16
Explanation: Pick pizza slice of size 8 in each turn. If you pick slice with size 9 your partners will pick slices of size 8.


 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int index , int endPoint , vector<int> &slices , int k) {

    // base case
    if(k == 0 || index > endPoint) {
        return 0;
    }

    // recursive case

    // if we take the current slice
    int take = slices[index] + solve(index + 2 , endPoint , slices , k - 1);
    int nottake = 0 + solve(index + 1, endPoint , slices , k);

    return max(take , nottake);
}

int main() {

    vector<int> slices = {1,2,3,4,5,6};
    int n = slices.size();

    // step1 : find the max sum of slices
    int case1 = solve(0 , n - 2 , slices , n / 3);
    int case2 = solve(1 , n - 1 , slices , n / 3);
    int ans = max(case1 , case2);
    cout << "ans is : " << ans << endl;


 return 0;
} 