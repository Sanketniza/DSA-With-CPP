/* 
    ? Shop in Candy Store
    ? https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1

        In a candy store, there are n different types of candies available and the prices of all the N different types of candies are provided to you. You are now provided with an attractive offer.
    For every candy you buy from the store and get K other candies ( all are different types ) for free. Now you have to answer two questions. Firstly, you have to find what is the minimum amount of money you have to spend to buy all the n different candies. Secondly, you have to find what is the maximum amount of money you have to spend to buy all the n different candies.
    In both the cases you must utilize the offer i.e. you buy one candy and get k other candies for free.

    Examples :

    Input: n = 4, k = 2, candies[] = {3 2 1 4}
    Output: 3 7
    Explanation: As according to the offer if you buy one candy you can take at most two  more for free. So in the first case, you buy the candy which costs 1 and takes candies worth 3 and 4 for free, also you buy candy worth 2 as well.So min cost : 1+2 =3. In the second case, you can buy the candy which costs 4 and takes candies worth 1 and 2 for free, also you need to buy candy worth 3 as well. So max cost : 3+4 =7.
    Input: n = 5, k = 4, candies[] = {3 2 1 4 5}
    Output: 1 5
    Explanation: For minimimum cost buy the candy with the cost 1 and get all the other candies for free. For maximum cost buy the candy with the cost 5 and get all other candies for free.
 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    int n = 4;
    int k = 2;
    vector<int> candies = {3 , 2 , 1 , 4};

    // int candies[] = {3 , 2 , 1 , 4};
    // sort(candies , candies + n);

    sort(candies.begin() , candies.end());

    int minCost = 0;
    int maxCost = 0;

    int buy = 0;
    int free = n - 1;

    while(buy <= free) {
        minCost += candies[buy];
        buy++;
        free -= k;
    }

    buy = n - 1;
    free = 0;

    while(buy >= free) {
        maxCost += candies[buy];
        buy--;
        free += k;
    }

    cout << minCost << " " << maxCost << endl;

    
 return 0;
} 