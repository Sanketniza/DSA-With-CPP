#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cout << "Enter the string: ";
    getline(cin , s);

    string part = "abc";

    while (s.length() != 0 && s.find(part) < s.length()) {
        s.erase(s.find(part) , part.length());
    }

    cout << "Remaining part after erase : " << s << endl;
    
 return 0;
}