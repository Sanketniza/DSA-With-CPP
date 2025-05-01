#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void heap(vector<int> &v , int n , int i) {
    
    int parent = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && v[left] > v[parent]) {
        parent = left;
    }

    if(right < n && v[right] > v[parent]) {
        parent = right;
    }

    if(parent != i) {
        swap(v[i], v[parent]);
        heap(v, n, parent);
    }
}

int main() {

    vector<int> a = {1, 2, 3, 4, 5, 6};
    vector<int> b = {1, 2, 3, 4};

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

    // above code is not correct it will give wrong output

    // because we are using max heap to merge two heaps
    // so we need to use min heap to merge two heaps

    vector<int> v;
    for(auto i : a) {
        v.push_back(i);
    }

    for(auto i : b) {
        v.push_back(i);
    }

    int n = v.size();

    for(int i = n/2 - 1; i >=0; i-- ) {
        heap(v , n  , i);
    }

    cout << "element in heap are " << endl;
    for(auto i : v) {
        cout << i << " ";
    }
        cout << endl;


 return 0;
}