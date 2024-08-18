
/*
^       • 240. Search a 2D Matrix II
^   
^       Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
^   
^   Integers in each row are sorted in ascending from left to right.
^   Integers in each column are sorted in ascending from top to bottom.
^   
^   
^   Example 1:
^   
^   
^  Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
^   Output: true
^   Example 2:
^   
^   
^   Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
^   Output: false
^   
^   
^   Constraints:
^   
^   m == matrix.length
^   n == matrix[i].length
^   1 <= n, m <= 300
^   -109 <= matrix[i][j] <= 109
^   All the integers in each row are sorted in ascending order.
^   All the integers in each column are sorted in ascending order.
^   -109 <= target <= 109

 */

#include <iostream>
#include <vector>
using namespace std;

bool BinarySearch(vector<vector<int>> matrix, int target)
{

    int row = matrix.size();
    int col = matrix[0].size();
    cout << "row: " << row << " col: " << col << endl;

    int rowIndex = 0;
    int colIndex = col - 1;
    cout << "rowIndex: " << rowIndex << " colIndex: " << colIndex << endl;

    while (rowIndex < row && colIndex >= 0)
    {

        int element = matrix[rowIndex][colIndex];
        cout << "element: " << element << endl;

        if (element == target)
        {
            return true;
        }

        if (element < target)
        {
            rowIndex++;
            cout << "updated rowIndex: " << rowIndex << endl;
        }
        
        else
        {
            colIndex--;
            cout << "updated colIndex: " << colIndex << endl << endl;
        }

        cout << "update rowIndex: " << rowIndex << " colIndex: " << colIndex << endl;

    }
    return false;
}

int main()
{

    vector<vector<int>> matrix;
    matrix.resize(4, vector<int>(3));
    // matrix.resize(row , vector<int> (col));

    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> matrix[i][j];
        }
        cout << endl;
    }

    cout << endl;

    cout << "Your matrix is: " << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int target;
    cout << "Enter the target: " << endl;
    cin >> target;

    int ans = BinarySearch(matrix, target);
    cout << "Answer: " << ans << endl;

    return 0;
}

/* #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BinarySearch(vector<int> arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {

        if (arr[mid] == target)
        {
            return mid;
        }

        else if (arr[mid] < target)
        {
            start = mid + 1;
        }

        else
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    return -1;
}

int main()
{
    vector<vector<int>> matrix;

    matrix.resize(4, vector<int>(4));

    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> matrix[i][j];
        }
        cout << endl;
    }

    cout << "Your matrix is: " << endl;

    // Print the matrix
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    // Convert 2D array to 1D array
    vector<int> temp;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            temp.push_back(matrix[i][j]);
        }
    }

    // Print the 1D array
    cout << "1D array representation: ";
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }

    sort(temp.begin(), temp.end());

    cout << "sorted array : ";
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }

    cout << endl;

    int target;
    cout << "Enter the target: " << endl;
    cin >> target;
    int ans = BinarySearch(temp, target);

    cout << ans << endl;

    return 0;
}
 */