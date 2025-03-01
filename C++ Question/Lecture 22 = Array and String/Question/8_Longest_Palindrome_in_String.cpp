/*  
    ? Longest Palindrome in a String
    ? https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/0

    Given a string s, your task is to find the longest palindromic substring within s.

A substring is a contiguous sequence of characters within a string, defined as s[i...j] where 0 ≤ i ≤ j < len(s).

A palindrome is a string that reads the same forward and backward. More formally, s is a palindrome if reverse(s) == s.

Note: If there are multiple palindromic substrings with the same length, return the first occurrence of the longest palindromic substring from left to right.

Examples :

Input: s= "aaaabbaa"
Output: "aabbaa"
Explanation: The longest palindromic substring is "aabbaa". 
Input: s = "abc"
Output: "a"
Explanation: "a", "b", and "c" are all palindromes of the same length, but "a" appears first. 
Input: s = "abacdfgdcaba" 
Output: "aba" 
Explanation: The longest palindromic substring is "aba", which occurs twice. The first occurrence is returned.

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPalindrom(string &s , int i , int j) {

    while ( i < j) {

        if(s[i] != s[j]) {
            return false;
        }

        i++;
        j--;
    }

    return true;
}

string solve(string &s , int n) {

    int maxLen = 1;
    int start = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {

            if(isPalindrom(s , i , j) && j - i + 1 > maxLen ) {

                maxLen = j - i + 1;
                start = i;
            }
        }
    }

    return s.substr(start , maxLen); // substr(starting index , length)
    // s.substr(1 , 6) --> "aabbaa" , how it works ? 
    // 1 --> starting index
    // 6 --> length of string
    // 1 + 6 = 7
    // s[1] to s[7] = "aabbaa"

}

int main() {

    string s = "aaaabbaa";
    int n = s.length();

    string ans = solve(s , n);
    cout << "ans is : " << ans << endl;

 return 0;
 
} 