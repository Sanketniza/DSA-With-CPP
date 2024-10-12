#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {

    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    int n = 8;

    deque<int> q;
    vector<int> ans;

    for(int i = 0; i < k; i++) {

        if(arr[i] < 0) {
            q.push_back(i);
        }
    }

    if(q.size() > 0) {
        // -ve number is present
        ans.push_back(arr[q.front()]);
    }
    else {
        // -ve number is not present
        ans.push_back(0);
    }

    // process for remaining windows

    for(int i = k; i < n; i++) {

        // remove the first element form window
       if(!q.empty() && i - q.front() >= k) {
        q.pop_front();
       }

       // check if the current element is -v
       if(arr[i] < 0) {
        q.push_back(i); // -ve number is present then only push in queue
       }

       if(q.size() > 0) {
        ans.push_back(arr[q.front()]);
       }

       else {
        ans.push_back(0);
       }
    }

    cout << "element in vector: ";
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }


 return 0;
}