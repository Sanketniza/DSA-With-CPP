#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cout << "Enter the string: ";
    getline(cin, s); // Read the entire line including spaces and special characters

// first way:

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ') {
            s.replace(i, 1, "@40");
        }
    }

    cout << "The new string is : " << s << endl;

    // second way:
    string temp = "";

    for(int j = 0; j < s.length(); j++) {

        if(s[j] == ' ') {
            temp += "@40"; //if there is space then add @40
        } else {
            temp += s[j]; // if there is no space then add the character
        }
    }

    cout << "The new string is : " << temp << endl;

 return 0;
}