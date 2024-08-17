#include<iostream>
using namespace std;
 
 int print(int *arr , int n) {

    int sum = 0 ;

    for (int  i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    
    return sum;
 }


int main() { 
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int *p = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }

    // Time complexity of this code is O(n)

    cout << endl;

    int ans = print(p, n);
    cout << "ans is: " << ans << endl;

 
    return 0;
}