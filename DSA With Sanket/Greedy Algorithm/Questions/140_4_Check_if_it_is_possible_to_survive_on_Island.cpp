/* 
    ? Check if it is possible to survive on Island
    ? https://www.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1

    Geekina got stuck on an island. There is only one shop on this island and it is open on all days of the week except for Sunday. Consider following constraints:

    N – The maximum unit of food you can buy each day.
    S – Number of days you are required to survive.
    M – Unit of food required each day to survive.
    Currently, it’s Monday, and she needs to survive for the next S days.
    Find the minimum number of days on which you need to buy food from the shop so that she can survive the next S days, or determine that it isn’t possible to survive.

    Example 1:

    Input: S = 10, N = 16, M = 2
    Output: 2
    Explaination: One possible solution is to 
    buy a box on the first day (Monday), 
    it’s sufficient to eat from this box up to 
    8th day (Monday) inclusive. Now, on the 9th 
    day (Tuesday), you buy another box and use 
    the chocolates in it to survive the 9th and 
    10th day.
    Example 2:

    Input: S = 10, N = 9, M = 8
    Output: -1
    Explaination: Let's start by detailing the days of the week and the net number of food units available after purchasing and consuming them:
    Monday - Net 1 food unit available.
    Tuesday - Net 2 food units available.
    Wednesday - Net 3 food units available.
    Thursday - Net 4 food units available.
    Friday - Net 5 food units available.
    Saturday - Net 6 food units available.
    Sunday - 6 food units available and that is not sufficient amount of food units to survive and you can't buy more on Sunday.
    Your Task:
    You do not need to read input or print anything. Your task is to complete the function minimumDays() which takes S, N, and M as input parameters and returns the minimum number of days Geekina needs to buy food. Otherwise, returns -1 if she cannot survive.

    Expected Time Complexity: O(1)
    Expected Auxiliary Space: O(1)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    int S = 10;
    int N = 16;
    int M = 2;

    /*  
         For Input:  --> work for this input
         10 9 8 (Here S = 10, N = 9, M = 8)
         your output is: -1
    */
    int sunday = S / 7;
    int buyDay = S - sunday;
    int totalFood = S * M;
    int ans = 0;

    if(totalFood % N == 0) {
        ans = totalFood / N;
    } else {
        ans = totalFood / N + 1;
    }

    if(ans <= buyDay) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    
 return 0;
}