
#include<iostream>
using namespace std;

int binary(int arr[], int size, int target) {

    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;

    while (s <= e) {

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            s = mid + 1;
        }

        else {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;

    }

    return -1;
}

void result(int arr[], int size, int target) {

    int ans = binary(arr, size, target);

    if (ans == -1) {
        cout << "Element not found" << endl;
    }

    // rotated array
    cout << "Rotation array : ";
    for(int i = ans; i < size; i++) {
        cout << arr[i] << " ";
    }

    for(int i = 0; i < ans; i++) {
        cout << arr[i] << " ";
    }
}
 
int main() { 

    int arr[] = {1,2,3,4,5,6,7,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 6;

    cout << "Original array : ";
    for(int i = 0; i < size; i++)   
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    result(arr,size ,target);


    return 0;
}