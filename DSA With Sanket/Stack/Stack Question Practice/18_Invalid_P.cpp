
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

                if ( (ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[') ) {
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