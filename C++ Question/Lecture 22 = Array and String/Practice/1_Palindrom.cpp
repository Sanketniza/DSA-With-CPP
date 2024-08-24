#include <iostream>
using namespace std;

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

bool isPosible(char ch)
{

    if (ch == 'a' && ch == 'z')
    {
        return true;
    }

    else
    {
        int temp = ch - 'A' + 'a';
        return true;
    }
}

bool reverse(char str[], int n)
{

    int s = 0;
    int e = n - 1;

    while (s < e)
    {
        if (isPosible(str[s] != str[e]))
        {
            return false;
        }

        else if (valid(str[s]) && valid(str[e]) )
        {
            return true;
        }

        else
        {
            s++;
            e--;
        }
    }
}

int main()
{

    string str; // do not defined the string size ...
    cout << "Enter the string : ";
    cin >> str;

    int n = str.length();

    reverse(str, n);

    cout << "Reversed string is : " << str;

    return 0;
}