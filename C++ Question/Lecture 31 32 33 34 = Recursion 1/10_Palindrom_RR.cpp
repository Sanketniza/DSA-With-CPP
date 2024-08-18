#include<iostream>
using namespace std;

bool palindrome(string s , int i , int j){
    
    // base case 

    if(i > j) {
        return true;
    }

    if(s[i] != s[j]) {
        return false;
    }

    else {
       return palindrome(s , i+1 , j-1);
    }
}
 
int main() { 

    string s = "popa";
    int i = 0;
    int j = s.length() - 1;

  bool ispalindrome = palindrome(s , i , j);

    if(ispalindrome){
        cout << "palindrome" << endl;
    }

    else{
        cout << "not palindrome" << endl;
    }

    return 0;
}