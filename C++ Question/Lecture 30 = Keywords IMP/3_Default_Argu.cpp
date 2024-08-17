#include<iostream>
using namespace std;
 
int print(int arr[] , int size , int start = 1) {
    
    for(int i = start ; i < size ; i++) {
        cout << arr[i] << " ";
    }
}

int main() { 

    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
    
    int ans = print(arr , size);
    cout << ans;

    return 0;
}