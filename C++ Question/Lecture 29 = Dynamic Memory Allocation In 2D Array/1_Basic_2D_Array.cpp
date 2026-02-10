#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    // ! creating a 2D array with n*n
    int **arr = new int *[n];

    // creating 2D array
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    // taking input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // printing 2D array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

//     //?taking input in the form of n*m


// //?  releasing the memory
//   for(int i = 0 ; i < n ; i++){
//     delete [] arr[i];
//   }

//   delete [] arr;

//&---------------------------------------------------------------------
    int row;
    int col;
    cout << "Enter the number of rows and columns : ";
    cin >> row >> col;

    //! creating an 2D array with row and col -->  n * m

    int **arr2 = new int *[row];
    for (int i = 0; i < row; i++)
    {
        arr2[i] = new int[col];
    }

    // taking input
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
               cin >> arr2[i][j]  ;
            }
        }


    // printing 2D array

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

