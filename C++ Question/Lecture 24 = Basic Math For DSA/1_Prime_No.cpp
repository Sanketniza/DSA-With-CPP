#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter n :";
    cin >> n;

    vector<bool> prime(n + 1, true);
    int count = 0;
    prime[0] = prime[1] = false;

    for (int i = 2; i < n; i++)
    {

        if (prime[i])
        {
            count++;

            for (int j = 2 * i; j < n; j = j + i)
            {
                prime[j] = 0;
            }
        }
    }

    return count;

    return 0;
}

/*
#include <iostream>
using namespace std;

bool isPrime(int n)
{

if (n <= 1)
{
    return false;
}

for (int i = 2; i < n; i++)
{

    if (n % i == 0)
    {

        return false;
    }
}

return true;
}

int main()
{

int n;

cout << "Enter a number : ";

cin >> n;

if (isPrime(n))
{

    cout << n << " is a prime number";
}

else
{

    cout << n << " is not a prime number";
}

return 0;
}
*/