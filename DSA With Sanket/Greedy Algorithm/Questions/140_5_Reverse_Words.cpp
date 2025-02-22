/* 
    ? Reverse Words
    ? https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

    Given a string s, reverse the string without reversing its individual words. Words are separated by spaces.

    Note: The string may contain leading or trailing spaces, or multiple spaces between two words. The returned string should only have a single space separating the words, and no extra spaces should be included.

    Examples :

    Input: s = " i like this program very much "
    Output: "much very program this like i"
    Explanation: After removing extra spaces and reversing the whole string (not individual words), the input string becomes "much very program this like i". 
    Input: s = " pqr mno "
    Output: "mno pqr"
    Explanation: After removing extra spaces and reversing the whole string, the input string becomes "mno pqr". 
    Input: s = " a "
    Output: "a"
    Explanation: The input string contains only one word with extra spaces around it. After removing the extra spaces, the output is "a".Constraints:

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string solve(string &s) {

    string ans = "";
    string temp = "";

    for(int i = s.length() - 1; i >= 0; i--) {

        if(s[i] == ' ' ) {
            reverse(temp.begin(), temp.end());
            ans += temp;
            ans += " ";
            temp = "";
        }

        else {
            temp.push_back(s[i]);
        }
    }

    reverse(temp.begin(), temp.end());
    ans += temp;
    return ans;
}

int main() {

    string s = " i like this program very much ";
    string temp = "";

        vector<string> words;
        
        // Split the string into words
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (!temp.empty()) {
                    words.push_back(temp);
                    temp = "";
                }
            } else {
                temp.push_back(s[i]);
            }
        }
        if (!temp.empty()) {
            words.push_back(temp);
        }
        
        // Reverse the order of words
        reverse(words.begin(), words.end());
        
        // Join the words back into a single string with spaces
        string ans = "";
        for (int i = 0; i < words.size(); i++) {
            ans += words[i];
            if (i != words.size() - 1) {
                ans += " ";
            }
        }

        //  cout  << ans << endl;

         string a = solve(s);
         cout << a << endl; // Output: "much very program this like i"
        
        return 0;
} 