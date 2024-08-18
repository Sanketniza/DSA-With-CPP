#include<iostream>
#include<vector>
using namespace std;
 
int main() { 

    vector<vector<int>> matrix;

    matrix.resize(4, vector<int>(4));

    vector<int> ans;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> matrix[i][j];
        }
    }

    //print the matrix

    for(int i = 0; i< 4; i++) {
        for(int j = 0; j < 4; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    int target;
    cout << "Enter the target: " << endl;
    cin >> target;

    int row = matrix.size();
    int col = matrix[0].size();

    int start = 0;
    int end = (row * col) - 1;
    int mid = start + (end - start) / 2;

    while (start <= end) {

        int element = matrix[mid/col][mid%col];

        if(element == target) {
            cout << "Element found at index: " << mid << endl;
            return element;
        }

        else if( element < target) {
            start = mid + 1;
        }

        else if( element > target) {
            end = mid - 1;
        }

        else {
            cout << "Element not found" << endl;
        }
        
         mid = start + (end - start) / 2;
    }

    return 0;
}