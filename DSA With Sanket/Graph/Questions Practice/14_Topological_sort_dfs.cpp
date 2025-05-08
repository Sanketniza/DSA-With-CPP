#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, list<int> > &adj, stack<int> &s, vector<bool> &visited) {

    visited[node] = true;

    for(auto i:adj[node]) {

        if(!visited[i]) {
            dfs(i, adj, s, visited);
        }
    }

    s.push(node);
}

vector<int> topologicalSort( vector <vector <int> > &graph , int v , int e) {

    // create adj directed list
    unordered_map<int, list<int> > adj;
    for(int i = 0; i < e; i++) {
        int u = graph[i][0];
        int v = graph[i][1];

        adj[u].push_back(v); // this condition is for create directed graph
    }

    vector<bool> visited(v, false);
    stack<int> s;

    for(int i = 1; i <= v; i++) {

        if(!visited[i]) {
            dfs(i, adj, s, visited);
        }
    }

    vector<int> ans;

    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main() {

    int n , e;
    cout << "Enter number of nodes and edges : ";
    cin >> n >> e;

    vector<vector<int>> edge;

    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        edge.push_back({u, v});
    }

    vector<int> ans = topologicalSort(edge, n, e);
    cout << "Topological Sort : ";

    for(auto i : ans) {
        cout << i << " ";
    }

 return 0;
}