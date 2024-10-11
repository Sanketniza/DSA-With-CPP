/*
    ? Sum of minimum and maximum elements of all subarrays of size k.
    ? https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/

    Given an array of both positive and negative integers, the task is to compute sum of minimum and maximum elements of all sub-array of size k.

Examples: 

Input : arr[] = {2, 5, -1, 7, -3, -1, -2}  
        K = 4
Output : 18
Explanation : Subarrays of size 4 are : 
     {2, 5, -1, 7},   min + max = -1 + 7 = 6
     {5, -1, 7, -3},  min + max = -3 + 7 = 4      
     {-1, 7, -3, -1}, min + max = -3 + 7 = 4
     {7, -3, -1, -2}, min + max = -3 + 7 = 4   
     
     Missing sub arrays - 
     
     {2, -1, 7, -3}
     {2, 7, -3, -1}
     {2, -3, -1, -2}
     {5, 7, -3, -1}
     {5, -3, -1, -2}
     and few more -- why these were not considered??
     Considering missing arrays result coming as 27
     
     Sum of all min & max = 6 + 4 + 4 + 4 = 18
 */

#include <iostream>
#include <deque>
#include <climits>
using namespace std;

int main()
{

    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    int n = 7;
    int sum = 0;

    deque<int> maxi(k);
    deque<int> mini(k);

    // Process first k elements of array
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[i] >= arr[maxi.back()])
            maxi.pop_back();

        while (!mini.empty() && arr[i] <= arr[mini.back()])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }

    // Process rest of the elements
    for (int i = k; i < n; i++)
    {
        sum += arr[maxi.front()] + arr[mini.front()];

        // Remove the elements which are out of this window
        while (!maxi.empty() && maxi.front() <= i - k)
            maxi.pop_front();

        while (!mini.empty() && mini.front() <= i - k)
            mini.pop_front();

        // Add current element at the rear of both deques
        while (!maxi.empty() && arr[i] >= arr[maxi.back()])
            maxi.pop_back();

        while (!mini.empty() && arr[i] <= arr[mini.back()])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }

    // Sum for the last window
    sum += arr[maxi.front()] + arr[mini.front()];

    cout << sum << endl;

    return 0;
}