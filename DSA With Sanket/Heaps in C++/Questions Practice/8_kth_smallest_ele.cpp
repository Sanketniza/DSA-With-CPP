#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {2,8,10,5,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    priority_queue<int> q;

    for(int i = 0; i < k; i++) {
        q.push(arr[i]);
    }

    for(int i = k; i < n; i++) {
        cout << "top: " << q.top() << endl;
        if(arr[i] < q.top()) {
            q.pop();
            q.push(arr[i]);
        }
    }

    cout << q.top() << endl;

    //second method
    //? time complexity is O(nlogk)
    //? space complexity is O(k)
    //? here we are using min heap to find kth largest element

    priority_queue<int , vector<int> , greater<int>> p;

    for(int i = 0; i < n; i++) {
        p.push(arr[i]);
    }

    for(int i = 0; i < k-1; i++) {
        p.pop();
    }

    cout << "Kth smallest element is: " << p.top() << endl;
    cout << "Kth largest element is: " << q.top() << endl;

    return 0;
}