
//* Insertion Sort
//^ Lecture No : 18

//& use case = It is adaptable algorithm
//? Time Complexity : O(n^2)
//? Space Complexity : O(1)
//? Best Case : O(n)
//? Average Case : O(n^2)
//? Worst Case : O(n^2)

#include <iostream>
using namespace std;

void PrintArray(int arr[] , int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1; i < n; i++)
    {

        int temp = arr[i];
        cout << "i : " << arr[i] << endl;

        int j = i - 1;

        for(; j >= 0 ; j--)
        {
            cout << "j : " << arr[j] << endl;
            
            if(arr[j] > temp) {
                arr[j + 1] = arr[j];

                cout<< "value of j + 1 = "<< arr[j + 1]  << endl;
                cout<< "value of j = "<< arr[j] << endl;
            }
            else {
                break;
            }
        }

        cout << "temp : " << temp << endl;
        cout << "arr[j + 1] : " << arr[j + 1] << endl;
        arr[j + 1] = temp;
        cout <<"updated temp = " << temp << endl;


        cout << "After pass " << i << ": ";
        PrintArray(arr , n);
        cout << endl;

    }
    
    return 0;
}

/* 
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
 */