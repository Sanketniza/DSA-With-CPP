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

    int x = sum(arr + 1, n - 1);
    summ += arr[0] +x;

    // summ += arr[0] + sum (arr + 1, n - 1);
    
    return summ;
}
 
int main() { 

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 , 1};
    int n = sizeof(arr) / sizeof(arr[0]);

   cout << "Sum of array : " << sum(arr, n);
   

    return 0;
}

/* 
    The function returns the accumulated sum stored in summ.
    
        Example Walkthrough
        Let's walk through an example with an array arr = {1, 2, 3, 4, 5} and n = 5.

        Initial call: sum(arr, 5)

        n is 5, so the function proceeds to the recursive case.
        x is calculated by calling sum(arr + 1, 4), which reduces the array to {2, 3, 4, 5} and n to 4.
        Recursive call: sum(arr + 1, 4)

        n is 4, so the function proceeds to the recursive case.
        x is calculated by calling sum(arr + 2, 3), which reduces the array to {3, 4, 5} and n to 3.
        Recursive call: sum(arr + 2, 3)

        n is 3, so the function proceeds to the recursive case.
        x is calculated by calling sum(arr + 3, 2), which reduces the array to {4, 5} and n to 2.
        Recursive call: sum(arr + 3, 2)

        n is 2, so the function proceeds to the recursive case.
        x is calculated by calling sum(arr + 4, 1), which reduces the array to {5} and n to 1.
        Recursive call: sum(arr + 4, 1)

        n is 1, so the function returns arr[4], which is 5.
        Back to step 4: sum(arr + 3, 2)

        x is 5, so summ is updated to 4 + 5 = 9.
        Back to step 3: sum(arr + 2, 3)

        x is 9, so summ is updated to 3 + 9 = 12.
        Back to step 2: sum(arr + 1, 4)

        x is 12, so summ is updated to 2 + 12 = 14.
        Back to step 1: sum(arr, 5)

        x is 14, so summ is updated to 1 + 14 = 15.
        The final result is returned: 15.

 */