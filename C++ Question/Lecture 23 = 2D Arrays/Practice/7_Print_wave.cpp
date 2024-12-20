
#include<iostream>
#include<vector>
using namespace std;

int main() {

    vector <vector<int>> arr;
    vector <vector<int>> ans;
    arr.resize(3 , vector<int>(3));

    // take input  row wise
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }

    }


    // print output
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 ; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for(int col = 0; col < 3; col++) {

        if(col &1) {

            for(int i = 3 - 1; i >= 0; i--) {
                ans.push_back(arr[i][col]);
            }
            cout << endl;
        }

        else{

            for(int i = 0; i < 3 ; i++) {
                ans.push_back(arr[i][col]);
            }

        }
    }

    cout << "Print the matrix in a sine wave order: " << endl;

    for (int i = 0; i < ans.size(); i++)
    {
       cout << ans[i];
    }


 return 0;
}