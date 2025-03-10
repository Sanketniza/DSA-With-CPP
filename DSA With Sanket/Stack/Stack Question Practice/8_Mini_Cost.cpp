#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(string &s) {

    stack<char> st;

    int n = s.length();

    for(int i = 0; i < n; i++) {

        char ch = s[i];

        if(ch == '{') {
            st.push(ch);
        }

        else {
            if(!st.empty() && st.top() == '{') {
                st.pop();

            }

            else {
                st.push(ch);
            }
        }
    }

    int a = 0;
    int b = 0;

    while (!st.empty()) {

        if(st.top() == '{' ) {
            b++;
        }

        else {
            a++;
        }

        st.pop();
    }

    int ans = (a + 1) / 2 + (b + 1) / 2;
    
    cout << ans << endl;
}

int main() {

    string s = "}}{{{";
    solve(s);
 return 0;
}