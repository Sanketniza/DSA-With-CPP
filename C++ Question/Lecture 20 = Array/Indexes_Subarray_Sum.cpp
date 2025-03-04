#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 15;

    int n = v.size();
    vector<int> prefix(n, 0);

    for(int i = 0; i < n; i++) {
        int sum = 0;

        for(int j = i + 1; j < n; j++ ) {

            sum += v[j];

            if(sum == 15) {
               cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }

 return 0;
}