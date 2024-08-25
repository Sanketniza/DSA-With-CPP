#include<iostream>
using namespace std;


//^ Fibonacci Series
int fibo(int n) {

    // base case
    if(n == 0 || n == 1) {
        return n;
}
    int a = fibo(n - 1) + fibo(n - 2);

    return a;
}
 
int main() { 

    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    int a = fibo(n);

    cout << a << " ";


    return 0;
}