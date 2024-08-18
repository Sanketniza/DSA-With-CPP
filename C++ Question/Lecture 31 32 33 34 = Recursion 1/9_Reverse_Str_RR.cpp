#include <iostream>
using namespace std;

void reverse(string &a, int s, int e)
{

    cout << "reverse string : " << a << endl;
    // base case

    if (s > e)
    {
        return;
    }

    swap(a[s], a[e]);
    s++;
    e--;

  // recursive call
    reverse(a, s, e);
}

int main()
{

    string a = "sanket";

    cout << endl;

    reverse(a, 0, a.length() - 1);

    cout << endl;

    cout << a << endl;

    return 0;
}