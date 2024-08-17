
// !  First and Last Position of an Element In Sorted Array
//^ lecture : 13
//* https://www.naukri.com/code360/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?source=youtube&campaign=love_babbar_codestudio2

/*

^  First and Last Position of an Element In Sorted Array

^  Average time to solve is 15m
^  750 upvotes
^

~  Problem statement
^  You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.

^  Now, your task is to find the first and last occurrence of ‘k’ in 'arr'.

^  Note :
^  1. If ‘k’ is not present in the array, then the first and the last occurrence will be -1.
^  2. 'arr' may contain duplicate elements.
^
^
^  Example:
^  Input: 'arr' = [0,1,1,5] , 'k' = 1
^
^  Output: 1 2
^
^  Explanation:
^  If 'arr' = [0, 1, 1, 5] and 'k' = 1, then the first and last occurrence of 1 will be 1(0 - indexed) and 2.
^
^
^  Detailed explanation ( Input/output format, Notes, Images )
^  Sample Input 1: 
^  8 (size of arr) 2 (k)
^  0 0 1 1 2 2 2 2
^
^
^  Sample output 1:
^  4 7
^
^
^  Explanation of Sample output 1:
^  For this testcase the first occurrence of 2 in at index 4 and last occurrence is at index 7.
^
^
^  Sample Input 2:
^  4 2
^  1 3 3 5
^
^
^  Sample output 2:
^  -1 -1
^
^
^  Expected Time Complexity:
^  Try to do this in O(log(n)).
^
^
^  Constraints:
^  1 <= n <= 10^5
^  0 <= k <= 10^9
^  0 <= arr[i] <= 10^9

 */

#include <iostream>
using namespace std;

int FirstOccurrence(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {

        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1;
        }

        else if (arr[mid] < key)
        {
            start = mid + 1;
        }

        else if (arr[mid] > key)
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    return ans;
}

int LastOccurrence(int arr[], int n, int key)
{

    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            start = mid + 1;
        }

        else if (arr[mid] < key)
        {
            start = mid + 1;
        }

        else if (arr[mid] > key)
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    return ans;
}

int main()
{

    int EvenArr[] = {2, 4, 6, 8, 10, 10, 12};
    int n = sizeof(EvenArr) / sizeof(EvenArr[0]);
    int EvenKey = 10;
    // int EvenKey = 2;

    int EvenIndex1 = FirstOccurrence(EvenArr, n, EvenKey);
    int EvenIndex2 = LastOccurrence(EvenArr, n, EvenKey);
    cout << "FOr Index of EvenArray " << EvenKey << ". The First Occurrence is " << EvenIndex1 << " and Last Occurrence of  is " << EvenIndex2 << endl;
    // cout << "Index of EvenArray " <<  EvenKey << "The First Occurrence is " << EvenIndex1 << "and Last Occurrence of  is " << LastOccurrence(EvenArr, n, EvenKey) << endl;

    int OddArr[] = {2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 5, 6, 6};
    int m = sizeof(OddArr) / sizeof(OddArr[0]);
    int Oddkey = 3;
    // int Oddkey = 5;

    int OddIndex1 = FirstOccurrence(OddArr, m, Oddkey);
    int OddIndex2 = LastOccurrence(OddArr, m, Oddkey);
    cout << "FOr Index of OddArray " << Oddkey << ". THe First Occurrence is " << OddIndex1 << " and Last Occurrence of  is " << OddIndex2 << endl;
    // cout << "Index of OddArray " << Oddkey << "THe First Occurrence is " << OddIndex << "and Last Occurrence of  is " << LastOccurrence(OddArr, m, Oddkey) << endl;

    return 0;
}
