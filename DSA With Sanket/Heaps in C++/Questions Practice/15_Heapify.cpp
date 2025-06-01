#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {4, 3, 2, 6};
    int n = arr.size();

    // Create a min heap
    priority_queue<int , vector<int> , greater<int> > q;
    // priority_queue<int , vector<int> , greater<int> > q(arr.begin(), arr.end());

    for(auto i : arr) {
        q.push(i);
    }

    int cost = 0;

    while (q.size() > 1) {

        int a = q.top();
        q.pop();

        int b = q.top();
        q.pop();

        int sum = a + b;

        cost += sum;

        q.push(sum);
    }

    cout << "Minimum cost to connect ropes: " << cost << endl;

 return 0;
}