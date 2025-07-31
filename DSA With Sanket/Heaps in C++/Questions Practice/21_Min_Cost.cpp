#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {4,3,2,6};

    priority_queue<int , vector<int> , greater<int>> minHeap(arr.begin(), arr.end());

    int cost = 0;

    while(minHeap.size() > 1) {

        int a = minHeap.top();
        minHeap.pop();

        int b = minHeap.top();
        minHeap.pop();

        int sum = a + b;

        cost += sum;

        minHeap.push(sum);
    }


    cout << "Cost is : " << cost << endl;

 return 0;
}