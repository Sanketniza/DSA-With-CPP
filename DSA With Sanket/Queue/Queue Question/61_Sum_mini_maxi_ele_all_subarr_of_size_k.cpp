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
using namespace std;

int main()
{

    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    int n = 7;
    int sum = 0;

    deque<int> maxi(k);
    deque<int> mini(k);

    /*  cout << "Maxi deque: ";
     for (int i = 0; i < maxi.size(); i++) {
         cout << arr[maxi[i]] << " ";
     }
     cout << endl;

     cout << "Mini deque: ";
     for (int i = 0; i < mini.size(); i++) {
         cout << arr[mini[i]] << " ";
     }
     cout << endl; */

    // Process first k elements of array
    for (int i = 0; i < k; i++) {

        /*  cout << "i is " << i << endl;

        cout << "Maxi deque: ";
        for (int i = 0; i < maxi.size(); i++)
        {
            cout << arr[maxi[i]] << " ";
        }
        cout << endl;

        cout << "Mini deque: ";
        for (int i = 0; i < mini.size(); i++)
        {
            cout << arr[mini[i]] << " ";
        }
        cout << endl;

        cout << "size of maxi is " << maxi.size() << endl;
        cout << "size of mini is " << mini.size() << endl;

        cout << "current element in maxi is " << arr[maxi[i]] << endl;
        cout << "current element in mini is " << arr[mini[i]] << endl;

        cout << "maxi front is " << maxi.front() << " and mini front is " << mini.front() << endl
             << endl;
        cout << "maxi back is " << maxi.back() << " and mini back is " << mini.back() << endl
             << endl;

        if (maxi.empty())
        {
            cout << "maxi is empty" << endl
                 << endl;
        }
        else
        {
            cout << "maxi is not empty" << endl
                 << endl;
        }

        if (mini.empty())
        {
            cout << "mini is empty" << endl
                 << endl;
        }

        else
        {
            cout << "mini is not empty" << endl
                 << endl;
        } */
 
//------------------------------------------------
        while (!maxi.empty() && arr[i] >= arr[maxi.back()])
        {
            cout << "sanket 1 :" << arr[maxi.back()] << endl;  
            cout << "while loop 1 entered for maxi" << endl;
            maxi.pop_back();
        }

        while (!mini.empty() && arr[i] <= arr[mini.back()])
        {
            cout << "sanket 2 :" << arr[mini.back()] << endl;
            cout << "while loop 1 entered for mini" << endl;
            mini.pop_back();
        }

//------------------------------------------------
        cout << "outside the while 1 loop " << endl;
        cout << "arr[i] is " << arr[i] << endl;

        maxi.push_back(i);
        cout << "maxi push back " << arr[i] << endl;

        mini.push_back(i);
        cout << "mini push back " << arr[i] << endl;
    }

    cout << endl
         << "-----------------------------------" << endl;

    //       cout << "Maxi deque: ";
    //  for (int i = 0; i < maxi.size(); i++) {
    //      cout << arr[maxi[i]] << " ";
    //  }
    //  cout << endl;

    //  cout << "Mini deque: ";
    //  for (int i = 0; i < mini.size(); i++) {
    //      cout << arr[mini[i]] << " ";
    // }
    // cout << endl
    //      << "------------------" << endl;

    // Process rest of the elements
    for (int i = k; i < n; i++)
    {
        sum += arr[maxi.front()] + arr[mini.front()];
        cout << "sum is " << sum << endl;

        cout << "value of i is " << i << " and arr[i] is " << arr[i] << endl;

        cout << "maxi front is " << arr[maxi.front()] << " and mini front is " << arr[mini.front()] << endl;
        cout << "maxi back is " << arr[maxi.back()] << " and mini back is " << arr[mini.back()] << endl
             << endl;

        // Remove the elements which are out of this window
        while (!maxi.empty() && maxi.front() <= i - k)
        {
            cout << "while loop entered for maxi remove" << endl;
            maxi.pop_front();
        }

        while (!mini.empty() && mini.front() <= i - k)
        {
            cout << "while loop entered for mini remove" << endl;
            mini.pop_front();
        }

        // Add current element at the rear of both deques
        while (!maxi.empty() && arr[i] >= arr[maxi.back()])
        {
            cout << "while loop entered for maxi add" << endl;
            maxi.pop_back();
        }

        while (!mini.empty() && arr[i] <= arr[mini.back()])
        {
            cout << "while loop entered for mini add" << endl;
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    // Sum for the last window
    sum += arr[maxi.front()] + arr[mini.front()];

    cout << sum << endl;

    return 0;
}