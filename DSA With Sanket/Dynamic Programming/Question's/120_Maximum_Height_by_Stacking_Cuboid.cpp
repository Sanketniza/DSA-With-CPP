/* 
   ? 120: Maximum Height by Stacking Cuboid
   ? https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/


    Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other.

You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

Return the maximum height of the stacked cuboids.

 

Example 1:



Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
Output: 190
Explanation:
Cuboid 1 is placed on the bottom with the 53x37 side facing down with height 95.
Cuboid 0 is placed next with the 45x20 side facing down with height 50.
Cuboid 2 is placed next with the 23x12 side facing down with height 45.
The total height is 95 + 50 + 45 = 190.
Example 2:

Input: cuboids = [[38,25,45],[76,35,3]]
Output: 76
Explanation:
You can't place any of the cuboids on the other.
We choose cuboid 1 and rotate it so that the 35x3 side is facing down and its height is 76.
Example 3:

Input: cuboids = [[7,11,17],[7,17,11],[11,7,17],[11,17,7],[17,7,11],[17,11,7]]
Output: 102
Explanation:
After rearranging the cuboids, you can see that all cuboids have the same dimension.
You can place the 11x7 side down on all cuboids so their heights are 17.
The maximum height of stacked cuboids is 6 * 17 = 102.

 */

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

int main() {

    vector<vector<int>> cuboids = {{50,45,20},{95,37,53},{45,23,12}};
    int n = cuboids.size();

    // step1 : sort the cuboids based on the daimention
    for(auto &a : cuboids) {
        sort(a.begin() , a.end());
    }

    // step2 : sort the cuboids based on the width or length
    sort(cuboids.begin() , cuboids.end());

    // step3 : apply the LIS on the height
    int ans = solve(n , cuboids);
    cout << "ans is : " << ans << endl;

return 0;
} 