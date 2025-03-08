#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int> &arr) {

    for(int i = 0 ; i < arr.size() ; i++) {
        for(int j = 0 ; j < arr.size() - i ; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {  // solving using vector

    vector<int> arr;
    arr.push_back(1);
    arr.push_back(12);
    arr.push_back(3);
    arr.push_back(64);
    arr.push_back(5);

    cout << arr.size() << endl;

    for(int i = 0 ; i < arr.size() ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSort(arr);
    for(int i = 0 ; i < arr.size() ; i++) {
        cout << arr[i] << " ";
    }

 return 0;
}