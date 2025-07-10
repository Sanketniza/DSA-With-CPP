#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    string s = "babad";

    int n = s.length();

    vector<vector<bool>> dp(n , vector<bool>(n , false));

    // base case
    if(n <= 1) {
        cout << "Longest Palindromic Substring is : " << s << endl;
        return 0;
    }

    // base case :- single char
    for(int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    int maxLength = 1;
    int start = 0;

    // base case :- two char
    for(int i = 0; i < n-1; i++) {
        if(s[i] == s[i + 1]) {
            dp[i][i + 1] = true;

            if(maxLength < 2) {
                maxLength = 2;
                start = i;
            }
        }
    }

    // for length > 2
    for(int len = 3; len < n -1; len++) {
        for(int i = 0; i < n - 1; i++) {
            int j = i + len - 1;

            if(s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;

                if(maxLength < len) {
                    maxLength = len;
                    start = i;
                }
            }
        }
    }

    cout << "Longest Palindromic Substring is : " << s.substr(start , maxLength) << endl;


 return 0;
}