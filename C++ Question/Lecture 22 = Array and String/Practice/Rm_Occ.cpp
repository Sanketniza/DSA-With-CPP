#include<iostream>
using namespace std;
 
int main() { 

    string s;
    cout << "enter the string " << endl;
    getline(cin, s);
    string part = "abc";

    while (s.length() != 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part) , part.length());
    }
    
    cout << s << endl;

    return 0;
}