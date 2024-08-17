
#include <iostream>
using namespace std;

int FirstOccurrence(int arr[], int n, int key)
{

    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {

        if (key == arr[mid])
        {
            ans = mid;
            end = mid - 1;
        }

        else if (arr[mid] < key)
        {
            start = mid + 1;
        }

        else
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    return ans;
}

int LastOccurrence(int arr[], int n, int key)
{

    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {

        if (key == arr[mid])
        {
            ans = mid;
            start = mid + 1;
        }

        else if (arr[mid] < key)
        {
            start = mid + 1;
        }

        else
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    return ans;
}

int main()
{

    int arr[] = {1, 2, 3, 3, 3, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 3;

    int first = FirstOccurrence(arr, n, key);
    int last = LastOccurrence(arr, n, key);

    cout << "first occurrence is at index : " << first << endl;
    cout << "last occurrence is at index : " << last << endl;

    return 0;
}