#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr) {

    int n = arr.size();

    int a = 0;
    int b = arr[0];

    for(int i = 1; i < n; i++) {

        int include = a + arr[i];
        int exclude = a + b;

        int temp = max(include, exclude);
        a = b;
        b = temp;
    }

    return b;
}

int main() {

    vector<int> arr = {1 , 5, 1, 2, 6};
    int n = arr.size();

    // base case
    if(n == 0) {
        cout << 0 << endl;
        return 0;
    }

    if(n == 1) {
        cout << arr[0] << endl;
        return 0;
    }

    vector<int> first , second;

    for(int i = 0; i < n; i++) {

        if(i != n - 1) {
            first.push_back(arr[i]);
        }

        if(i != 0) {
            second.push_back(arr[i]);
        }
    }

    int solution = max(solve(first) , solve(second));

    cout << solution << endl;

 return 0;
}