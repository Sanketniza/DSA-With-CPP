/* 
    ? lecture 78 - maximum occurrence of number
    ? link : https://www.naukri.com/code360/problems/maximum-frequency-number_920319?leftPanelTab=0
    ? https://www.geeksforgeeks.org/maximum-occurrence-element-array/

    Maximum Frequency Number
Easy
0/40
Average time to solve is 10m
Contributed by
91 upvotes
Asked in companies
Problem statement
Ninja is given an array of integers that contain numbers in random order. He needs to write a program to find and return the number which occurs the maximum times in the given input. He needs your help to solve this problem.

If two or more elements contend for the maximum frequency, return the element which occurs in the array first i.e. whose index is lowest.

For example,

For 'arr' = [ 1, 2, 3, 1, 2]. you need to return 1.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 5
1 <= N <= 10000
-10 ^ 3 <= |arr| <= 10 ^ 3

Time Limit: 1 sec
Sample Input 1:
1 
13
2 12 2 11 -12 2 -1 2 2 11 12 2 -6 
Sample Output 1:
2
Explanation of Sample Input 1:
Test case 1:
For the first test case of sample output 1, as we start traveling the array, ‘2’ has the highest frequency, hence our answer is ‘2’.
Sample Input 2:
2 
3
4 -5 1
4
1 -2 1 -2
Sample Output 2:
4
-2
Explanation of Sample Input 2:
Test case 1:
For the first test case of sample output 2, as all the elements have only occurred once, so we will take the first element that has occurred once. Therefore our output will be ‘4’.

Test case 2:
-2 has the highest frequency.
 */

#include<iostream>
#include<unordered_map>
using namespace std;
 
int main() { 

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8,1,2,4,5,3,2,1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    unordered_map<int, int> mp;

    int MaxiFre = 0;
    int MaxAns = 0;

    for(int i = 0; i < n; i++) { 
       mp[arr[i]]++; 
       MaxiFre = max(MaxiFre, mp[arr[i]]);
    }

    cout << "Maximum frequency element is " << MaxAns << endl;
    cout << "Maximum frequency is " << MaxiFre << endl;

    for(int i = 0; i < n; i++) { 
        if(mp[arr[i]] == MaxiFre) { 
            MaxAns = arr[i];
            break;
        }
    }

    cout << "Maximum frequency element is " << MaxAns << endl;
    


    return 0;
}