/*
    ? lecture 56 - Next Smaller Element
    ? link - https://www.naukri.com/code360/problems/next-smaller-element_1112581?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM

    Problem statement
You are given an array 'ARR' of integers of length N. Your task is to find the next smaller element for each of the array elements.

Next Smaller Element for an array element is the first element to the right of that element which has a value strictly smaller than that element.

If for any array element the next smaller element does not exist, you should print -1 for that array element.

For Example:

If the given array is [ 2, 3, 1], we need to return [1, 1, -1]. Because for  2, 1 is the Next Smaller element. For 3, 1 is the Next Smaller element and for 1, there is no next smaller element hence the answer for this element is -1.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 10 ^ 5
0 <= ARR [i] <= 10 ^ 9

Time Limit: 1sec.
Sample Input 1:
2
4
2 1 4 3
3
1 3 2
Sample Output 1:
1 -1 3 -1
-1 2 -1
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(curr);
    }
    
    return ans;
}

int main()
{
    vector<int> arr = {2, 1, 4, 3};
    vector<int> ans = nextSmallerElement(arr);

    cout << "The next smaller element for each of the array elements is: ";
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}