/* 
   ? 108: Count derangements
   ? https://www.naukri.com/code360/problems/count-derangements_873861?leftPanelTab=0

    Problem statement
    A Derangement is a permutation of ‘N’ elements, such that no element appears in its original position. For example, an instance of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, because 2 present at index 0 is not at its initial position which is 2 and similarly for other elements of the sequence.

    Given a number ‘N’, find the total number of derangements possible of a set of 'N’ elements.

    Time limit: 1 sec
    Sample Input 1:
    2
    2
    3
    Sample Output 1:
    1
    2
    Explanation of Sample Output 1:
    In test case 1, For two elements say {0, 1}, there is only one possible derangement {1, 0}. 1 is present at index 0 and not at its actual position, that is, 1. Similarly, 0 is present at index 1 and not at its actual position, that is, 0.

    In test case 2, For three elements say {0, 1, 2}, there are two possible derangements {2, 0, 1} and {1, 2, 0}. In both the derangements, no element is present at its actual position.

    Sample Input 2:
    2
    1
    4
    Sample Output 2:
    0
    9
    Explanation of Sample Output 2:
    In test case 1, For the array = {0}, there is no possible derrangements. Hence the answer is 0 (zero).

    In test case 2, For the array elements = {0, 1, 2, 3}, total 9 derrangements are possible. One of them is: { 3, 2, 1, 0}.
 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveRec(int n) {

    // base case 
    if(n == 1) {
        return 0;
    }

    if(n == 2) {
        return 1;
    }

    int ans = (n - 1) * (solveRec(n - 1)) + (solveRec(n - 2));
    return ans;
} 

int solveRec(int n , vector<int> &dp) {

    // base case 
    if(n == 1) {
        return 0;
    }

    if(n == 2) {
        return 1;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n]= (n - 1) * (solveRec(n - 1 , dp)) + (solveRec(n - 2 , dp));
   
    return dp[n];
}

int solveTab(int n) {

    vector<int> dp(n +1, 0);
    dp[1] = 0; // base case
    dp[2] = 1; // base case

    for(int i = 3; i <= n; i++) {
        dp[i] = (i - 1) * (dp[i - 1]) + (dp[i - 2]);
    }

    return dp[n];
}

int solveTabSpaceOptimized(int n) {

    int a = 0;
    int b = 1;
    int c;

    for(int i = 3; i <= n; i++) {
        c = (i - 1) * b + a;
        a = b;
        b = c;
    }

    return c;

}

int main() {

    // int arr = {0, 1, 2, 3};
    int n = 3; 

    // todo: Recursion
        int ans = solveRec(n);
        cout << "ans is : " << ans << endl;

    // todo: Recursion + Memomization method , way 1
        vector<int> dp(n + 1 , -1);
        int ans1 = solveRec(n , dp);
        cout << "ans is : " << ans1 << endl;

    // todo: Tabulation method , way 3
        cout << "ans is : " << solveTab(n) << endl;

    // todo: Space Optimized  , way 4
        cout << "ans is : " << solveTabSpaceOptimized(n) << endl;        

 return 0;
} 