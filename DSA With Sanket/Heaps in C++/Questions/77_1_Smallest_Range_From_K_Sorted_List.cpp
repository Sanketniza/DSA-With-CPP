
/* 
    ? lecture : 77 
    ? Smallest Range From K Sorted Lists
    ? link : https://www.geeksforgeeks.org/smallest-range-from-k-sorted-arrays/
    ? https://www.naukri.com/code360/problems/smallest-range-from-k-sorted-list_1069356?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

    Problem statement
You are given ‘K’ lists containing non-negative integers. Each list has a size ‘N’ and is sorted in non-decreasing order. You need to find the minimum length of a range such that at least one element of each list must be included in that range.

For example :

If we have 3 lists as [1, 10, 11], [2, 3, 20], [5, 6, 12] then the [1, 5] is the range that includes 1 from the first list, 2,3 from the second list, and 5 from the third list i.e, this range contains at least one element from each list.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= 'T' <= 50
1 <= 'N' <= 10 ^ 4  
1 <= 'K' <= 10 ^ 4  
1 <= 'N' * 'K' <= 10 ^ 4
1 <= 'VAL' <= 10 ^ 9

Where 'VAL' is the value of any element of any list.

Time Limit: 1 sec
Sample Input 1 :
2
3 2
2 4 5
5 6 7
2 3
1 1
9 12
4 9
Sample Output 1 :
1
9
Explanation For Sample Input 1 :
Test case 1 :
The given list are [2, 4, 5], [5, 6, 7]. The range [5, 5] will include 5 which is present in both the list and hence the length of this range is 1. This is the only possible range having the minimum length.

Test case 2 :
The given list are [1, 1], [9, 12], [4, 9]. The range [1, 9] will include 1 which is present in the first list, and 9 which include in both the second and third list  The length of the range is 9 (9 - 1 + 1 = 9).
Sample Input 2 :
2
3 3
4 7 30
1 2 12
20 40 50
5 1
3 6 8 12 31
Sample Output 2 :
14
1
Explanation For Sample Input 2 :
Test case 1 :
The given list are [4, 7, 30], [1, 2, 12] and [20, 40, 50]. The range [7, 20], hence the length of this range is 14. This is the only possible range having the minimum length.

Test case 2 :
The range [3, 3] will include 3 which is present in the first list. The length of the range is 1. Infect, we can select any of element present in first list as there is only one list given to us.
 */

#include<iostream>
using namespace std;
 
int main() { 

    

    return 0;
}