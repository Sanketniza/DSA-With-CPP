
#include<iostream>
using namespace std;

int binary(int arr[] , int n) {

    int start = 0;
    int end = n - 1;
    int mid = start + (end - start ) / 2;

    while (start < end ) {

        

        if(arr[mid] < arr[mid + 1 ]) {
            // start = mid + 1;  ans- 8
            end = mid;  // ans = 1
        }

        else {
            // end = mid;
            start = mid + 1;
        }

        mid = start + (end - start ) /2;

    } 

    // cout << arr[start] << endl;

    return start;
}
 
int main() {

    int arr[] ={2,4,6,8,1,3,5};
    int size = sizeof(arr)/sizeof(arr[0]);


    int result = binary(arr, size);

    cout << "peak element at index : " << result  << " value is : " << arr[result]<< endl;
 
 return 0;

}