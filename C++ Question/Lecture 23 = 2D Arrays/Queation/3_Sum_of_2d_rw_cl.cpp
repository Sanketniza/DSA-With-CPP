#include <iostream>
using namespace std;

int LargestSumRow(int arr[][3], int row, int col)
{

    int sum = 0;
    int maxi = 0;
    int rowIndex = -1;

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            sum += arr[row][col];
        }

        if (sum > maxi)
        {
            maxi = sum;
            rowIndex = row;
        }
    }

    cout << "largest sum :" << maxi << endl;
    return rowIndex;
}

// !------------------------------------------------------------------------------------
// ? printing sum in row wise
void printSumRow(int arr[][3], int row, int col)
{
    int sum = 0;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }
}

// ? printing sum in column wise
void printSumCol(int arr[][3], int row, int col)
{

    int sum = 0;

    for (int col = 0; col < 3; col++)
    {
        for (int row = 0; row < 3; row++)
        {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }
}

int main()
{

    int arr[3][3];

    // ^ Taking input from user
    cout << "Input : " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    // * Printing
    cout << "element" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    // cout << "Row wise sum is : " <<
    printSumRow(arr, 3, 3);

    cout << endl;

    // cout << "Column wise sum is : "
    printSumCol(arr, 3, 3);
    cout << endl;

    int ans = LargestSumRow(arr, 3, 3);
    cout<< "max row at index :" << ans << endl;

    return 0;
}