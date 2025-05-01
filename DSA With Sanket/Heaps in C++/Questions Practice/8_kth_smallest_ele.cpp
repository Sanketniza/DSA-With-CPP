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
            // cout << "popped: " << q.top() << endl;
            q.push(arr[i]);

        }
    }

    cout << q.top() << endl;
 return 0;
}