#include <iostream>
using namespace std;

void merge(int arr[], int s, int e)
{
    int mid = (s + e) / 2;

    int leng1 = mid - s + 1;
    int leng2 = e - mid;

    int *first = new int[leng1];
    int *second = new int[leng2];

    // copy the first array
    int mainArrayIndex = s;
    for (int i = 0; i < leng1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    // copy the second array
    mainArrayIndex = mid + 1;
    for (int i = 0; i < leng2; i++)
    {
        second[i] = arr[mainArrayIndex++];                
    }

    // merge two array
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while (index1 < leng1 && index2 < leng2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while (index1 < leng1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < leng2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}

void mergeSort(int arr[], int s, int e)
{
    // base case
    if (s >= e)  // 0 or 1 = already sorted
    {
        return;
    }

    int mid = (s + e) / 2;

    // recursive call

    //? first part sorting
    mergeSort(arr, s, mid);

    //? second part sorting
    mergeSort(arr, mid + 1, e);

    //? merge two sorted array
    merge(arr, s, e);
}

int main()
{
    int arr[7] = {15, 1, 1, 1, 45, 45, 45};
    int n = 7;

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
