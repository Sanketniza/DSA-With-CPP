//! Aggressive Cows
//^ lecture = 15

// todo : link ;- -   - - Aggressive Cows: https://bit.ly/3dkuQ2B

/*

Problem statement
You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.


You are also given an integer 'k' which denotes the number of aggressive cows.


You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.


Print the maximum possible minimum distance.


Example:
Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}

Output: 2

Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions {1, 3}. Here distance between cows is 2.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
6 4
0 3 4 7 10 9


Sample Output 1 :
3
*/

#include <iostream>
using namespace std;

bool isPossible(int arr[], int size, int k, int mid)
{

    int cows = 1;
    int prev = arr[0];
    cout << "prev: " << prev << endl;
    cout << "mid: " << mid << endl;
    
    for (int i = 0; i < size; i++)
    {

        if (arr[i] - prev > mid)
        {
            cows++;

            if (cows == k)
            {
                return true;
            }

            prev = arr[i];
        }
    }

    return false;
}

int BinarySearch(int arr[], int size, int k)
{

    int start = 0;
    int end = arr[size - 1] - arr[0];
    cout << "end: " << end << endl;
    int ans = -1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (isPossible(arr, size, k, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main()
{

    int arr[] = {0, 3, 4, 7, 10, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    int result = BinarySearch(arr, size, k);
    cout << "The Minimum distance is " << result << endl;

    return 0;
}