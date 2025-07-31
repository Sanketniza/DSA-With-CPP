#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {1 , -2 , 3 , 4 , 5};
    int k = 2;

    int n = arr.size();

    priority_queue<int> q;

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int sum = 0;
            for(int k = i; k <= j; k++) {
                sum += arr[k];
            }
            q.push(sum);
        }
    }

    for(int i = 0; i < n; i++) {
        cout << q.top() << " ";
        q.pop();
    }


    return 0;

}