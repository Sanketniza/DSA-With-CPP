#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(string str, vector<string> &ans, string output, int index, string keyPad[]) {

    // base case

    if(index >= str.length()) {
        ans.push_back(output);
        return;
    }

    int number = str[index] - '0';
    string value = keyPad[number];

    for(int i = 0; i < value.length(); i++) {
        output.push_back(value[i]);
        solve(str, ans, output, index + 1, keyPad);
        output.pop_back();
    }
}

int main() {

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
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << endl;

 return 0;
}