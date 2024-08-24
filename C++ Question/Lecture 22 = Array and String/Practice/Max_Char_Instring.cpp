#include<iostream>
using namespace std;

char Max(string s)
{
    
    int arr[26] = {0};
    //! we can not be find the array size like this --> arr.size()

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        int number = 0;

        if( ch >= 'a' && ch <= 'z')
        {
            number = ch - 'a';
        }

        else 
        {
            number = ch - 'A';
        }

        arr[number]++;
    }

    int max = -1;
    int ans = 0;
    for(int i = 0 ; i < 26 ; i++)
    {
        if( max < arr[i]) {
            max = arr[i];
            ans = i;
        }
    }    

    return 'a' + ans;
}
 
int main() { 

    string s;
    cout << "Enter the string : ";
    cin >> s;

    Max(s);

    return 0;
}