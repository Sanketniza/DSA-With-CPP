/* 

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , int n) {

    int first = INT_MIN, second = INT_MIN,
    third = INT_MIN;
    
    for (int i=0; i<n; i++) {
        
        // If arr[i] is greater than first,
        // set third to second, second to 
        // first and first to arr[i].
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        }
        
        // If arr[i] is greater than second, 
        // set third to second and second 
        // to arr[i].
        else if (arr[i] > second) {
            third = second;
            second = arr[i];
        }
        
        // If arr[i] is greater than third,
        // set third to arr[i].
        else if (arr[i] > third) {
            third = arr[i];
        }
    }
    
    // Return the third largest element 
    return third;


}

int main() {

    // Method 1: Using three loops
    vector<int> arr = {12, 35, 1, 10, 34, 1 , 18};
    int n = arr.size();

    int fisrt = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(arr[i] > fisrt) {
            fisrt = arr[i];
        }
    }

    int second = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(arr[i] > second && arr[i] < fisrt) {
            second = arr[i];
        }
    }

    int third = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(arr[i] > third && arr[i] < second) {
            third = arr[i];
        }
    }

    cout << "Third largest element is : " << third << endl;

    // Method 2: Using sort
    sort(arr.begin() , arr.end());
    cout << "Third largest element is : " << arr[n - 3] << endl;

    // Method 3: Using priority queue

    priority_queue<int , vector<int> , greater<int>> pq;
    for(int i = 0; i < n; i++) {
        pq.push(arr[i]);
        if(pq.size() > 3) {
            pq.pop();
        }
    }

    cout << "Third largest element is : " << pq.top() << endl;

    // Method 4: Using 

    int x = solve(arr , n);
    cout << "Third largest element is : " << x << endl;



    return 0;

} 