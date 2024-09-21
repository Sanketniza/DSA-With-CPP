#include<iostream>
using namespace std;

int Binary(int arr[], int size) {

    int start = 0;
    int end = size -1;  // end at index 9 and sizeof arr is 10

    cout << end << " and size of arr " << size << endl;

    int mid = start + (end - start) /2;

    while (start < end) {

        if(arr[mid] < arr[mid + 1]) {

            start = mid + 1;
        }

        else {
            end = mid;
        }

        mid = start + (end - start) /2;
    }

    return start;

}
 
int main() { 

     int arr[] = {2,3,5,6,15,7,8,9,4,2};
     int size = sizeof(arr)/sizeof(arr[0]);
     
    int result = Binary(arr, size);

    cout << "The Highest Index element in array is " << result << " element value is " << arr[result] << endl;

    return 0;
}