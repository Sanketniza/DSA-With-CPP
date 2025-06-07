#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node , unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis, stack<int> &st) {
    
    vis[node] = true;

    for(auto nbr : adj[node] ) {
        if(!vis[nbr]) {
            dfs(nbr , adj , vis, st);
        }
    }

    st.push(node);
}

void dfsRev(int node , unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis) {

    vis[node] = true;

    for(auto nbr : adj[node]) {
        if(!vis[nbr]) {
            dfsRev(nbr , adj , vis);
        }
    }
}


int stronglyConnectedComponents(int v , vector<vector<int>> &edges) {

    // Adjacency list for directed graph
    unordered_map<int , list<int>> adj;

    for(int i = 0; i < edges.size(); i++) {

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // topological sort using DFS
    unordered_map<int, bool> vis;
    stack<int> st;

    for(int i = 0; i < v; i++) {

        if(!vis[i]) {
            dfs(i , adj , vis, st);
        }
    }

    // Create transpose graph for directed graph

    unordered_map<int, list<int>> transpose;
    for(int i = 0; i < v; i++) {
        vis[i] = false; // Reset visited for next DFS

        for(auto nbr : adj[i] ) {
            transpose[nbr].push_back(i); // Reverse the direction
        }
        
    }

    // Perform DFS on transpose graph in order of finishing times
    int count = 0;

    while(!st.empty()) {

        int top = st.top();
        st.pop();

        if(!vis[top]) {
            count++;
            dfsRev(top , transpose , vis);
        }
    }

    return count;
}

int main() {

    int v = 5;
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}
    };

    cout << "Strongly Connected Components: " << stronglyConnectedComponents(v, edges) << endl;

 return 0;
}