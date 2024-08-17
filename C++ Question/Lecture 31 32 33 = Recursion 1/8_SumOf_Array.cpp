#include<iostream>
using namespace std;

//print the sum of array

int sum(int arr[], int n) {

    //base case
    if(n == 0) {
        return 0;
    }

    if(n == 1) {
        return arr[0];
    }

    int summ = 0;
    // Recursive case

    // int x = sum(arr + 1, n - 1);
    // summ += arr[0] +x;

    summ += arr[0] + sum (arr + 1, n - 1);
    
    return summ;
}
 
int main() { 

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 , 1};
    int n = sizeof(arr) / sizeof(arr[0]);

   cout << "Sum of array : " << sum(arr, n);
   

    return 0;
}