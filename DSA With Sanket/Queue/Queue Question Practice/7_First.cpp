#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {-8, 2, 3, -6, 10};
    int k = 2;

    vector<int> ans;

    for (int i = 0; i < arr.size() - 1; i++) {

        bool found = false;

        for (int j = i; j < min(i + k, (int)arr.size()); j++) {
            if (arr[j] < 0) {
                ans.push_back(arr[j]);
                found = true;
                break;
            }
        }

        if (!found) {
            ans.push_back(0);
        }

    }

    cout << "First negative integer for each window of size k: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}