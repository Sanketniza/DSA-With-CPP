/* 
    118: Reducing Dishes LeetCode 
    https://leetcode.com/problems/reducing-dishes/description/

    A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

 

Example 1:

Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.
Example 2:

Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
Example 3:

Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People do not like the dishes. No dish is prepared.
 

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &s , int index , int time) {

    int n = s.size();
    if(index == n) {
        return 0;
    }

    int include = s[index] * (time + 1) + solve(s , index + 1 , time + 1);
    int exclude = 0 + solve(s , index + 1 , time);

    return max(include , exclude); 
}

int solveM(vector<int> &s , int index , int time , vector<vector<int>> &dp) {

    // base case
    int n = s.size();
    if(index == n) {
        return 0;
    }

    if(dp[index][time] != -1) {
        return dp[index][time];
    }

    // recursive case
    int include = s[index] * (time + 1) + solveM(s , index + 1 , time + 1 , dp);
    int exclude = 0 + solveM(s , index + 1 , time , dp);

    dp[index][time] = max(include , exclude);
    return dp[index][time];
}

int solveT(vector<int> &s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    for (int index = n - 1; index >= 0; index--) {
        for (int time = index; time >= 0; time--) {
            int include = s[index] + dp[index + 1][time + 1];
            int exclude = dp[index + 1][time];

            dp[index][time] = max(include, exclude);
        }
    }

    return dp[0][0];
}


int main() {

    vector<int> satisfaction = {-1,-8,0,5,-9};
    sort(satisfaction.begin() , satisfaction.end());
    int n = satisfaction.size();


    // recursive approach
    int ans = solve(satisfaction , 0 , 0);
    cout << "ans is : " << ans << endl;


    // memoization approach
    vector<vector<int>> dp(n , vector<int> (n + 1 , -1));
    int ansM = solveM(satisfaction , 0 , 0 , dp);
    cout << "ansM is : " << ansM << endl;


    // tabulation approach
    int ansT = solveT(satisfaction);
    cout << "ansT is : " << ansT << endl;

 return 0;
} 