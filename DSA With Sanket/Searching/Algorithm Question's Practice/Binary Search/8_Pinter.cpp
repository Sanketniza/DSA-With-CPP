#include<iostream>
#include<vector>
using namespace std;

bool ispossible(vector<int> arr, int n, int k, int mid) {

    int paintercount = 1;
    int boardscount = 0;

    for(int i = 0; i < n; i++) {

        if(boardscount + arr[i] <= mid) {
            boardscount += arr[i];
        }

        else {
            paintercount++;
            if(paintercount > k || arr[i] > mid) {
                return false;
            }
            boardscount = arr[i];
        }
    }
    return true;
}

int binarySearch(vector<int> arr, int n, int k) {

    int s = 0;
    // Change: Calculate the sum of all elements for the upper bound
    int e = 0;
    for (int i = 0; i < n; i++) {
        e += arr[i];
    }
    int ans = -1;

    while (s <= e) {  // Change: Use <= instead of <
        int mid = s + (e - s) / 2;

        if (ispossible(arr, n, k, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;  // Change: Remove the cout statement here
}

int main() {

    vector<int> arr = {2,3,4,5};
    int k = 2;
    int n = arr.size();
    cout << "The size of the array is " << n << endl;

    int result = binarySearch(arr, n, k);
    cout << "The minimum time to paint all boards is " << result << endl;

    return 0;
}