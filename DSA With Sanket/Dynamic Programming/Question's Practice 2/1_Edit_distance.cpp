
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

    int solveM(string &a , string &b , int i , int j , vector<vector<int>> &dp) {

        // base case
        if(i == a.length()) {
            // if we have reached the end of string a, the remaining characters in string b are to be inserted
            return b.length() - j;
        }

        if(j == b.length ()) {
            // if we have reached the end of string b, the remaining characters in string a are to be deleted
            return a.length() - i;
        }

        if(dp[i][j] != -1) {
            // if the result is already computed, return it
            return dp[i][j];
        }

        // recursive call

        int ans = 0;

        if(a[i] == b[j]){
            // if the characters at the current positions in both strings are the same, move to the next positions
            ans = solveM(a , b , i + 1 , j + 1 , dp);
        } 

        else{
            // if the characters at the current positions in both strings are different, we have three options:
            //* 1. insert the character from string b at the current position in string a
            //* 2. delete the character from string a at the current position
            //* 3. replace the character from string a at the current position with the character from string b at the current position

            // we take the minimum of these three options

            // insert
            int insertAns = 1 + solveM(a , b , i , j + 1 , dp);
            // delete
            int deleteAns = 1 + solveM(a , b , i + 1 , j , dp);
            // replace
            int replaceAns = 1 + solveM(a , b , i + 1 , j +1 , dp);

            ans = min(insertAns , min(deleteAns , replaceAns));
        }

        // store the result in the dp array
        return dp[i][j] = ans;
    }

    int solveTabulation(string &a , string &b) {

        int n = a.length();
        int m = b.length();
        vector<vector<int>> dp(n + 1 , vector<int> (m + 1 , 0));

        //base cases

        // if we have reached the end of string a, the remaining characters in string b are to be inserted
        for(int j = m - 1; j >= 0; j--) {
            dp[n][j] = m - j;
        }

        // if we have reached the end of string b, the remaining characters in string a are to be deleted
        for(int i = n - 1; i >= 0; i--) {
            dp[i][m] = n - i;
        }

        // fill the dp array

        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {

                int ans = 0;

                if(a[i] == b[j]) {
                    // if the characters at the current positions in both strings are the same, move to the next positions
                    dp[i][j] = dp[i + 1][j + 1];
                    // ans = dp[i + 1][j + 1];
                }

                else {
                    // if the characters at the current positions in both strings are different, we have three options:
                    //* 1. insert the character from string b at the current position in string a
                    //* 2. delete the character from string a at the current position
                    //* 3. replace the character from string a at the current position with the character from string b at the current position

                    // we take the minimum of these three options

                    // insert
                    int insertAns = 1 + dp[i][j + 1];
                    // delete
                    int deleteAns = 1 + dp[i + 1][j];
                    // replace
                    int replaceAns = 1 + dp[i + 1][j + 1];

                    dp[i][j] = min(insertAns , min(deleteAns , replaceAns));
                }
            }
        }

        return dp[0][0];
    }

    int solveTabulationSpaceOptimized(string &a , string &b ) {

        int n = a.length();
        int m = b.length();

        vector<int> curr(n + 1 , 0);
        vector<int> next(n + 1 , 0);

        // remaining base cases
        for (int j = 0; j <= m; j++) {
            next[j] = m - j;
        }

        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {

                 curr[m] = n - i;

            int ans = 0;

            if (a[i] == b[j]) {
                ans = next[j + 1];
            } else {
                // insert
                int insertAns = 1 + curr[j + 1];
                // delete
                int deleteAns = 1 + next[j];
                // replace
                int replaceAns = 1 + next[j + 1];

                ans = min(insertAns, min(deleteAns, replaceAns));
            }

            curr[j] = ans;
        }

        next = curr;
    }

    return next[0];
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
        vector<vector<int>> dp(n , vector<int> (m , -1));
        int b = solveM(word1 , word2 , 0 , 0 , dp);
        cout << "ans is : " << b << endl;    

     //todo: Tabulation approach (bottom up )
        int c = solveTabulation(word1 , word2);
        cout << "ans is : " << c << endl;  

     //todo: spaceOptimized Tabulation approach (bottom up )
        int d = solveTabulationSpaceOptimized(word1 , word2);
        cout << "ans is : " << d << endl;    

 return 0;
} 