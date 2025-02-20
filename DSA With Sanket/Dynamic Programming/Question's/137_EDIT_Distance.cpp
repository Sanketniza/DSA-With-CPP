/* 
    ? 137: EDIT Distance
    ? https://leetcode.com/problems/edit-distance/

    Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

    You have the following three operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character
    

    Example 1:

    Input: word1 = "horse", word2 = "ros"
    Output: 3
    Explanation: 
    horse -> rorse (replace 'h' with 'r')
    rorse -> rose (remove 'r')
    rose -> ros (remove 'e')
    Example 2:

    Input: word1 = "intention", word2 = "execution"
    Output: 5
    Explanation: 
    intention -> inention (remove 't')
    inention -> enention (replace 'i' with 'e')
    enention -> exention (replace 'n' with 'x')
    exention -> exection (replace 'n' with 'c')
    exection -> execution (insert 'u')
 
 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    int solve(string& a , string &b , int i , int j) {

        //base case
        if( i == a.length())
            return b.length() - j;

        if( j == b.length())
            return a.length() - i;

        // recursive call

        int ans = 0;

        if(a[i] == b[j]){
            ans = solve(a , b , i + 1 , j + 1);
        } 

        else{
            // insert
            int insertAns = 1 + solve(a , b , i , j + 1);
            // delete
            int deleteAns = 1 + solve(a , b , i + 1 , j);
            // replace
            int replaceAns = 1 + solve(a , b , i + 1 , j +1);

            ans = min(insertAns , min(deleteAns , replaceAns));
        }      

        return ans; 
    }

int main() {

    string word1 = "horse";
    string word2 = "ros";

    int n = word1.length();
    int m = word2.length();

    //todo: Recursive Approach
        int a = solve(word1 , word2 , 0 , 0);
        cout << "ans is : " << a << endl;

    //todo: Memoization Approach
        //vector<vector<int>> dp(n , vector<int> (m , -1));
        //int b = solveM(word1 , word2 , 0 , 0 , dp);
        //cout << "ans is : " << b << endl;    

 return 0;
} 