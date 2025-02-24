/*
 
283.  


^    Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
^    
^    Note that you must do this in-place without making a copy of the array.
^    
^    
^    
^    Example 1:
^    
^    Input: nums = [0,1,0,3,12]
^    Output: [1,3,12,0,0]
^    Example 2:
^    
^    Input: nums = [0]
^    Output: [0]
^    
^    
^    Constraints:
^    
^    1 <= nums.length <= 104
^    -231 <= nums[i] <= 231 - 1

//* video 20
//* link :https://leetcode.com/problems/move-zeroes/description/
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    int arr[] = {0,0, 1, 0, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    int nonzero = 0;
    cout << nonzero << endl;

    // cout <<"nonzero : " << arr[nonzero ] << endl;

 
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            // cout << "arr[i] : " << arr[i] << " arr[nonzero] : " << arr[nonzero] << endl;
            swap(arr[i], arr[nonzero]);
            nonzero++;
            cout << nonzero << endl;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}