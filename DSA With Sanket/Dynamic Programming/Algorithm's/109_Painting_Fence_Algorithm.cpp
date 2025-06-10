
/*  
   ?  Painting Fence Algorithm
   ?  https://www.naukri.com/code360/problems/ninja-and-the-fence_3210208?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

    Problem statement
    There is a fence with n posts, each post can be painted with one of the k colors.
    You have to paint all the posts such that no more than two adjacent fence posts have the same color.
    Return the total number of ways you can paint the fence.

    Input: n = 3, k = 2
    Output: 6
    Explanation: Take c1 as color 1, c2 as color 2. All possible ways are:
    post1  post2  post3      
     c1     c1      c2 
     c1     c2      c1 
     c1     c2      c2 
     c2     c1      c1  
     c2     c1      c2
     c2     c2      c1


     Ninja has given a fence, and he gave a task to paint this fence. The fence has 'N' posts, and Ninja has 'K' colors. Ninja wants to paint the fence so that not more than two adjacent posts have the same color.

Ninja wonders how many ways are there to do the above task, so he asked for your help.

Your task is to find the number of ways Ninja can paint the fence. Print the answer modulo 10^9 + 7.

Example:
Input: 'N' = 3, 'K' = 2
Output: 6

Say we have the colors with the numbers 1 and 0. We can paint the fence with 3 posts with the following different combinations.

110
001
101
100
010
011

Sample Input 1 :
2
1 1
3 2
Sample Output 1 :
1
6
Explanation Of Sample Input 1 :
For the first test case, there is only one way to paint the fence. 

For the second test case, We can paint the fence with 3 posts with the following different combinations.

110
001
101
100
010
011

    Sample Input 2 :

    2 4

    4 2
    Sample Output 2 :
    16

    10
 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int numberOfWays(int n, int k) {
    if(n == 1) {
        return k;
    }

    int same = k;
    int diff = k * (k - 1);
    int total = same + diff;

    for(int i = 3; i <= n; i++) {
        same = diff;
        diff = total * (k - 1);
        total = same + diff;
    }

    return total;

    // f(n == 1) return k;
    // if(n == 2) return add(k, mul(k, k - 1));

    // int ans = solve(n - 2, k) * (k - 1) + solve(n - 1, k) * (k - 1);
    // return ans;
}


int add(int a , int b) {
    return (a%MOD + b%MOD)%MOD ;
}

int mul(int a , int b) {
    return ((a%MOD)*1LL  * (b%MOD))%MOD;
}

int solveR(int n , int k) {

    if(n == 1)
        return k;

    if(n == 2) 
        return add(k , mul(k , k - 1));


    int ans = add(mul(solveR(n - 2, k) , k - 1) , mul(solveR(n - 1, k) , k - 1));
    return ans;
}

int solveRecMem(int n , int k , vector<int> &dp) {

    // base case = 3
    if(n == 1)
        return k;

    if(n == 2)
        return add(k , mul(k , k - 1));

    if(dp[n] != -1) {
        return dp[n];
    }         

    dp[n] = add(mul(solveRecMem(n - 2, k , dp) , k - 1) , mul(solveRecMem(n - 1, k , dp) , k - 1));
    return dp[n];
}

int solveTab(int n , int k) {

    vector<int> dp(n + 1 , 0);
    dp[1] = k;
    dp[2] = add(k , mul(k , k - 1));

    for(int i = 3; i <= n; i++) {

        dp[i] = add(mul(dp[i - 2] , k - 1) , mul(dp[i - 1] , k - 1 ));
    }

    return dp[n];
}

int solveTabSpaceOpt (int n , int k) {

    int a = k;
    int b = add(k , mul(k , k - 1));
    

     for(int i = 3; i <= n; i++) {

        int c = add(mul(a , k - 1) , mul(b , k - 1 ));
        a = b;
        b = c;
    }

    return b;

    
}

int main() {


    int n, k;
    cin >> n >> k;

    // Sample Input 0: Iterative
    int result = numberOfWays(n, k);
    cout << "Number of ways: " << result << endl;

    // Sample Input 1: Recursion
        int ans = solveR(n , k);
        cout << "Number of ways: " << ans << endl;

    // Sample Input 2: Recursion + Memoization
        vector<int> dp(n + 1 , -1);
        int ans1 = solveRecMem(n , k , dp);
        cout << "Number of ways: " << ans1 << endl;

    // Sample Input 3: Tabulation
        int ans2 = solveTab(n , k);
        cout << "Number of ways: " << ans2 << endl;

    // Sample Input 4: Tabulation + Space Optimized
        int ans3 = solveTabSpaceOpt(n , k);
        cout << "Number of ways: " << ans3 << endl;        

    return 0;

} 