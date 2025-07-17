#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> printAdjacency(int node , int edge , vector<vector<int>> &edges) {

    vector<vector<int>> adj(node);

    for(int i = 0; i < edge; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans(node);

    for(int i = 0; i < node; i++) {
        ans[i].push_back(i);

        for(int j = 0; j < adj[i].size(); j++) {
            ans[i].push_back(adj[i][j]);
        }

    }

    return ans;
}

int main() {

    int v = 3;
    int e = 2;

    vector<vector<int>> edges = {{2,1}, {2,0}};

    vector<vector<int>> result = printAdjacency(v , e , edges);

    cout << "element in ans :" << endl;

    for(int i = 0; i < v; i++) {
        cout << i << " -> " << endl;

        for(int j = 0; j < result.size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }


 return 0;
}