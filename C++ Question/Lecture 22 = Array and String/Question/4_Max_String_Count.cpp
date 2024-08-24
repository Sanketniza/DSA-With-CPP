#include <iostream>
using namespace std;

char MaxCount(string s)
{

    int arr[43] = {0};
    //! we can not be find the array size like this --> arr.size()

    // check count of elements

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        cout << "The value of ch is : " << ch << endl;
        int number = 0;
        cout << "The value of number is : " << number << endl;

        if (ch >= 'A' && ch <= 'Z')
        {
            number = ch - 'A';
        }

        else
        {
            number = ch - 'a';
        }

        arr[number]++;
        cout << "The value of arr[number] is : " << arr[number] << endl;
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