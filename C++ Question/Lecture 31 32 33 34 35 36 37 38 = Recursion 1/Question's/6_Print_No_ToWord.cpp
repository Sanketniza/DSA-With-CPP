#include <iostream>
using namespace std;

// ^ print digit number to words  

void sayDigit(int n, string arr[])
{

    // base case

    if(n < 0) {
        return;
    }

    if (n == 0)
    {
        cout <<  arr[0];
        return;
    } 

    // processing
    int digit = n % 10;
    cout << arr[digit] << endl;
    n = n / 10;
    cout << n << endl;

   // cout << arr[digit] << " " << endl; --> print number in reverse order

    // recursive case
    sayDigit(n, arr);

    cout << arr[digit] << " ";
}

int main()
{

    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    string arr[10] = {"zero", "one", "two", "three",
                      "four", "five", "six",
                      "seven", "eight", "nine"};

    sayDigit(n, arr);

        return 0;
}