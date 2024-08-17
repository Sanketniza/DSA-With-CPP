

/*
Problem statement
For a given two-dimensional integer array/list ‘ARR’ of size (N x M), print the ‘ARR’ in a sine wave order, i.e., print the first column top to bottom, next column bottom to top, and so on.

For eg:-

The sine wave for the matrix:-
1 2
3 4
will be [1, 3, 4, 2].
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
1 <= N <= 100
1 <= M <= 100
0 <= ARR[i][j] <= 100

Time Limit: 1sec
Sample Input 1:
2
3 4
1 2 3 4
5 6 7 8
9 10 11 12
4 4
1 2 4 5
3 6 8 10
11 12 13 15
16 14 9 7
Sample Output 1:
1 5 9 10 6 2 3 7 11 12 8 4
1 3 11 16 14 12 6 2 4 8 13 9 7 15 10 5
 */
#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<vector<int>> arr;
    vector<int> ans;

    arr.resize(4, vector<int>(4));

    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "Print the original matrix: " << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

 cout << "Let check the matrix in a sine wave order: " << endl;
    for (int col = 0; col < 4; col++)
    {

        if (col & 1)
        {

            for (int i = 4 - 1; i >= 0; i--)
            {
                ans.push_back(arr[i][col]);
                cout << ans[i] << " ";
            }
            cout << endl;
        }

        else
        {

            for (int i = 0; i < 4; i++)
            {
                ans.push_back(arr[i][col]);
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }

    cout << endl;

    cout << "Print the matrix in a sine wave order: " << endl;

    for (int i = 0; i < ans.size(); i++)
    {
         cout << ans[i] << " ";
    }

    return 0;
}
