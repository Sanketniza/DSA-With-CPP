
//!  Painter's Partition Problem
//^ https://www.naukri.com/code360/problems/ayush-and-ninja-test_1097574?source=youtube&campaign=love_babbar_codestudio2

//^ lecture No : 15

/*
 Problem statement
Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.



You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.



Example :
Input: arr = [2, 1, 5, 6, 2, 3], k = 2

Output: 11

Explanation:
First painter can paint boards 1 to 3 in 8 units of time and the second painter can paint boards 4-6 in 11 units of time. Thus both painters will paint all the boards in max(8,11) = 11 units of time. It can be shown that all the boards can't be painted in less than 11 units of time.

10 20 30 40


Sample Output 1 :
60
 */

#include <iostream>
using namespace std;

bool isPossible(int arr[], int size, int k, int mid)
{

    int PaintersCount = 1;
    int paintersSum = 0;

    for (int i = 0; i < size; i++)
    {

        if (paintersSum + arr[i] <= mid)
        {
            paintersSum += arr[i];
            cout << "paintersSum is " << paintersSum << endl;
        }

        else
        {
            PaintersCount++;
            cout << "paintersCount is " << PaintersCount << endl;

            if (PaintersCount > k || arr[i] > mid)
            {
                return false;
            }

            paintersSum = arr[i];
            cout << "paintersSum in else part is " << paintersSum << endl;
        }
    }

    cout << endl;
    return true;
}

int BinarySearch(int arr[], int n, int k)
{

    int start = 0;
    int sum = 0;
    int ans = -1;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    cout << "sum of painters is " << sum << endl;
    int end = sum;

    int mid = start + (end - start) / 2;
    cout << "Initial mid is " << mid << endl;

    while (start < end)
    {

        if (isPossible(arr, n , k, mid))
        {
            ans = mid;
            cout << "Updated ans is " << ans << endl;
            end = mid - 1;
            cout << "Updated ans is " << ans << endl;
        }

        else {

            start = mid + 1;
            mid = start + (end - start) / 2;
        }

        mid = start + (end - start) / 2;
        cout << "Updated mid is " << mid << endl;
    }

    return ans;
}

int main()
{

int arr[] = {1,2,3,4,5};
    // int arr[] = {5, 5, 5, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    int result = BinarySearch(arr, size, k);
    cout << endl;
    cout << "The Minimum time required is " << result << endl;

    return 0;
}
