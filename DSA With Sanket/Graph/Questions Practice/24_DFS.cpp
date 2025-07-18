#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node , unordered_map<int, list<int> > &adj , vector<int> &component , vector<bool> &visited) {
    
    visited[node] = true;
    component.push_back(node);

    for(auto i : adj[node]) {
        if(!visited[i]) {
            dfs(i , adj , component , visited);
        }
    }

}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    
    unordered_map<int , list<int> > adj;

    for(int i = 0; i < E; i++) {

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(V , false);
    vector<vector<int>> ans;
    stack<int> s;

    for(int i = 1; i <= V; i++) {
        if(!visited[i]) {
            vector<int> component;
            dfs(i , adj , component , visited);
            ans.push_back(component);
        }
    }

    return ans;
};
int main() {

    int V = 7, E = 7;
    vector<vector<int>> edges = {
        {1, 2},
        {1, 7},
        {2, 3},
        {3, 4},
        {4, 5},
        {4, 8},
        {7, 8}
    };
    
    vector<vector<int>> result = depthFirstSearch(V, E, edges);

    // print the dfs element 

    // for(int i = 0; i < result.size(); i++) {
    //     for(int j = 0; j < result[i].size(); j++) {
    //         cout << result[i][j] << endl;
    //     }
    //     cout << " ";
    // }

    for(const auto &com : result) {
        for(int i : com) {
            cout << i << " ";
        }
        cout << endl;
    }

 return 0;
}