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

    vector<int> dp(n + 1);

    for(int i = 0; i <= n; i++) {
        dp[i] = -1; 
    }

    cout << "ans is : " << fib(n, dp) << endl;


    return 0;
}