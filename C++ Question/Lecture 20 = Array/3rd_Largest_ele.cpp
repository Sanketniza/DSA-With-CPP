/* 

 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {12, 35, 1, 10, 34, 1 , 18};
    int n = arr.size();

    int fisrt = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(arr[i] > fisrt) {
            fisrt = arr[i];
        }
    }

    int second = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(arr[i] > second && arr[i] < fisrt) {
            second = arr[i];
        }
    }

    int third = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(arr[i] > third && arr[i] < second) {
            third = arr[i];
        }
    }

    cout << "Third largest element is : " << third << endl;

    return 0;

} 