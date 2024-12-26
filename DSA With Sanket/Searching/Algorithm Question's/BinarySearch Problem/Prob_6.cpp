
//!  Book Allocation Problem:
//^ lecture No : 15
// https://www.naukri.com/code360/problems/ayush-and-ninja-test_1097574?source=youtube&campaign=love_babbar_codestudio2&leftPanelTabValue=SUBMISSION
/* 
     problem statement
^   Ayush is studying for ninjatest which will be held after 'N' days, And to score good marks he has to study 'M' chapters and the ith chapter requires TIME[i] seconds to study. The day in Ayush’s world has 100^100 seconds. There are some rules that are followed by Ayush while studying.
^   
^   1. He reads the chapter in a sequential order, i.e. he studies i+1th chapter only after he studies ith chapter.
^   
^   2. If he starts some chapter on a particular day he completes it that day itself.
^   
^   3. He wants to distribute his workload over 'N' days, so he wants to minimize the maximum amount of time he studies in a day.
^   
^   Your task is to find out the minimal value of the maximum amount of time for which Ayush studies in a day, in order to complete all the 'M' chapters in no more than 'N' days.
^   
^   For example
^   
^   if Ayush want to study 6 chapters in 3 days and the time that each chapter requires is as follows:
^   Chapter 1 = 30
^   Chapter 2 = 20
^   Chapter 3 = 10
^   Chapter 4 = 40
^   Chapter 5 = 5
^   Chapter 6 = 45
^   
^   Then he will study the chapters in the following order 
^   
^   | day 1 : 1 , 2 | day 2 : 3 , 4 | day 3 : 5 , 6 |
^   Here we can see that he study chapters in sequential order and the maximum time to study on a day is 50, which is the minimum possible in this case.

 */

#include <iostream>
#include <algorithm>
using namespace std;

// Function to check if it's possible to allocate books such that each student gets at most 'mid' pages
bool isPossible(int time[], int n, int m, int mid)
{
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (pageSum + time[i] <= mid)
        {
            pageSum += time[i];
            cout << "pageSum is " << pageSum << endl; 
        }
         
        else
        {
            studentCount++;
            cout << "studentCount is " << studentCount << endl;

            if (studentCount > m || time[i] > mid)
            {
                return false;
            }
            pageSum = time[i];
            cout << "pageSum in else part is " << pageSum << endl;
        }
    }
    cout << endl;
    return true;
    cout << "isPossible value is " << true << endl;
}

// Function to find the minimum number of students required to distribute the books
long long BinarySearch(int time[], int n, int m)
{
    int start = 0;
    int sum = 0;
    int ans = -1;

    // Calculate the total number of pages
    for (int i = 0; i < n; i++)
    {
        sum += time[i];
    }

    cout << "sum of pages is " << sum << endl;

    int end = sum;
    int mid = start + (end - start) / 2;

    cout << "Initial mid is " << mid << endl;

    while (start <= end)
    {
        if (isPossible(time, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
            cout << "Updated ans is " << ans << endl;
            cout << "Updated end is " << end << endl;
        }
        else
        {
            start = mid + 1;
            cout << "Updated start is " << start << endl;
        }
        mid = start + (end - start) / 2;

        cout << "Updated mid is " << mid << endl;
    }

    return ans;
}

int main()
{
    int time[] = {10, 20, 30, 40};
    int n = sizeof(time) / sizeof(time[0]);
    int m = 2; // Number of students

    long long result = BinarySearch(time, n, m);
    cout << "Minimum number of students required: " << result << endl;

    return 0;
}