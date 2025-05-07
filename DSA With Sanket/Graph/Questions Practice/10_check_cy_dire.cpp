#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool cycleDetection(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited) {

    visited[node] = true;
    dfsVisited[node] = true;

    for(auto neighbor: adj[node]) {
       
       if(!visited[neighbor]) {
            bool cycle = cycleDetection(neighbor, adj, visited, dfsVisited);
            if(cycle) {
                return true;
            }
        }
        else if(dfsVisited[neighbor]) {
            return true;
        }
    }

    dfsVisited[node] = false;
    return false;
}

bool detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {

    unordered_map<int, list<int>> adj;

    for(int i = 0; i < edges.size(); i++) {

        int v = edges[i].first = 1;
        int u = edges[i].second - 1;

        adj[v].push_back(u); // because it is directed graph
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for(int i = 1; i <= n; i++) {

        if(!visited[i]) {

            bool ans = cycleDetection(i, adj, visited, dfsVisited);
            if(ans) {
                return true;
            }
        }
    }

    return false;
}

int main() {

    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<pair<int, int>> edges;
    for(int i = 0; i < e; i++) {
        int u , v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    bool ans = detectCycleInDirectedGraph(n, edges);

    if(ans) {
        cout << "Cycle is present in the directed graph" << endl;
    } else {
        cout << "Cycle is not present in the directed graph" << endl;
    }

 return 0;
}