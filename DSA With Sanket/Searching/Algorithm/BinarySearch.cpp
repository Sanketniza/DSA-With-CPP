//! Binary Search

#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int x)
{

    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {

        if (arr[mid] == x)
        { 
            return mid;
        }

        if (arr[mid] > x)
        {
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }

    return -1;
}

int main()
{
    int EvenArr[6] = {2, 4, 6, 8, 10, 12};
    int OddArr[5] = {2, 3, 4, 10, 40};
    int key = 10;

    int OddIndex = BinarySearch(OddArr, 5, key);
    cout << "Index of " << key << " is " << OddIndex << endl;

    int EvenIndex = BinarySearch(EvenArr, 6, key);
    cout << "Index of " << key << " is " << EvenIndex << endl;

    return 0;
}