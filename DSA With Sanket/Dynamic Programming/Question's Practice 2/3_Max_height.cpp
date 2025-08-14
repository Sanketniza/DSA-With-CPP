
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 bool check(vector<int> base , vector<int> newbase) {

        if(newbase[0] <= base[0] && newbase[1] <= base[1] && newbase[2] <= base[2]) {
            return true;
        }

        else {
            return false;
        }
    }

    int solve(int n , vector<vector<int>>& a) {

        vector<int> currRow(n + 1 , 0);
        vector<int> nextRow(n + 1 , 0);

        for(int curr = n - 1; curr >= 0; curr--) {

            for(int prev = curr - 1; prev >= -1; prev--) {

                // include
                int taken = 0;
                if(prev == -1 || check(a[curr] , a[prev])) {
                    taken = a[curr][2] + nextRow[curr + 1];
                }

                // exclude
                int notTaken = 0 + nextRow[prev + 1];

                currRow[prev + 1] = max(taken , notTaken);

                nextRow = currRow;
            }
        }
        return nextRow[0];
    }



    int solveM(int n , int curr , int prev , vector<vector<int>> &a) {

        //base case
        if(curr == n) {
            return 0;
        }

        // include
        int take = 0;
        if(prev == -1 || check(a[curr] , a[prev])) {
            take = a[curr][2] + solveM(n , curr + 1 , curr , a);
        }

        // exclude
        int notTake = 0 + solveM(n , curr + 1 , prev , a);

        return max(take , notTake);


    }

int main() {

    vector<vector<int>> cuboids = {{50,45,20},{95,37,53},{45,23,12}};
    int n = cuboids.size();
    // cout << "n is : " << n << endl;
    // int m = cuboids[0].size();
    // cout << "m is : " << m << endl;
    // cout << "sum of cuboids is : " << n * m << endl;

    // step1 : sort the cuboids based on the daimention
    for(auto &a : cuboids) {
        sort(a.begin() , a.end());
    }

    // step2 : sort the cuboids based on the width or length
    sort(cuboids.begin() , cuboids.end());

    // step3 : apply the LIS on the height
    int ans = solve(n , cuboids);
    cout << "ans is : " << ans << endl;

    // recursive approach
    int ans1 = solveM(n , 0 , -1 , cuboids);
    cout << "ans1 is : " << ans1 << endl;

    

return 0;
} 