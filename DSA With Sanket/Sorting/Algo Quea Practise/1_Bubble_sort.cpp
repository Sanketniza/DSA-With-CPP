
#include <iostream>
using namespace std;

void printName(int arr[] , int n){

    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " " << endl;
    }
    cout << endl;
}

int main()
{

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }

        printName(arr ,n);
    
    }
    
cout << endl;
    cout << "Number of in sorted form is " << endl;
     printName(arr ,n);

    

    return 0;
}