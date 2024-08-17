#include <iostream>
using namespace std;

void printNo(int arr[], int n)
{

    for (int a = 0; a < n; a++)
    {
        cout << arr[a] << "" << endl;
    }
    cout << endl;
}

int main()
{

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n - 1; i++)
    {

        int minIndex = i;

        for (int k = i + 1; k < n; k++)
        {

            if (arr[k] < arr[minIndex])
            {
                minIndex = k;
            }
        }

        swap(arr[minIndex], arr[i]);

        cout << "First round : " << i;
        printNo(arr, n);
    }

    cout << endl;
    cout << "Final sorted array is : ";
    printNo(arr, n);

    return 0;
}