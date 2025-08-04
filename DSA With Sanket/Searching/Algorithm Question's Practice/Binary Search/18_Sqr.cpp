#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sqrtOfNumber(int n) {

    int s = 0;
    int e = n;
    int mid = s + (e - s) / 2;

    int ans = -1;

    while (s <= e) {

        int square = mid * mid;

        if(square == n) {
            return mid;
        }

        if(square < n) {
            ans = mid;
            s = mid + 1;
        }

        else {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }

    return ans;
}

int main() {

    int n ;
    cout << "Enter the value of n : ";
    cin >> n;

   int ans = sqrtOfNumber(n);
   cout << ans << endl;

   cout << "Enter N again : ";
   cin >> n;
   
    while (n != 0) {
        cout << sqrtOfNumber(n) << endl;
        cout << "Enter N again : ";
        cin >> n;
    }

 return 0;
}