
/*
^    Problem statement
^    You are given a positive integer ‘n’.
^
^
^    Your task is to find and return its square root. If ‘n’ is not a perfect square, then return ^    the floor value of sqrt(n).
^
^    Example:
^    Input: ‘n’ = 7
^
^    Output: 2
*/

//^ Lecture No : 14
// todo : link ;- -   - https://www.naukri.com/code360/problems/square-root_893351?source=youtube&campaign=love_babbar_codestudio2

#include <iostream>
using namespace std;

long long int sqrtInteger(int n)
{

    int s = 0; 
    int e = n;
    long long int mid = s + (e - s) / 2;

    long long int ans = -1;

    while (s <= e)  // while (start < end) --> run time error

    {

        long long int square = mid * mid;

        if (square == n)
            return mid;

        if (square < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    
    return ans;
}

double morePrecision(int n, int precision, int tempSol)
{

    double factor = 1;
    double ans = tempSol;
    cout << "factor is " << factor << endl;
    cout << "tempSol is " << tempSol << endl;
    cout << "ans is " << ans << endl;

    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;  // --> 0.1

        for (double j = ans; j * j < n; j = j + factor)
        {
            ans = j;  
        }
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter the number : ";
    cin >> n;

    int tempSol = sqrtInteger(n);
    cout << tempSol << endl;
    cout << "Answer is " << morePrecision(n, 3, tempSol) << endl; 

    return 0;
}