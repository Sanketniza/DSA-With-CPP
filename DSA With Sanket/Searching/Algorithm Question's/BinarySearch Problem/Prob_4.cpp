//!  find Pivot element in mounted array

//^ Lecture No : 14
//* find the pivot element.
// todo : link ;-   - Search in a rotated & Sorted array:  https://bit.ly/3rEVSK7

#include <iostream>
using namespace std;

int Pivot(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if (arr[mid] >= arr[mid + 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }

    return start;
}

int main()
{
    int arr[] = {7, 8, 1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 3;

    int result = Pivot(arr, size);
    cout << "Index of pivot element in array is " << result << endl;
    return 0;
}
