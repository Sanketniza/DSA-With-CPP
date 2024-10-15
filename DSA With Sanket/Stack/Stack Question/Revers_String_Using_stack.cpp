/* 
    ? lecture 56: Reverse String Using Stack
    ? link - https://www.geeksforgeeks.org/problems/reverse-a-string-using-stack/1

    Problem Statement:
    You are given a string S, you need to reverse the string using stack.

    Example:
    Input: S = "GeeksforGeeks"
    Output: skeeGrofskeeG

    Input: S = "sanket"
    Output: ketans
 */

#include <iostream>
#include <stack>
#include <cstring> // Include for strlen

using namespace std;

// Function declarations
void solve(stack<char> &s);
void insert(stack<char> &s, char ch);

char* reverse(char *S, int len) {
    stack<char> s;

    // Push all characters onto the stack
    for (int i = 0; i < len; i++) {
        char ch = S[i];
        s.push(ch);
    }

    // Call the solve function to reverse the stack
    solve(s);

    // Pop characters from the stack back into the string
    for (int i = 0; i < len; i++) {
        S[i] = s.top();
        s.pop();
    }

    return S;
}

void solve(stack<char> &s) {
    if (s.empty()) {
        return;
    }

    char ch = s.top(); // Use char instead of int
    s.pop();

    solve(s);

   s.push(ch);
}



// Example usage
int main() {
    char str[] = "sanket";
    int len = strlen(str);

    reverse(str, len);

    cout << "Reversed string: " << str << endl; // Output: skeeGrofskeeG

    return 0;
}