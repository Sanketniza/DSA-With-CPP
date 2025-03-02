/* 
    ? First Occurence
    ? https://www.geeksforgeeks.org/problems/implement-strstr/1?page=1&category=Strings&sortBy=submissions

    Find the first occurrence of the string pat in the string txt. The function returns an integer denoting the first occurrence of the string pat in txt (0-based indexing).

    Note: You are not allowed to use the inbuilt function. If there is no occurrence then return -1.

    Examples :

    Input: txt = "GeeksForGeeks", pat = "Fr"
    Output: -1
    Explanation: Fr is not present in the string GeeksForGeeks as substring.
    Input: txt = "GeeksForGeeks", pat = "For"
    Output: 5
    Explanation: For is present as substring in GeeksForGeeks from index 5 (0 based indexing).
    Input: txt = "GeeksForGeeks", pat = "gr"
    Output: -1
    Explanation: gr is not present in the string GeeksForGeeks as substring.


 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(string &txt , string &pat) {

    size_t found = txt.find(pat);

    if(found != string::npos) {
        return found;
    }

    return -1;
}

int main() {

    string txt = "GeeksForGeeks";
    string pat = "For";

    int n = txt.length();
    int m = pat.length();

    int ans = -1;

    for(int i = 0; i < n; i++) {

        if(txt[i] == pat[0]) {

            int j = 0;
            while(j < m && txt[i + j] == pat[j]) {
                j++;
            }

            if(j == m) {
                ans = i;
                break;
            }
        }
    }

    cout << "ans is : " << ans << endl;

    // second solution
    int op = solve(txt , pat);
    cout << "ans is : " << op << endl;

    return 0;
    
} 