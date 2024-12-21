
#include<iostream>
using namespace std;

int Binary(int arr[], int size , int target) {

    int s = 0;
    int e = size - 1;
    int mid = s + (e - s ) /2;

    while (s <= e) {

        if(arr[mid] == target) {
            return mid;
        }

        if(arr[mid] < target) {
            s = mid + 1;
        }

        else {
            e = mid - 1;
        }

        mid = s + (e - s ) / 2;
    }

    return -1;
}

int main() {

    int arr[] = {2,3,4,5,6,7,8,9};
    int size = 8;
    int target = 8;

   int ans = Binary(arr,size,target);
   cout << "Ans is : " << ans << endl;

 return 0;
}