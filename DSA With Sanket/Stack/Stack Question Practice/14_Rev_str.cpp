#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void reverse(stack<char> &s) {

    if(s.empty()) {
        return;
    }

    char ch = s.top();
    s.pop();

    reverse(s);

   s.push(ch);

}

void solve(string str) {
    
    stack<char> s;

    for(int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    reverse(s);

     for (int i = 0; i < str.length(); i++) {
        s[i] = s.top();
        s.pop();
    }

    
}

int main() {

    string str = "sanket";

    sovle(str);
    
 return 0;
}