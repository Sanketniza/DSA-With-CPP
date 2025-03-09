/* 
    ? Keypad typing
    ? https://www.geeksforgeeks.org/problems/keypad-typing0119/1

    You are given a n length string S of lowercase alphabet characters and the task is to find its matching decimal representation as on the shown keypad. Output the decimal representation corresponding to the string. For ex: if you are given amazon then its corresponding decimal representation will be 262966.



    Example 1:

    Input:
    S = geeksforgeeks
    Output: 4335736743357
    Explanation:geeksforgeeks is 4335736743357
    in decimal when we type it using the given
    keypad.
    Example 2:

    Input:
    S = geeksquiz
    Output: 433577849
    Explanation: geeksquiz is 433577849 in
    decimal when we type it using the given
    keypad. 

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(string str , string& ans , string output , int index) {

    string keyPad[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    if(index == str.length()) {
        cout << "The decimal representation of the string is : " << output << endl;
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        if(keyPad[i].find(str[index]) != string::npos) {
            output += to_string(i);
            solve(str , ans , output , index + 1);
            output.pop_back();
        }
    }
}

void solvee(string s, int n,string output, string& ans, int index) {
        
        if (index >= n) {
            ans = output;
            return;
        }

        unordered_map<char, char> keypad = {
            {'a', '2'}, {'b', '2'}, {'c', '2'},
            {'d', '3'}, {'e', '3'}, {'f', '3'},
            {'g', '4'}, {'h', '4'}, {'i', '4'},
            {'j', '5'}, {'k', '5'}, {'l', '5'},
            {'m', '6'}, {'n', '6'}, {'o', '6'},
            {'p', '7'}, {'q', '7'}, {'r', '7'}, {'s', '7'},
            {'t', '8'}, {'u', '8'}, {'v', '8'},
            {'w', '9'}, {'x', '9'}, {'y', '9'}, {'z', '9'}
        };

        char c = s[index];
        
        if (islower(c) && keypad.find(c) != keypad.end()) {
            output += keypad[c];
            solvee(s, n, output, ans, index + 1);
        } 
        
        else {
            solvee(s, n, output, ans, index + 1);
        }
    }

int main() {

    // string str = "geeksforgeeks";
    string str;
    cout << "Enter the string : ";
    cin >> str;

    string ans = "";

    string keyPad[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    for (int i = 0; i < str.length(); i++) // i = g
    {
        for (int j = 0; j < 10; j++)
        {
            if (keyPad[j].find(str[i]) != string::npos)
            // if (keyPad[j].find(str[i]) ) -> this will not working
            // "" <- (keyPad[0].find(g) != string::npos) => ("" != string::npos) => false
            // "" <- (keyPad[1].find(g) != string::npos) => ("" != string::npos) => false
            //"abc" <- (keyPad[2].find(g) != string::npos) => ("abc" != string::npos) => true
            // (keyPad[3].find(g) != string::npos) => ("def" != string::npos) => false
            // (keyPad[4].find(g) != string::npos) => ("ghi" != string::npos) => false
            // (keyPad[5].find(g) != string::npos) => ("jkl" != string::npos) => false
            // (keyPad[6].find(g) != string::npos) => ("mno" != string::npos) => false
            // (keyPad[7].find(g) != string::npos) => ("pqrs" != string::npos) => false
            // (keyPad[8].find(g) != string::npos) => ("tuv" != string::npos) => false
            // (keyPad[9].find(g) != string::npos) => ("wxyz" != string::npos) => false    
            {
                // cout << j;
                ans += to_string(j);
                break;
            }
        }
    }

    cout << "The decimal representation of the string is ans : " << ans << endl;

    //* recursive approach

    int n = str.length();
    string output = "";
    int index = 0;
    string asn = "";

    if(n == 0) {
        cout << "The decimal representation of the string is  asn : " << asn << endl;
        return 0;
    }

    solve(str , ans , output , index );

    cout << "The decimal representation of the string is : " << asn << endl;

    solvee(str, n, output, ans, index);
    cout << "The decimal representation of the string is : " << ans << endl;
    

 return 0;
}

/* 

Let's break down the line if (keyPad[j].find(s[i]) != string::npos) and explain string::npos and why we use != instead of ==.

Understanding keyPad[j].find(s[i])

keyPad[j] refers to one of the strings in your keyPad array (e.g., "abc", "def", etc.).
s[i] refers to a single character from your input string str.
keyPad[j].find(s[i]) searches for the character s[i] within the string keyPad[j].
If the character s[i] is found within keyPad[j], the find() function returns the index (position) of the first occurrence of the character.
If the character s[i] is not found within keyPad[j], the find() function returns string::npos.
Understanding string::npos

string::npos is a static member constant of the std::string class.
It represents a special value that indicates "not found."
It's typically defined as the maximum value of the size_t type, which is an unsigned integer type.
Because it is the largest possible size_t value, it is a value that can never be an index into a string.
Therefore, it is a perfect value to return when no match is found.
Why != string::npos?

The if condition if (keyPad[j].find(s[i]) != string::npos) checks if the character s[i] was found in keyPad[j].
!= (not equal):
If keyPad[j].find(s[i]) returns a value other than string::npos, it means the character was found.
Therefore, != string::npos evaluates to true, and the code inside the if block executes.
Why not == string::npos?
If you used == string::npos, the if condition would be true only when the character s[i] was not found.
This would mean the code inside the if block would only execute when the character was not present, which is the opposite of what you want.
In simpler terms:

"If the character s[i] is found in the string keyPad[j] (meaning the result of find() is not 'not found'), then do the following..."

Example:

Let's say:

s[i] is 'c'.
keyPad[j] is "abc".
Then:

keyPad[j].find(s[i]) would return 2 (the index of 'c' in "abc").
2 != string::npos would be true.
The code inside the if block would execute.
Now, let's say:

s[i] is 'z'.
keyPad[j] is "abc".
Then:

keyPad[j].find(s[i]) would return string::npos.
string::npos != string::npos would be false.
The code inside the if block would not execute.

 */