#include<iostream>
using namespace std;

int PeakMountain(int arr[], int n) {

    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while (mid < end) {

        if(arr[mid] < arr[mid + 1]){
            start = mid + 1;
        }

        else{
            end = mid;
        }

        mid = start + (end - start) / 2;
    }

    return start;
}
 
int main() { 

    int arr[] = {2,4,6,8,1,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    int result = PeakMountain(arr, n);
    cout << "Index of peak element in array is " << arr[result] << endl;

    return 0;
}