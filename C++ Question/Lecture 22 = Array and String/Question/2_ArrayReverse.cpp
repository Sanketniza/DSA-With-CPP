#include<iostream>
using namespace std;

void reverse(int arr[], int n) {
    
    int s = 0;
    int e = n - 1;

    for(int i = 0; i < n/2; i++) {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}
 
int main() { 

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << n << endl;

    reverse(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }   

    return 0;
}
