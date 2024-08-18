
#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<vector<int>> arr;
    vector<int> ans;

    arr.resize(4, vector<int>(4));
    // arr.resize(row , vector<int> (col));

    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << endl;

    cout << "Your matrix is: " << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Rotated matrix is: " << endl;

    for (int col = 0; col < 4; col++)
    {

        if (col & 1)
        { // when col value is odd ( 1, 3)

            for (int i = 4 - 1; i >= 0; i--)
            {
                ans.push_back(arr[i][col]);
            }
        }

        else
        { // when col value is even ( 0, 2)
            for (int i = 0; i < 4; i++)
            {
                ans.push_back(arr[i][col]);
            }
        }
    }
    return 0;
}