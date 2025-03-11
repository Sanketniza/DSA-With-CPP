/* 
   ? lecture 55: Valid Parentheses
   ? link := https://www.naukri.com/code360/problems/valid-parenthesis_795104?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM

   Problem statement
    You're given a string 'S' consisting of "{", "}", "(", ")", "[" and "]" .



    Return true if the given string 'S' is balanced, else return false.



    For example:
    'S' = "{}()".

    There is always an opening brace before a closing brace i.e. '{' before '}', '  (' before ').
    So the 'S' is Balanced.
    Detailed explanation ( Input/output format, Notes, Images )
    Sample Input 1 :
    [()]{}{[()()]()}
    Sample Output 1 :
    Balanced
    Explanation Of the Sample Input 1 :
    There is always an opening brace before a closing brace i.e. '{' before '}', '  (' before '), '[' before ']'.
    So the 'S' is Balanced.
    Sample Input 2 :
    [[}[
    Sample Output 2 :
    Not Balanced
 */


#include<iostream>
#include<stack>
using namespace std;

int main() {

  string s = "[()]{}{[()()]()}";
  stack<char> a;

    for (int i = 0; i < s.length(); i++) {

        char ch = s[i];

        // condition one - if opening bracket , push into stack
        // condition two - if closing bracket , match and pop

        if (ch == '(' || ch == '{' || ch == '[') {
            a.push(ch);
        }

        else {

            // for closing bracket

            if (!a.empty()) {
                char top = a.top();

                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')) {
                    a.pop();
                }
                else {
                    return false;
                }
            }

            else {
                return false;
            }
        }
    }

  if(a.empty())
    {
        cout << "Balanced" << endl;
        return true;
    }

    else 
    {
        cout << "Not Balanced" << endl;
        return false;  
    }
  
  

 return 0;
}