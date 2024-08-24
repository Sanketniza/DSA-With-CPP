#include <iostream>
#include <cstring>
using namespace std;

//* video 22;

char toLowwecase(char ch)
{

    char temp;

    if (ch >= 'a' && ch <= 'z')
    {
        return ch;
    }

    else
    {
        temp = ch - 'A' + 'a';
        return temp;
    }
    
}

bool valid(char ch)
{
    if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9')
    {
        return true;
    }
    
    else
    {
        return false;
    }
}

bool palindrome(char b[], int n)
{

    int s = 0;
    int e = n - 1;

    while (s < e)
    {

        if (toLowwecase(b[s]) != toLowwecase(b[e]))
        {
            return false;
        }

        else if (valid(b[s]) && valid(b[e]))
        {
            return true;
        }

        else
        {
            s++;
            e--;
        }
    }

    return true;
}

int main()
{

    char a[20];
    cout << "enter the string : ";
    cin >> a;
    int n = strlen(a);

    cout << "Given string is palindrome : " << palindrome(a, n) << endl;

    return 0;
}