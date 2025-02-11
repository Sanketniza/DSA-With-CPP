/* 
    116: Min Score Triangulation of Polygon
    https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/

    You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex in clockwise order.

Polygon triangulation is a process where you divide a polygon into a set of triangles and the vertices of each triangle must also be vertices of the original polygon. Note that no other shapes other than triangles are allowed in the division. This process will result in n - 2 triangles.

You will triangulate the polygon. For each triangle, the weight of that triangle is the product of the values at its vertices. The total score of the triangulation is the sum of these weights over all n - 2 triangles.

Return the minimum possible score that you can achieve with some triangulation of the polygon.

 

Example 1:


Input: values = [1,2,3]

Output: 6

Explanation: The polygon is already triangulated, and the score of the only triangle is 6.

Example 2:


Input: values = [3,7,4,5]

Output: 144

Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.
The minimum score is 144.

Example 3:


Input: values = [1,3,1,4,1,5]

Output: 13

Explanation: The minimum score triangulation is 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.

 

Constraints:

n == values.length
3 <= n <= 50
1 <= values[i] <= 100

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    int solve(vector<int> &v , int i , int j) {

        // base case
        if(i + 1 == j) {
            return 0;
        }

        // recursive call
        int ans = INT_MAX;
        for(int k = i + 1; k < j; k++) {
            ans = min (ans , v[i]*v[j]*v[k] + solve (v ,i ,k ) + solve(v , k, j ));
        }

        return ans;
    }

    int solveM(vector<int> &v , int i , int j , vector<vector<int>> &dp) {

        // base case
        if(i + 1 == j) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // recursive call
        int ans = INT_MAX;
        for(int k = i + 1; k < j; k++) {
            ans = min (ans , v[i]*v[j]*v[k] + solveM (v ,i ,k , dp) + solveM(v , k, j , dp));
        }

        dp[i][j] = ans;

        return dp[i][j];
    }

    int solveTab(vector<int> &v) {

        int n = v.size();
        vector<vector<int>> dp (n , vector<int>(n , 0));

        for(int i = n - 1; i>= 0; i--) {
            for(int j = i + 2; j < n; j++) {

                int ans = INT_MAX;

                for(int k = i + 1; k < j; k++) {
                    ans = min (ans , v[i]*v[j]*v[k] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][n - 1];
    }

int main() {

    vector<int> values = {1,3,1,4,1,5};
    int n = values.size();

    // recursive approach
    int ans = solve(values , 0 , n - 1);
    cout << "ans is : " << ans << endl;

    //todo: DP approach
    vector<vector<int>> dp(n , vector<int>(n , -1));
    int ans1 = solveM(values , 0 , n - 1 , dp);
    cout << "ans1 is : " << ans1 << endl;

    //todo: Tabulation approach
    int ans2 = solveTab(values);
    cout << "ans2 is : " << ans2 << endl;

 return 0;
} 