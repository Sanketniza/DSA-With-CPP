#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<vector<int>> edge , int n , int e) {
    
    // adj list 
    unordered_map<int , list<pair<int, int>>> adj;
}

int main() {

    int n = 5;
    int e = 5;

    vector<vector<int>> edge(e , vector<int>(2));

   for(int i = 0; i < e; i++) {
       cin >> edge[i][0] >> edge[i][1];

   }

   vector<vector<int>> result = solve(edge , n , e);

   for(auto i : result ){
        for(auto j : i) {
           cout << j << " ";
        }
       cout << endl;
    }
    
 return 0;
}