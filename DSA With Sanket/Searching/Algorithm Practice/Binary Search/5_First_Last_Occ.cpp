#include<iostream>
using namespace std;

int FirstOcc (int arr[] , int size , int k ) {

    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end) {

        if (arr[mid] == k) {
            ans = mid ;
            end = mid - 1;
        }

        else if( arr[mid] < k) {

            start = mid + 1;
        }

        else if ( arr[mid] > k) {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    return ans;
}

int LastOcc (int arr[] , int size , int k ) {

    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end) {

        if (arr[mid] == k) {
            ans = mid ;
            start = mid + 1;
        }

        else if( arr[mid] < k) {    

            start = mid + 1;
        }

        else if ( arr[mid] > k) {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    return ans;
}
 
int main() { 

    int arr[] = {1,2,3,4,5,6,6,6,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 6;

    int a = FirstOcc(arr , size , k);
    int b = LastOcc(arr , size , k);

    cout << "First Occurrence is " << a << endl;
    cout << "Last Occurrence is " << b << endl;
    
    return 0;
}