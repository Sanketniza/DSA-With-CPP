#include <iostream>
using namespace std;

char MaxCount(string s)
{

    int arr[43] = {0};

    // check count of elements
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        int number = 0;

        if (ch >= 'A' && ch <= 'Z')
        {
            number = ch - 'A';
        }

        else
        {
            number = ch - 'a';
        }
        
        arr[number]++;
    }

    // cout << number;

    // finding the max occurrences of each element
    int max = -1;
    int ans = 0;

    for (int i = 0; i < 43; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            ans = i;
        }
    }

    return 'a' + ans;
}

int main()
{

    string s;
    cout << "Enter the string : ";
    cin >> s;

    cout << MaxCount(s);
    return 0;
}