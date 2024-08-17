#include <iostream>
using namespace std;

// ! solve Linear search with recursion 

void print(int arr[], int n)
{

    cout << "size of array: " << n << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool linearSearch(int arr[], int n, int key)
{

    //* understand how this algorithm works
    print(arr, n);

    // base case
    if (n == 0)
    {
        return false;
    }

    if (arr[0] == key)
    {
        return true;
    }

    else
    {
        bool remainingPart = linearSearch(arr + 1, n - 1, key);
        return remainingPart;
    }
}

int main()
{

    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    int result = linearSearch(arr, size, key);

    if (result)
    {
        cout << "Element found at index: " << endl;
    }
    
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}