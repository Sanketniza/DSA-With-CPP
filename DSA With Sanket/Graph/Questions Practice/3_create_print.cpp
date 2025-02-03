#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> printAdjacency(int node , int e , vector<vector<int>> edge) {

    // prepare the adjacency list

    vector<vector<int>> ans(node);

    for(int i = 0; i<e; i++) {

        cout << edge[i][0] << " -> " << edge[i][1] << endl;
        int u = edge[i][0];
        int v = edge[i][1];

        cout << "value of u and v : " << u << " " << v << endl;

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

    int v = 3; // number of vertices
    int e = 3; // number of edges

    vector<vector<int>> edges = {{0,1}, {1,2}, {2,0}};

    vector<vector<int>> r = printAdjacency(v, e, edges);

    cout << "element in ans :" << endl;

    for(int i = 0; i < r.size(); i++) {
        cout << i << " -> ";

        for(int j = 0; j < r[i].size(); j++) {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    return 0;
}