#include <iostream>
using namespace std;

bool isPresent(int arr[][4], int target, int row, int col)
{

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (arr[row][col] == target)
            {
                return true;
            }
        }
    }
    return false;
}


int main()
{

    int arr[3][4];

    // ^ Taking input from user
    cout << "Input : " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }

    // * Printing
    cout << "element" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

   // * selecting target values
    int target;
    cout << "Enter your target: ";
    cin >> target;

    if (isPresent(arr, target, 3, 4) )
    //           (array, target, row, col)
    {
        cout << "Element is found " << endl;
    }

    else
    {
        cout << "Element is not found" << endl;
    }

    return 0;
}