

/*
^    You are given an m x n integer matrix matrix with the following two properties:
^    
^    Each row is sorted in non-decreasing order.
^    The first integer of each row is greater than the last integer of the previous row.
^    Given an integer target, return true if target is in matrix or false otherwise.
^    
^    You must write a solution in O(log(m * n)) time complexity.
   
^    Example 1:
   
^    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
^    Output: true


^    Example 2:
  
^    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
^    Output: false
^    
^    
^    Constraints:
^    
^    m == matrix.length
^    n == matrix[i].length
^    1 <= m, n <= 100
^    -104 <= matrix[i][j], target <= 104
 */

#include <iostream>
#include <vector>
using namespace std;

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

    cout << endl;

    cout << "Your matrix is: " << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    int target;
    cout << "Enter the target: " << endl;
    cin >> target;

    int row = matrix.size();
    cout << "Size of Row: " << row << endl;
    int col = matrix[0].size();
    cout << "Size of Col: " << col << endl;


    int start = 0;
    int end = row * col - 1;
    int mid = start + (end - start) / 2;
    cout << "Start: " << start << " End: " << end << " Mid: " << mid << endl;


    while (start <= end)
    {

        int element = matrix[mid / col][mid % col];
        cout << "Element: " << element << endl;

        if (element == target)
        {
            cout << "Target found at index: " << mid << endl;
            break;
        }

        else if (element < target)
        {
            start = mid + 1;
        }

        else
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;

        cout << "updated Start: " << start << " updated End: " << end << " updated Mid: " << mid << endl;
    }
    
    return 0;
}