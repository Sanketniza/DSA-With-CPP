
#include<iostream>
using namespace std;

/* int bubbleSort(int arr[] , int n) {

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
        cout << " Pass " << i + 1 << ": ";
        for(int k = 0; k < n ; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
    
}
 */

void bubbleSort(int arr[] , int n  ) {

    // base case
    if (n == 0 || n == 1) {
        return;
    }

    for(int i = 0; i < n - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    bubbleSort(arr , n - 1);

}

int main() {

    int arr[] = {3,5,4,1,2,3,6,9,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Array before sorting: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSort(arr,n);

    cout << "Array after sorting: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;

}