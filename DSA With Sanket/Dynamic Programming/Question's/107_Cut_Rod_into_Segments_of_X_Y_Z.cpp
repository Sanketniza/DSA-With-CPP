/* 
    Cut Rod into Segments of X, Y, Z
    https://www.naukri.com/code360/problems/cut-into-segments_1214651?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM

    Problem statement
You are given an integer ‘N’ denoting the length of the rod. You need to determine the maximum number of segments you can make of this rod provided that each segment should be of the length 'X', 'Y', or 'Z'.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
2
7 5 2 2
8 3 3 3
Sample Output 1:
2
0
Explanation For Sample Input 1:

In the first test case, cut it into 2 parts of 5 and 2.

In the second case, there is no way to cut into segments of 3 length only as the length of the rod is less than the given length. 
Sample Input 2:
2
7 3 2 2
8 1 4 4
Sample Output 2:
3
8
Explanation For Sample Input 2:
In the first test case, cut it into 3 parts of 3, 2 and 2.

In the second case, cut it into 8 parts of length 1.
 */

 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;

int SolveTab(int n , int x , int y , int z) {

    vector<int> dp(n + 1 , INT_MIN);
    dp[0] = 0;

    for(int i = 1; i <= n; i++) {

       if(i - x >= 0) {
         dp[i] = max(dp[i] , dp[i - x] + 1);
       }

       if(i - y >= 0) {
         dp[i] = max(dp[i] , dp[i - y] + 1);
       }

       if(i - z >= 0) {
            dp[i] = max(dp[i] , dp[i - z] + 1);
        }

        cout << "dp[" << i << "] : " << dp[i] << endl;
    }

    if(dp[n] < 0) {
        return 0;
    }

    else {
        return dp[n];
    }

} 

int solve(int n , int x , int y , int z) {
    return SolveTab(n , x , y , z);
}
 

 int main() {
 
  vector<int> len = {7, 5, 2, 2};
  int n = len[0];
  int x = len[1];
  int y = len[2];
  int z = len[3];

  int ans = solve(n , x , y , z);
  cout << "ans is : " << ans << endl;

  return 0;
}
