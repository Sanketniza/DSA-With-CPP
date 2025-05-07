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

    vector<vector<int>> adj(node);

    for(int i = 0; i < node; i++) {
        adj[i].push_back(i);

        for(int j = 0; j < ans[i].size(); j++) {
            adj[i].push_back(ans[i][j]);
        }

    }
    return adj;

}



int main() {

    int v = 3, E = 2;

    vector<vector<int>> edges = {{2,1}, {2,0}};

    vector<vector<int>> res = printAdjacency(v, E, edges);

    // print the adjacency list
    cout << "Adjacency List:" << endl;
    for(int i = 0; i < res.size(); i++) {
        cout << i << " -> ";
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

 return 0;
}