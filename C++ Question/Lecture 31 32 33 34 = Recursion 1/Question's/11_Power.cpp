#include<iostream>
using namespace std;
 
int pow(int x, int n) {

    // base case

    if(n == 0) {
        return 1;
    }

    if(n == 1) {
        return x;
    }

    // recursive case
    int ans = pow ( x , n /2 );

    if(n % 2 == 0) {
        return ans * ans;
    }

    else {
        return ans * ans * x;
    }

cout << ans;
    return ans;
}

int main() { 

    int x, n;
    cout << "enter the value of x and n: ";
    cin >> x >> n;
   int anss = pow(x, n);

   cout << "ans is: " << anss;

    return 0;
}