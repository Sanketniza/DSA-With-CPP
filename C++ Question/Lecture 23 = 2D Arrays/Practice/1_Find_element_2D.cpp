#include <iostream>
using namespace std;

bool isPosPresent(int arr[][4], int target, int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            if (arr[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{

    int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int target;
    cout << "Enter your target: ";
    cin >> target;

    if (isPosPresent(arr, target, 3, 4))
    {

        cout << "Element is found " << endl;
    }

    else
    {

        cout << "Element is not found " << endl;
    }

    return 0;
}