#include<iostream>
using namespace std;

void PrintArray(int arr[] , int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
 
int main() { 

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);


    for(int i = 1; i < n  ; i++) {

        for(int j = i - 1; j >= 0; j--) {
            
            if(arr[j] > arr[j + 1]) {

                swap(arr[j], arr[j + 1]);
            }
        }
        PrintArray(arr , n);
    }


  cout << "final ans ";
        PrintArray(arr , n);
            cout << endl;

    return 0;
}