#include <iostream>
using namespace std;

int gcd(int a, int b)
{

    if (a == 0)
    {
        return b;
    }

    if (b == 0)
    {
        return a;
    }

    while (a != b)
    {

        if (a > b)
        {
            a = a - b;
        }

        else
        {
            b = b - a;
        }
    }

    return a;
}

int main()
{

    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    int ans = gcd(a, b);
    cout << "LCM of " << a << " and " << b << " is: " << ans;

    return 0;
}