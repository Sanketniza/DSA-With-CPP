/* 
17. Letter Combinations of a Phone Number


Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]
 
 */

#include <iostream>
#include <vector>
using namespace std;

void solve(string str, vector<string> &ans, string output, int index, string keyPad[])
{

    // base case

    if (index >= str.length())
    {
        ans.push_back(output);
        return;
    }

    int number = str[index] - '0';
    cout << "number is : " << number << endl;
    string value = keyPad[number];

    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        solve(str, ans, output, index + 1, keyPad);
        output.pop_back();
    }
}

int main()
{

    string str;
    cout << "Enter the string : ";
    cin >> str;

    vector<string> ans;

    if (str.length() == 0)
    {
        ans.push_back("");
        return 0;
    }

    string output = "";
    int index = 0;

    string keyPad[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    solve(str, ans, output, index, keyPad);

    cout << "The possible combinations are : " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}