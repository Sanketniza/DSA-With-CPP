#include<iostream>
using namespace std;

int sort(int arr[] , int size) {

  int ans[size   ] = {};

    //base case
    if(size == 0 || size == 1) {
        return 0;
    }

    if(arr[0] > arr[1]) {
        return -1;
    }

    //recursive case
    else{

       ans =  sort(arr + 1 , size - 1);
    }
    return ans;

}
 
int main() { 

    int arr[] = { 1, 25, 13, 4, 5, 6, 7, 8, 9, 10 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting : " << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    int sorted = sort(arr , size);

    cout << endl << "After sorting : " << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}