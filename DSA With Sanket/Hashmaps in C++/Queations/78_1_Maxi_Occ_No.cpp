
/* 
    ? lecture 78 - maximum occurrence of number
    ? link : https://www.naukri.com/code360/problems/maximum-frequency-number_920319?leftPanelTab=0
    Ninja is given an array of integers that contain numbers in random order. He needs  to write a program to find and return the number which occurs the maximum times in   the given input. He needs your help to solve this problem.
 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main() { 

    int arr[] = {0,1,2,3,4,5,6,1,2,5,4,1,2,3,1,5,4,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);


    unordered_map<int, int> mp;

    for(int i = 0; i < n; i++) { 
       mp[arr[i]]++; 
    }

    for(auto i:mp) { 
        cout << i.first << " : " << i.second << endl; 
    }
    cout << endl;

    int maxi = INT_MIN;
    int ans = -1;

    for(auto i:mp) {
        if(i.second > maxi) {
            maxi = i.second;
            ans = i.first;
        }
    }

    cout << "Most repeated element is " << ans << endl;
    cout << "Maxi Occ No is " << maxi << endl;

    return 0;
}