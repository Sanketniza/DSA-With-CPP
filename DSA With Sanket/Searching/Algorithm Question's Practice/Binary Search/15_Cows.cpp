
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int> arr , int n , int k , int mid) {

    int cowsCount = 1;
    int lastPosition = arr[0];

    for(int i = 0 ; i < n ; i++) {

        if(arr[i] - lastPosition >= mid) {
            cowsCount++;

            if(cowsCount == k ) {
                return true;
            }

            lastPosition = arr[i];
        }
    }

    return false;
}

int cows(vector<int> arr,int n,int k){
        
    sort(arr.begin() , arr.end());
    int start = 0;
    int maxi = -1;

    for(int i = 0; i < n; i++) {
        maxi = max(maxi , arr[i]);
    }

    int end = maxi;
    int ans = -1;
    int mid = start + (end - start)/2;

    while (start <= end) {

        if(isPossible(arr,n,k,mid)) {
            ans = mid;
            start = mid + 1;
        }

        else {
            end = mid - 1;
        }

        mid = start + (end - start)/2;
    }
    
    return ans;

}

int main() {
     
     vector<int> arr = {1,2,3,14,5,6,7,8,9};
     int k = 2;
     int n = arr.size();

    int result = cows(arr,n,k);
    cout << "The final answer is " << result << endl;

 return 0;
}