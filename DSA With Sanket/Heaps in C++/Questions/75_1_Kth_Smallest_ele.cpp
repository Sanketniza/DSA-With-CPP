
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main() { 

// todo: solution 1
    int arr[] = {5,1,2,3,77,8,4,5,9,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    int k = 3;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    cout << arr[k-1] << endl;


// todo: solution 2

    vector<int> v = {5,1,2,3,77,8,4,5,9,4};

    int l = 3;
    int m = v.size();

    priority_queue<int> q;

// step 1: 
    for(int i = 0; i <= l; i++) {
        q.push(i);
        // q.push(v[i]);
    }

// step 2: 
    for(int i = k; i < m; i++) {
        if(v[i] < q.top()) {
            q.pop();
            q.push(v[i]);
        }
    }

// step 3:
    cout << "Kth smallest element is: " << q.top() << endl;  

    return 0;
}