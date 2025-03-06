/* 
    ? 15_Valid_Palindrome.cpp
    ? https://leetcode.com/problems/valid-palindrome/description/

    A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

    Given a string s, return true if it is a palindrome, or false otherwise.

    

    Example 1:

    Input: s = "A man, a plan, a canal: Panama"
    Output: true
    Explanation: "amanaplanacanalpanama" is a palindrome.
    Example 2:

    Input: s = "race a car"
    Output: false
    Explanation: "raceacar" is not a palindrome.
    Example 3:

    Input: s = " "
    Output: true
    Explanation: s is an empty string "" after removing non-alphanumeric characters.
    Since an empty string reads the same forward and backward, it is a palindrome.
 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    string s = "hello sanket how are you bro ";
    
    string str;

        for(char c : s)  {
            if (isalnum(c)) {
                str += tolower(c);
            }    
        }
        
        int i = 0;
        int j = str.length() - 1;

        // bool ans = solve(str , i , j);
        // return ans;

        while ( i < j) {

            if(str[i] != str[j]) {
                return false;       
            }

            i++;
            j--;
        }

        return true;

 return 0;
} 