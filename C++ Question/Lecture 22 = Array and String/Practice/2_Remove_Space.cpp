#include<iostream>
using namespace std;
 
int main() { 

    string s;
    cout << "Enter the string : ";
    getline(cin, s);

    for(int i = 0; i< s.length(); i++) {
        if(s[i] == ' ') {
            s.replace(i, 1, "@40");
        }
    }

    cout << s;

    return 0;
}