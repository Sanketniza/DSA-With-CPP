#include<iostream>
using namespace std;

// ^ print number

void print(int n) {

    //* base case
    if(n == 0) {
        return;
    }

   cout << n << " ";

    //* recursive case
    print(n - 1);

    // cout << n << " ";
}
 
int main() { 

    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    print(n);

    return 0;
}