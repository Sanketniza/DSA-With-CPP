
#include<iostream>
using namespace std;

void insertionSort(int arr[] , int n) {

    int temp;

    for(int i = 1; i < n; i++) {

        temp = arr[i];
       int j = i - 1;

        for(; j >= 0; j--) {

            if(arr[j] > temp) {
                arr[j + 1] = arr[j];
            }

            else {
                break;
            }
        }
        
        arr[j + 1] = temp;

    }
}

int main() {

    int arr[] = {2,5,4,1,3,6,9,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertionSort(arr,n);

    cout << "Sorted array  : " ;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

 return 0;
}