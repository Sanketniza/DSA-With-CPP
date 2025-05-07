#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int n , int &count) {
    
    //base case
    if(n == 0) {
        return count;
    }

    // check if n is prime
    bool isPrime = true;

    

    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            isPrime = false;
            break;
        }
    }

    if(isPrime && n != 1) {
        count++;
        cout << n << " ";
    }
    // recursive call
    return solve(n - 1 , count);

}

int main() {

    int n = 30;
   

    int count = 0;
    int ans = solve (n , count);
    cout << "The number of prime numbers between 2 and " << n << " is: " << ans << endl;

 return 0;
}
