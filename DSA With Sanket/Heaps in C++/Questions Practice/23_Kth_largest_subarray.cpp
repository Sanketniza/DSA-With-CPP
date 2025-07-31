#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {1 , -2 , 3 , 4 , 5};
    int k = 2;

    int n = arr.size();

    priority_queue<int , vector<int> , greater<int>> q;

    for(int i = 0; i < n; i++) {

        int sum = 0;

        for(int j = i; j < n; j++) {
            sum += arr[j];

            if(q.size() < k) {
                q.push(sum);
            }

            else {
                if(sum > q.top()) {
                    q.pop();
                    q.push(sum);
                }
            }
        }
    }

    cout << "kth largest sum is : " << q.top() << " " << endl;


    return 0;

}