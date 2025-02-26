#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1?page=1&category=Arrays&sortBy=submissions
// https://www.geeksforgeeks.org/problems/kth-largest-element5034/1

int kthSmallest(vector<int> &arr , int k , int n) {
    sort(arr.begin() , arr.end());
    return arr[k - 1];
}

int kthLargest(vector<int> &arr , int k , int n) {
    // priority_queue<int> pq;
    // for(int i = 0; i < n; i++) {
    //     pq.push(arr[i]);
    // }

    // for(int i = 0; i < k - 1; i++) {
    //     pq.pop();
    // }

    // return pq.top();

    priority_queue<int , vector<int> , greater<int>> pq;
    for(int i = 0; i < n; i++) {
        pq.push(arr[i]);
        if(pq.size() > k) {
            pq.pop();
        }
    }

    return pq.top();
}

int main() {

    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    int n = arr.size();

    // Method 1: Using sort
    int a = kthSmallest(arr , k , n);
    cout << "kth smallest element is : " << a << endl;

    // Method 2: Using priority queue
    int b = kthLargest(arr , k , n);

    cout << "kth largest element is : " << b << endl;


 return 0;
}