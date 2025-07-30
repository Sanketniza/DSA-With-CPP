#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void heap(int i , int n , vector<int> &ans) {

    int parent = i;
    int leftIndex = 2 * i + 1;
    int righIndex = 2 * i + 2;

    if(leftIndex < n && ans[parent] < ans[leftIndex]) {
        parent = leftIndex;
    }

    if(righIndex < n && ans[parent] < ans[righIndex]) {
        parent = righIndex;
    }

    if(parent != i) {
        swap(ans[parent] , ans[i]);
        heap(parent , n , ans);
    }
}

int main() {

    vector<int> v = {1, 2, 3, 4, 5, 6};
    vector<int> v2 = {1, 2, 3, 4};

    vector<int> ans;

    for(auto i : v) {
        ans.push_back(i);
    }

    for(auto i : v2) {
        ans.push_back(i);
    }

    int n = ans.size();

    cout << "Original array is " << endl;
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    // n/2 + 1

    for(int i = n / 2 - 1; i >= 0; i--) {
        heap(i , n , ans);
    }

    cout << "element in heap are " << endl;
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
 return 0;
}