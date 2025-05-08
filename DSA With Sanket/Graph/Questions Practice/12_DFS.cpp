#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visit, vector<vector<int>> &result, unordered_map<int, list<int>> &adj) {
   
    visit[node] = true;
    vector<int> ans;
    ans.push_back(node);

    for(auto i : adj[node]) {
        if(!visit[i]) {
            dfs(i, visit, result, adj);
        }
    }
    result.push_back(ans);
}

vector<vector<int>> printAdjacency(int n, int e, vector<vector<int>> &edges) {
    
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visit;
    vector<vector<int>> result;

    for(int i = 1; i <= n; i++ ) {

        if(!visit[i]) {
            dfs(i, visit, result, adj);
        }
    }
    return result;
}

int main() {

    int n = 5;
    int e = 4;

    vector<vector<int>> edges {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5}
    };

    vector<vector<int>> result = printAdjacency(n, e, edges);

    cout << "DFS Traversal of the graph:" << endl;

    for(auto i : result) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

 return 0;
}