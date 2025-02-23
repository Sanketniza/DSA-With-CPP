#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void Merge(vector<int> arr1, int n, vector<int> arr2, int m, vector<int> arr3) {

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n && j < m ) {

        if(arr1[i] < arr2[j] ) {
            arr3[k++] = arr1[i++];
        } 

        else {
            arr3[k++] = arr2[j++];
        }
    }

    while(i < n) {
        arr3[k++] = arr1[i++];
    }

    while(j < m) {
        arr3[k++] = arr2[j++];
    }

    sort(arr3.begin(), arr3.end());

    for(int i = 0; i < n + m; i++) {
        cout << arr3[i] << " ";
    }

    

    cout << endl;
}

int main() {

    vector<int> arr1 = {1, 3, 15, 7 , 10};
    vector<int> arr2 = {2, 4, 6, 8};
    int n = arr1.size();
    int m = arr2.size();

    vector<int> arr3(n + m);

    //stl way

    merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), arr3.begin() );

    for(int i = 0; i < n + m; i++) {
        cout << arr3[i] << " ";
    }

    cout << endl;

    Merge(arr1, n, arr2, m, arr3);
    
 return 0;
}