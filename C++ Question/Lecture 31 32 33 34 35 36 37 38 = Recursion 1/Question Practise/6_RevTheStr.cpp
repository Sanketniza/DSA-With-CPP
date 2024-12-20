#include<iostream>
#include<string>
using namespace std;

string reverseStr(string s, int start, int end) {
    // base case
    if(start > end) {
        return s;
    }

    // swap characters
    swap(s[start], s[end]);
    
    // recursive call
    return reverseStr(s, start + 1, end - 1);
}

int str(string s, int start, int end) {
    string reversed = reverseStr(s, start, end);
    cout << "sanket rev is: " << reversed << endl;
    return 0;
}

int main() {

    string s = "sanket";
    int start = 0;
    int end = s.length() - 1;

    int a = str(s, start, end);
    // cout << "sanket rev : " << a << endl;

    return 0;
}