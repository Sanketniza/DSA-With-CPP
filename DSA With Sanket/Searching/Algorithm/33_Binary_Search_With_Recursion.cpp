#include <iostream>
using namespace std;

void print(int arr[], int start, int end)
{

    cout << "size of array: " << end - start + 1 << endl;
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool BinarySearch(int arr[], int start, int end, int key)
{

    print(arr, start, end);

    // base case

    if (start > end)
        return false;

    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
        return true;


    if (arr[mid] < key)
    {
        return BinarySearch(arr, mid + 1, end, key);
    }

    else
    {
        return BinarySearch(arr, start, mid - 1, key);
    }
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int start = 0;
    int key = 15;

    cout << "Element in found or not : " << BinarySearch(arr, start, size, key);

    return 0;
}