/* 
    ? Activity Selection
    ? https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1
    
    Given some activities with their start and end day given in array start[] and end[]. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a given day.

    Note : Duration of the activity includes both starting and ending day.

    Examples:

    Input: start[] = [2, 1], end[] = [2, 2]
    Output: 1
    Explanation: A person can perform only one of the given activities.
    Input: start[] = [1, 3, 2, 5], end[] = [2, 4, 3, 6]
    Output: 3
    Explanation: A person can perform activities 1, 2 and 4.
    Input: start[] = [1, 3, 0, 5, 8, 5], end[] = [2, 4, 6, 7, 9, 9]
    Output: 4
    Explanation: A person can perform activities 0, 1, 3, and 4.
    */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> start = {1, 3, 2, 5};
    vector<int> end = {2, 4, 3, 6};

    vector<pair<int, int>> v;

    for(int i = 0; i < start.size(); i++) {
        v.push_back({end[i], start[i]});
    }

    sort(v.begin(), v.end());

    int ans = 1;
    int last = v[0].first;

    for(int i = 1; i < v.size(); i++) {

        if(v[i].second > last) {
            ans++;
            last = v[i].first;
        }
    }

    cout << "ans is : " << ans << endl;

 return 0;
 
}    