// C++ program to find articulation points using a naive DFS approach

#include <bits/stdc++.h>
using namespace std;

// Standard DFS to mark all reachable nodes
void dfs(int node, unordered_map<int , list<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    
    for (int neighbor : adj[node]) {
        
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}


// Finds articulation points using naive DFS approach
vector<int> articulationPoints(int V, vector<vector<int>> &edges) {
    
    unordered_map<int , list<int>> adj;

    for(int i = 0; i < edges.size(); i++) {

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> res;

    // Try removing each node one by one
    for (int i = 0; i < V; ++i) {
        vector<bool> visited(V, false);
        visited[i] = true;
        
        // count DFS calls from i's neighbors
        int comp = 0; 
        for (auto it : adj[i]) {
            
            // early stop if already more than 1 component
            if (comp > 1) break; 

            if (!visited[it]) {
                
                // explore connected part
                dfs(it, adj, visited); 
                comp++;
            }
        }

        // if more than one component forms, it's an articulation point
        if (comp > 1)
            res.push_back(i);
    }

    if (res.empty())
        return {-1};

    return res;
} 

int main() {
    
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
                        // here {0 , 1} means 0 is connected to 1

    vector<int> ans = articulationPoints(V, edges);

    cout << "Articulation Points are: ";
    for (auto it : ans) {
        cout << it << " ";
    }

    return 0;
}