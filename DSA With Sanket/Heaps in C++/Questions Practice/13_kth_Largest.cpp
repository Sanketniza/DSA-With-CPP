#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {2,8,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;

    vector<int>a;

    for(int i = 0; i < n; i++) {
        int sum = 0;

        for(int j = i; j < n; j++) {
            sum += arr[j];
            a.push_back(sum);
        }
        
    }

    for(auto it : a) {
        cout << it << " ";
    }
    cout << endl;


    priority_queue<int , vector<int> , greater<int> > q;
    vector<int>v;

    for(int i = 0; i < n; i++) {

        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];

            if(q.size() < k) {
                q.push(sum);
            }

            else{
                if(sum > q.top()) {
                    q.pop();
                    q.push(sum);
                }
            }
        }
    }
    
    cout << "Kth largest element is: " << q.top() << endl;
    
    
 return 0;
}