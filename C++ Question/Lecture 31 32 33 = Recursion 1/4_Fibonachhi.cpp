#include <iostream>
using namespace std;


//^ Fibonacci Series

int fibo(int n)
{

    // base case
    if (n == 0 )
    {
        return 0;
    }

    if(n == 1) {
        return 1;
    }

    // recursive case
   int a = fibo(n - 1) + fibo(n - 2);

    return a;
  
}

int main()
{

    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    int ans = fibo(n);
   cout << ans << " ";

    return 0;
}