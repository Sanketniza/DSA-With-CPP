#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> printAdjacency(int node , int e , vector<vector<int>> &edge) {

    // prepare the adjacency list
    vector<vector<int>> ans(node);

    for(int i = 0; i < e; i++) {

        int u = edge[i][0];
        int v = edge[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }
}



int main() {

    int v = 3, E = 2;

    vector<vector<int>> edges = {{2,1}, {2,0}};

    vector<vector<int>> res = printAdjacency(v, E, edges);

 return 0;
}