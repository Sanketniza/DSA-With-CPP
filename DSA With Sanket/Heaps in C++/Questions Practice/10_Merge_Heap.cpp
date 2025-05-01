#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};

    priority_queue<int> q;

    for(int i = 0; i < a.size(); i++) {
        q.push(a[i]);
    }

    for(int i = 0; i < b.size(); i++) {
        q.push(b[i]);
    }

    vector<int> ans;
    while(!q.empty()) {
        ans.push_back(q.top());
        q.pop();
    }

    cout << "Merged Heap: ";
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    cout << "Size of Merged Heap: " << ans.size() << endl;
    cout << "Max Element: " << ans[0] << endl;
 return 0;
}