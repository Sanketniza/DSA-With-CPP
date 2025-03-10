#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    string str = "((a+b))";

    stack<char> st;

    for(int i = 0; i < str.length(); i++) {

        char ch = str[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }

        else if(ch == ')') {

            bool isRedundant = true;

            while (st.top() != ')') {
                char top = st.top();

                if(top == '+' || top == '-' || top == '*' || top == '/') {
                    isRedundant = false;
                }

                st.pop();
            }

            if(isRedundant == true) {
                cout << "Yes" << endl;
                // return 0;
            }

            st.pop();

        }

        cout << "No" << endl;
    }

    


 return 0;
}

