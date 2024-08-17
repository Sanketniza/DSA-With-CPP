#include <iostream>
using namespace std;

int main()
{

    int arr[] = {0, 0, 21, 0, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    int nonzero = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[nonzero]);
            nonzero++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}