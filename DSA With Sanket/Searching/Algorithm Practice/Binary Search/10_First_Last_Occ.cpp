
#include<iostream>
using namespace std;

int FirstOcc (int arr[] , int size , int target) {

    int s = 0;
    int e = size - 1;
    int mid = s + ( e - s ) / 2;
    int ans = -1;

    while ( s <= e) {

        if(arr[mid] == target) {
            ans = mid;
            e = mid - 1;
        }

        else if(arr[mid] < target) {
            s = mid + 1;
        }

        else {
            e = mid - 1;
        }

        mid = s + ( e - s ) / 2;
    }

    return ans;

}

int LastOcc(int arr[] , int size , int target) {

    int s = 0;
    int e = size - 1;
    int mid = s + ( e - s  ) / 2;
    int ans = -1;

   while( s <= e )  {

        if(arr[mid] == target) {
            ans = mid;
            s = mid + 1;
        }

        else if(arr[mid] < target) {
            s = mid + 1;
        }

        else {
            e = mid - 1;
        }

        mid = s + ( e - s ) / 2;
    }  
    
    return ans;
}

int main() {

    int arr[] = {0,1,2,3,3,4};
    int size = 6;
    int target = 3;

    int first = FirstOcc(arr , size , target);
    int last = LastOcc(arr , size , target);

    cout << "first occ is : " << first << " and last occ is : " << last << endl;
    

 return 0;

}