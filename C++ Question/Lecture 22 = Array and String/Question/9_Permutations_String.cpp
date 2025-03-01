/* 
    ? Permutations of a String
    ? https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1?page=1&category=Strings&sortBy=submissions

    Given a string s, which may contain duplicate characters, your task is to generate and return an array of all unique permutations of the string. You can return your answer in any order.

Examples:

Input: s = "ABC"
Output: ["ABC", "ACB", "BAC", "BCA", "CAB", "CBA"]
Explanation: Given string ABC has 6 unique permutations.
Input: s = "ABSG"
Output: ["ABGS", "ABSG", "AGBS", "AGSB", "ASBG", "ASGB", "BAGS", "BASG", "BGAS", "BGSA", "BSAG", "BSGA", "GABS", "GASB", "GBAS", "GBSA", "GSAB", "GSBA", "SABG", "SAGB", "SBAG", "SBGA", "SGAB", "SGBA"]
Explanation: Given string ABSG has 24 unique permutations.
Input: s = "AAA"
Output: ["AAA"]
Explanation: No other unique permutations can be formed as all the characters are same.
 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* vector<string> permutations(string s , int n) {

    vector<string> ans;
    sort(s.begin() , s.end());

    do {
        ans.push_back(s);
    } while(next_permutation(s.begin() , s.end()));

    return ans;
} */

void recurParmutation(int index , string s , vector<string> &ans) {

    if(index == s.length()) {
        ans.push_back(s);
        return;
    }

    for(int i = index; i < s.length(); i++) {
        if(i != index && s[i] == s[index]) {
            continue;
        }

        swap(s[i] , s[index]);
        recurParmutation(index + 1 , s , ans);
        swap(s[i] , s[index]);
    }
}

vector<string> permutations(string s , int n) {

    vector<string> ans;
    sort(s.begin() , s.end());

    recurParmutation(0 , s , ans);

    sort(ans.begin() , ans.end());

    return ans;
}

int main() {

    string s = "ABC";
    int n = s.length();

    vector<string> ans = permutations(s , n);

    for(auto i : ans) {
        cout << i << " ";
    }

   

 return 0;
} 