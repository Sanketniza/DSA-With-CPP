#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    string str = "{[({()})]}}";
    stack<char> s;

    for(int i = 0; i < str.length(); i++) {

        char ch = str[i];

        if(ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }

        else {

            if(!s.empty()) {
                char top = s.top();

                if( (ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[') ) {
                    s.pop();
                }

                else{
                    cout << "No" << endl;
                    return 0;
                }
            }

            else {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    if(s.empty()) {
        cout << "Yes" << endl;
    }

    else {
        cout << "No" << endl;
    }
 
 return 0;
}