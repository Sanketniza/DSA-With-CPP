// * Selection Sort

// ^ Lecture No : 16

//& use case = It is used in very small data sets.

#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {6, 2, 8, 4, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        cout << "Current iteration: " << i << endl;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
                cout << "middle element: " << arr[minIndex] << endl;
            }
        }

        cout << "minIndex: " << minIndex << endl;

        // Swap the found minimum element with the first element
        swap(arr[minIndex], arr[i]);
        cout << "found minimum element: " << arr[minIndex] << endl;

        // Print the array after each iteration
        cout << "After pass " << i + 1 << ": ";
        printArray(arr, n);
        cout << endl;
    }

    // Print the sorted array
    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
