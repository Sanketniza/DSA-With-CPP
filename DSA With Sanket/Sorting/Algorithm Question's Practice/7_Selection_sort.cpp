
#include<iostream>
using namespace std;

int main() {

    int arr[] = {5,4,1,2,3,6,98};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < n; i++)  {

        int min = i;

        for(int j = i + 1; j < n; j++)  {

            if(arr[j] < arr[min])  {
                min = j;
            }
        }

        swap(arr[min] ,arr[i]);
    }

    cout << "sorting array is: ";
    for(int i = 0; i < n; i++)  {
        cout << arr[i] << " ";
    }

 return 0;
}