
#include<iostream>
using namespace std;

int main() {
    
    int arr[3][2];

    // taking input row wise
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 2; col++) {
            cin >> arr[row][col];
        }
    }

    //print row wise
  for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 2; col++) {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }

    
 return 0;
}