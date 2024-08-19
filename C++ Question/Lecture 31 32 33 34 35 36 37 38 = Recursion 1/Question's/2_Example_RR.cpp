#include<iostream>
using namespace std;
 
int print(int n) {

    //* base case
    if(n == 0) {
        return 1;
    }

    // int smallerProblem = print(n - 1);
    // int bigProblem = 2 * smallerProblem;

    // cout << bigProblem << " ";

    // return bigProblem;

    // ^ one line answer
    return 2 * print(n - 1);
}
int main() { 

    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    int ans = print(n);
    cout << ans << " ";

    return 0;
}