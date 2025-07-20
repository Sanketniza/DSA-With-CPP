#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node , unordered_map<int , list<int>> &adj , unordered_map<int , bool> &visited , vector<int> &ans) {
    
    visited[node] = true;

    stack<int> s;

    for(auto i : adj[node]) {
        if(!visited[i]) {
            dfs(i , adj , visited , ans);
        }

    }

    s.push(node);
    ans.push_back(node);
}

vector<int> solve(int node , int edge , vector<vector<int>> &edges) {

    // prepare for adj list

    unordered_map<int , list<int>> adj;
    for(int i = 0; i < edge; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // preapare list for topological sort
    unordered_map<int , bool> visited;
    vector<int>ans;

    for(int i = 1; i <= node; i++) {
        
        if(!visited[i]) {
            dfs(i , adj , visited , ans);
        }
    }

    return ans;
}

int main() {

    int n = 5;
    int m = 6;

    vector<vector<int>> edge = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}, {2, 4}};

    vector<int> ans = solve(n, m, edge);

    cout << "Topological Sort : ";

    for(auto i : ans) {
        cout << i << " ";
    }

 return 0;
}