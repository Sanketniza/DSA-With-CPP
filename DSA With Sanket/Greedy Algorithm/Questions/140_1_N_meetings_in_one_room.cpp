/* 
    ? N meetings in one room
    ? https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

    You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 

    Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

    Examples :

    Input: start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
    Output: 4
    Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)
    Input: start[] = [10, 12, 20], end[] = [20, 25, 30]
    Output: 1
    Explanation: Only one meetings can be held with given start and end timings.
    Input: start[] = [1, 2], end[] = [100, 99]
    Output: 1

 */
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

static bool cmp(pair<int , int> a , pair<int , int> b) {
    return a.second < b.second;
}

int main() {

    vector<int> start = {1 , 3 , 0 , 5 , 8 , 5};
    vector<int> end = {2 , 4 , 6 , 7 , 9 , 9};
    int n = start.size();

    vector<pair<int , int> > v;

    //& Inserting the start and end time of the meetings in the vector
    for(int i = 0; i < n; i++) {

        pair<int , int> p = make_pair(start[i] , end[i]);
        v.push_back(p);

        // v.push_back({end[i] , start[i]});
    }

    //& Sorting the vector according to the end time of the meetings

    /* sort(v.begin() , v.end() , [&](pair<int%20,%20int>%20a%20,%20pair<int%20,%20int>%20b) {
        return a.second < b.second;
    }); */

    // sort(v.begin() , v.end() , cmp);

    //& Selecting the first meeting

    int count = 1;
    int endTime = v[0].second;

    for(int i = 1; i < n; i++) {

        if(v[i].first > endTime) {
            count++;
            endTime = v[i].second;
        }
    }

    cout << "Maximum number of meetings that can be held are : " << count << endl;

 return 0;
} 
