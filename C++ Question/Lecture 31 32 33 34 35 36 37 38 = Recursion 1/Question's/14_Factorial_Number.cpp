

/* 
    ? Factorial Number
    ? https://www.geeksforgeeks.org/problems/factorial-number2446/1


    For a given number N, find whether it is a factorial number or not. A Factorial number is a number which is equal to the factorial value of other numbers.
 

Example 1:

Input:
N = 6
Output:
1
Explanation:
6 is factorial of 3
Example 2:

Input:
N = 5
Output:
0
Explanation:
no number's factorial is 5.


 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int n) {

    // base case

    if(n == 0 || n == 1) {
        return 1;
    }

    // recursive case

    int factorial = 1;
    int i = 2;

    while (factorial < n) {

        if(n % factorial != 0) {
            return 0;
        }

        factorial *= i;
        i++;
    }

    if(factorial == n) {
        return 1;
    } else {
        return 0;
    }



}

int main() {

    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    int ans = solve(n);
    cout << "ans : " << ans << " ";

 return 0;
} 