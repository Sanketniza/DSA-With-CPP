
#include<iostream>
using namespace std;

int findPivot(int arr[] , int size){
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;

    while (s < e ) {

        if(arr[mid] >= arr[0]){
            s = mid + 1;
        }

        else {
            e = mid;
        }

        mid = s + (e - s ) / 2;
    }

    return s;
}

int binarySearch(int arr[] , int s , int e , int key){

    int sa = s ;
    int ea = e ;
    int mid = sa + ( ea - sa ) / 2;

    while ( sa <= ea) {

        if(arr[mid] == key){
            return mid;
        }

        if (arr[mid] < key) {
            sa = mid + 1;
        }

        else {
            ea = mid - 1;
        }

        mid = sa + ( ea - sa ) / 2;
    }
    return -1;
}

int search(int arr[] , int size , int key){
    
    int pivot = findPivot(arr , size);

    if(key >= arr[pivot] && key <= arr[size - 1]) {
        return binarySearch(arr , pivot , size , key);
    }


    else {
        return binarySearch(arr , 0 , pivot - 1 , key);
    }
}
 
int main() { 

    int arr[] = {11, 12, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    int ans = search(arr , size , key);

    if(ans != -1) {
        cout << "the element is found at index : " << ans << endl;
    }

    else {
        cout << "Element is not found" << endl;
    }

    return 0;
}