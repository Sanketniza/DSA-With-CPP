/* 
     Nth Fibonacci Number
     https://www.naukri.com/code360/problems/nth-fibonacci-number_74156?leftPanelTab=0&leftPanelTabValue=PROBLEM

     Problem statement
The n-th term of Fibonacci series F(n), where F(n) is a function, is calculated using the following formula -

    F(n) = F(n - 1) + F(n - 2), 
    Where, F(1) = 1, F(2) = 1


Provided 'n' you have to find out the n-th Fibonacci Number. Handle edges cases like when 'n' = 1 or 'n' = 2 by using conditionals like if else and return what's expected.

"Indexing is start from 1"


Example :
Input: 6

Output: 8

Explanation: The number is ‘6’ so we have to find the “6th” Fibonacci number.
So by using the given formula of the Fibonacci series, we get the series:    
[ 1, 1, 2, 3, 5, 8, 13, 21]
So the “6th” element is “8” hence we get the output.
 */

#include<iostream>
#include<vector>
using namespace std;

/* 
    * Dynamic Programming:
    * 1. Overlapping Subproblems
    * 2. Optimal Substructure
    * 3. Optimal Solution
    * 4. Recursion + Memoization
    * 5. Tabulation
    * 6. Space Optimization
   
    Approach one : - Top - Down [Recursive + Memoization]
    Approach two : - Bottom - UP [ Tabulation  ]
    Approach three : - Space Optimization

 */

// todo: Approach one : - Top - Down [Recursive + Memoization]
int fib(int n , vector<int> &dp) {

    if(n <= 1) {
        return n;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n] = fib(n -1 , dp) + fib(n -2 , dp);
    return dp[n];
}
 
int main() { 

    int n ;
    cin >> n;

//----------------------------------------------------------------

// todo: Approach one : - Top - Down [Recursive + Memoization]
    /* 
        Time Complexity : O(n);
        Space Complexity : O(n);
    */

    vector<int> dp(n + 1);

    for(int i = 0; i <= n; i++) {
        dp[i] = -1; 
    }

    // vector<int> dp(n + 1 , -1);

    cout << "ans is : " << fib(n, dp) << endl;
// ----------------------------------------------------------------

    // todo: Approach two : - Bottom - UP [ Tabulation  ] 
    // Taaulation is nothing but the iterative version of the recursive approach

    /* 
        Time Complexity : O(n);
        Space Complexity : O(n);
    */

    vector<int> dp2(n + 1);

    dp2[0] = 0;
    dp2[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp2[i] = dp2[i - 1] + dp2[i - 2];
    }

    cout << "ans is : " << dp2[n] << endl;

// ----------------------------------------------------------------

    // todo: Approach three : - Space Optimization

    /* 
        Time Complexity : O(n);
        Space Complexity : O(1);
    */

    int a = 0;
    int b = 1;
    int c;

    if(n == 0) {
        cout << "ans is : " << a << endl;
        return 0;
    }

    for(int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    cout << "ans is : " << b << endl;

// ----------------------------------------------------------------

    return 0;
}