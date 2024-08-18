#include <iostream>
using namespace std;

int main()
{

    // int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // this method can be put element in row wise

    // int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // this method can be put element in your wise

    int arr[3][4];

    // ^ Taking input from user
    /*
        row = i
        column = j
     */

    // * Taking input - Row wise
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cin >> arr[i][j];
    //     }
    // }

    // * Taking input - Column wise
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[j][i];
        }
    }

    // * Printing
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}