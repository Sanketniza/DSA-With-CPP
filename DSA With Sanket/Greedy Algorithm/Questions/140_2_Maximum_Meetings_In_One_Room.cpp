/* 
    ? Maximum Meetings in One Room
    ? https://www.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1

    There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of meeting i and F[i] is the finish time of meeting i. The task is to find the maximum number of meetings that can be accommodated in the meeting room. You can accommodate a meeting if the start time of the meeting is strictly greater than the finish time of the previous meeting. Print all meeting numbers.

    Note: If two meetings can be chosen for the same slot then choose meeting that finishes earlier.

    Example 1:

    Input:
    N = 6
    S = {1,3,0,5,8,5}
    F = {2,4,6,7,9,9} 
    Output:
    {1,2,4,5}
    Explanation:
    We can attend the 1st meeting from (1 to 2), then the 2nd meeting from (3 to 4), then the 4th meeting from (5 to 7), and the last meeting we can attend is the 5th from (8 to 9). It can be shown that this is the maximum number of meetings we can attend.
    Example 2:

    Input:
    N = 1
    S = {3}
    F = {7}
    Output:
    {1}
    Explanation:
    Since there is only one meeting, we can attend the meeting.

 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:

    vector<int> maxMeetings(int N, vector<int>& start, vector<int>& end) {
        // Create meetings array with {end, start, position}
        vector<vector<int>> meetings;
        for(int i = 0; i < N; i++) {
            meetings.push_back({end[i], start[i], i + 1});
        }
        
        // Sort by end time
        sort(meetings.begin(), meetings.end());
        
        vector<int> result;
        int lastEnd = -1;
        
        // Select meetings
        for(auto& meet : meetings) {
            if(meet[1] > lastEnd) {
                result.push_back(meet[2]);
                lastEnd = meet[0];
            }
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};

int main() {

    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    int N = start.size();
    
    Solution sol;
    vector<int> ans = sol.maxMeetings(N, start, end);
    
    cout << "Selected meetings: ";
    for(int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;

}