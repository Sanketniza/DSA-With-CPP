/* 
    ? 128: Guess Number Higher or Lower
    ? https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/

    We are playing the Guessing Game. The game will work as follows:

I pick a number between 1 and n.
You guess a number.
If you guess the right number, you win the game.
If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.

 

Example 1:


Input: n = 10
Output: 16
Explanation: The winning strategy is as follows:
- The range is [1,10]. Guess 7.
    - If this is my number, your total is $0. Otherwise, you pay $7.
    - If my number is higher, the range is [8,10]. Guess 9.
        - If this is my number, your total is $7. Otherwise, you pay $9.
        - If my number is higher, it must be 10. Guess 10. Your total is $7 + $9 = $16.
        - If my number is lower, it must be 8. Guess 8. Your total is $7 + $9 = $16.
    - If my number is lower, the range is [1,6]. Guess 3.
        - If this is my number, your total is $7. Otherwise, you pay $3.
        - If my number is higher, the range is [4,6]. Guess 5.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $5.
            - If my number is higher, it must be 6. Guess 6. Your total is $7 + $3 + $5 = $15.
            - If my number is lower, it must be 4. Guess 4. Your total is $7 + $3 + $5 = $15.
        - If my number is lower, the range is [1,2]. Guess 1.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $1.
            - If my number is higher, it must be 2. Guess 2. Your total is $7 + $3 + $1 = $11.
    The worst case in all these scenarios is that you pay $16. Hence, you only need $16 to guarantee a win.

    Example 2:

    Input: n = 1
    Output: 0
    Explanation: There is only one possible number, so you can guess 1 and not have to pay anything.
    Example 3:

    Input: n = 2
    Output: 1
    Explanation: There are two possible numbers, 1 and 2.
    - Guess 1.
        - If this is my number, your total is $0. Otherwise, you pay $1.
        - If my number is higher, it must be 2. Guess 2. Your total is $1.
    The worst case is that you pay $1.
    
 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int start , int end) {

    // base case
    if(start >= end) {
        return 0;
    }

    int ans = INT_MAX;

    for(int i = start; i <= end; i++) {
        // int temp = i + max(solve(start, i - 1), solve(i + 1, end));
        // ans = min(ans, temp);

        ans = min(ans , i + max(solve(start , i -1 ) , solve(i + 1 , end)));
    }

    return ans;
}

int solveM(int start , int end , vector<vector<int>>&dp) {

    // base case
    if(start >= end) {
        return 0;
    }

    // if the value is already computed, return it
    if(dp[start][end] != - 1)
        return dp[start][end];

    int ans = INT_MAX;

    // iterate through the array
    for(int i = start; i <= end; i++) {
        // compute the maximum value between the left and right subarrays
        int temp = max(solveM(start, i - 1, dp), solveM(i + 1, end, dp));
        // compute the minimum value between the current index and the maximum value
        ans = min(ans, i + temp);
    }

    // store the computed value in the dp array
    return dp[start][end] = ans;
}

int solveTab(int n) {

    vector<vector<int>> dp(n + 1 , vector<int> (n + 1, 0));

    for(int i = n; i >= 1; i--) { // i is the starting point and n is the ending point

        for(int j = i + 1; j <= n; j++) { // j is the ending point

            int ans = INT_MAX;

            for(int k = i; k <= j; k++) { // k is the number which we are guessing
                int temp = k + max(k - 1 < i ? 0 : dp[i][k - 1], k + 1 > j ? 0 : dp[k + 1][j]);
                ans = min(ans, temp);
            }

            dp[i][j] = ans;
        }
    }

    return dp[1][n]; // 1 is the starting point and n is the ending point (solve(1, n))
}

int main() {

    int n = 10;

    //todo: Recursive Approach
    int ans = solve(1, n); // 1 is the starting point and n is the ending point
    cout << "ans is : " << ans << endl;

    //todo: DP Approach (Top Down) (Memoization + Recursion) 
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int ans1 = solveM(1, n, dp);
    cout << "ans1 is : " << ans1 << endl;

    //todo: DP Approach (Bottom Up) (Tabulation)
    int ans2 = solveTab(n);
    cout << "ans2 is : " << ans2 << endl;
 
 return 0;
 
} 