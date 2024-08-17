#include <iostream>
using namespace std;

void merge(int arr1[], int n, int arr2[], int m, int arr3[])
{

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n && j < m)
    {

        if (arr1[i] < arr2[j])
        {

            arr3[k] = arr1[i];
            k++;
            i++;
        }

        else
        {
            arr3[k++] = arr2[j++];
        }
    }

    while (i < n)
    {
        arr3[k++] = arr1[i++];
    }

    while (j < m)
    {
        arr3[k++] = arr2[j++];
    }
}

void print(int arr3[], int n)
{
    cout << "merge sorted array :" ;
    for(int i = 0 ; i < n ; i++) {

        cout << arr3[i] << " ";
    }
}

int main()
{   

    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {0, 2, 6, 8, 9};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[n + m] = {0};

    merge(arr1, n, arr2, m, arr3);
    print(arr3, n + m);

    return 0;
}