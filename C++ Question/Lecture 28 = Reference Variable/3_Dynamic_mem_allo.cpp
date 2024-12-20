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

 void sum(int *a , int n , int &add) {
   

    for(int i = 0; i < n ; i++) {
        add += a[i];
    }

 }


int main() { 

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

 // int *p = arr[3]; --> this is static memory allocation.

 // for dynamic memory allocation of array. use below syntax.. use new keyword..
    int *p = new int[n];

  cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }

    // Time complexity of this code is O(n)

    cout << endl;

    int ans = print(p, n);
    cout << "ans is: " << ans << endl;


    // -------------------------------------

    int add = 0;
    sum(p , n , add);
    cout << "sum is : " << add << endl;

    return 0;
    
}