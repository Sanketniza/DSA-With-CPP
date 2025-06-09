
/* 
   ?  Minimum Elements
   ?  https://www.naukri.com/code360/problems/minimum-elements_3843091?leftPanelTab=0&leftPanelTabValue=PROBLEM

    Problem statement
You are given an array of ‘N’ distinct integers and an integer ‘X’ representing the target sum. You have to tell the minimum number of elements you have to take to reach the target sum ‘X’.

Note:
You have an infinite number of elements of each type.
For example
If N=3 and X=7 and array elements are [1,2,3]. 
Way 1 - You can take 4 elements  [2, 2, 2, 1] as 2 + 2 + 2 + 1 = 7.
Way 2 - You can take 3 elements  [3, 3, 1] as 3 + 3 + 1 = 7.
Here, you can see in Way 2 we have used 3 coins to reach the target sum of 7.
Hence the output is 3.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 15
1 <= nums[i] <= (2^31) - 1
1 <= X <= 10000

All the elements of the “nums” array will be unique.
Time limit: 1 sec
Sample Input 1 :
2
3 7
1 2 3
1 0
1
Sample output 1 :
 3
 0
Explanation For Sample Output 1:
For the first test case,
Way 1 - You can take 4 elements  [2, 2, 2, 1] as 2 + 2 + 2 + 1 = 7.
Way 2 - You can take 3 elements  [3, 3, 1] as 3 + 3 + 1 = 7.
Here, you can see in Way 2 we have used 3 coins to reach the target sum of 7.
Hence the output is 3.
For the second test case
To reach X = 0, you don’t need to take any elements from the array.
The sum is already 0, so the total number of elements used is 0.
Sample Input 2 :
2
3 4
12 1 3
2 11
2 1
Sample output 2 :
2
6 

 */




#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &num  , int x) {

    if(x == 0) {
        return 0;
    }

    if(x < 0) {
        return INT_MAX;
    }

    int mini = INT_MAX;

    for(int i = 0; i < num.size(); i++) {
        int ans = solveRec(num , x - num[i]);

        if(ans != INT_MAX) {
            mini = min(mini , 1 + ans );
        }
    }

    return mini;
}

int solveRec1(vector<int> &num , int x , vector<int> dp) {

    if(x == 0) {
        return 0;
    }

    if(x < 0) {
        return INT_MAX;
    }

    if(dp[x] != -1) {
        return dp[x];
    }

    int mini = INT_MAX;

    for(int i = 0; i < num.size(); i++) {
        int ans = solveRec1(num , x - num[i] , dp);

        if(ans != INT_MAX) {
            mini = min(mini , 1 + ans);
        }
    }

    dp[x] = mini;

    return mini;
}

int solveRec2(vector<int> &num , int x) {

    vector<int> dp(x + 1 , INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= x ; i++) {
        for(int j = 0; j < num.size(); j++) {
            if(i - num[j] >= 0 && dp[i - num[j] ] != INT_MAX) {
                dp[i] = min(dp[i] , 1 + dp[i - num[j]]);
            }
        }
    }

    if(dp[x] == INT_MAX) {
        return -1;
    }

    return dp[x];
}

 
int main() { 

      vector<int> num = {1, 2, 3};
        int sum = 7;
        int n = num.size();  

        // todo: Approach one : - Recursive only
         // Recursion way = 1
        /*  
            Time Complexity : O(2^n);
            Space Complexity : O(1);
        
         */

        int ans = solveRec(num,  sum);
        if(ans == INT_MAX) {
            cout << "Not Possible" << endl;
        } else {
            cout << "ans is : " << ans << endl;
        }

        // todo: Approach two : - Recursive + Memoization
        // Recursion + Memoization = 2
        /*  
            Time Complexity : O(n);
            Space Complexity : O(n);
        */

        vector<int> dp(sum + 1 , -1);
        int ans2 = solveRec1(num , sum , dp);
        if(ans2 == INT_MAX) {
            cout << "Not Possible" << endl;
        }

        else {
            cout << "ans is : " << ans2 << endl;
        }

        // todo: Approach three : - Tabulation
        // Tabulation = 3
        /*  
            Time Complexity : O(n * sum);
            Space Complexity : O(sum);
        */

       int ans3 = solveRec2(num , sum);
        cout << "ans is : " << ans3 << endl;

    return 0;
}