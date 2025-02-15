/* 
    ? 122: Number of Dice Rolls with Target Sum
    > https://www.geeksforgeeks.org/problems/dice-throw5349/1
    > https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
    > https://www.youtube.com/watch?v=58JH2S0C7yY

    ? Problem Statement

    Given n dice each with m faces. Find the number of ways to get sum x which is the summation of values on each face when all the dice are thrown.

Example:

Input: m = 6, n = 3, x = 12
Output: 25
Explanation: There are 25 total ways to get the Sum 12 using 3 dices with faces from 1 to 6.
Input: m = 2, n = 3, x = 6
Output: 1
Explanation: There is only 1 way to get the Sum 6 using 3 dices with faces from 1 to 2. All the dices will have to land on 2.

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    int solve(int face , int dice , int target) {

        // base cases
        if(target == 0 && dice == 0) {
            return 1;
        }

        if(target < 0)
            return 0;

        if(dice == 0 && target != 0) {
            return 0;
        }

        if(target == 0 && dice != 0) {
            return 0;
        }

        // recursive case

        int ans = 0;
        for(int i = 1; i <= face; i++) {
            ans += solve(face , dice - 1 , target - i);
        }

        return ans;
    }
int main() {

    int m = 6;
    int n = 3;
    int x = 12;

   
    //todo: Recursive Solution
    int ans = solve( m ,  n ,  x); 
    cout << "ans is : " << ans << endl;
 return 0;
}  