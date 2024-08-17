#include<iostream>
#include<vector>
using namespace std;

void reverseArray(vector<int> arr , int n) {

    int s = n ;
    int e = arr.size() - 1;

    while (s <= e) {

        swap(arr[s] , arr[e]);
        s++;
        e--;
    }

    cout << "reverse array : " << endl;
    for(int i : arr) {
        cout << i << " ";
    }
}
 
int main() { 

    vector <int > arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);

    int n = 3;

    for(int i : arr) {
        cout << i << " ";
    }

    cout << endl;

     reverseArray(arr , n);

    return 0;
}