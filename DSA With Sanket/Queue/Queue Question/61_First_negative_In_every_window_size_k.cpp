/* 
    ? lecture 61: First negative integer in every window of size k
    ? link: https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

    Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

    Example 1:

    Input : 
    N = 5
    A[] = {-8, 2, 3, -6, 10}
    K = 2
    Output : 
    -8 0 -6 -6
    Explanation :
    First negative integer for each window of size k
    {-8, 2} = -8
    {2, 3} = 0 (does not contain a negative integer)
    {3, -6} = -6
    {-6, 10} = -6
 */

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {

    int arr[] = {-8, 2, 3, -6, 10};
    int k = 2;
    int n = 5;

    deque<int> q;
    vector<int> ans;
    

    //step 1: store first -ve integer in the queue
    for(int i = 0; i < k; i++) {

        cout << "arr[i]: " << arr[i] << endl;
        cout << "i: " << i << endl;
        if(arr[i] < 0) {
            q.push_back(i);
            cout << "q.push_back: " << i << endl;  // index 0 = -8
         
        }
    }

    // step 2: store ans for first window in the vector
    if(q.size() > 0) {
        ans.push_back(arr[q.front()]);
        cout << "q.front(): " << q.front() << endl;
        cout << "arr[q.front()]: " << arr[q.front()] << endl;
        cout << "ans.push_back: " << ans.front() << endl;
    }
    else {
        ans.push_back(0);
    }

    cout << "First window: " << q.front() << endl;
    cout << "First window: " << arr[q.front()] << endl;

    // step 3: Process for remaining windows 

    for(int i = k; i < n; i++) {

        // remove the first element for the window or array
         if(!q.empty() && i - q.front() >=k ) {
            q.pop_front();
         }

         // check if the current element is -ve
         cout << "current element: " << arr[i] << endl;
         if(arr[i] < 0) {
            q.push_back(i);
            cout << "q.push_back: " << arr[q.back()] << endl;
         }

         // store the first -ve integer in the vector
         cout << "q.size(): " << q.size() << endl;
         if(q.size() > 0) {
            ans.push_back(arr[q.front()]);
            cout << "ans.push_back: " << arr[q.front()] << endl;
         }

         else {
            ans.push_back(0);
            cout << "ans.push_back: "  << endl;
         }
         
         cout << "first element in vecotor: " << ans.front() << endl;
    }

    cout << "first element in vecotor: " << ans.front() << endl;

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

 return 0;
}