
/* 
    ? Depth First Search (DFS)
    ? https://www.naukri.com/code360/problems/dfs-traversal_630462?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &component) {

    component.push_back(node);
    visited[node] = true;

    // For each connected node, make a recursive call
    for (auto i : adj[node]) {
        if (!visited[i]) {
            dfs(i, visited, adj, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    // Prepare the adjacency list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];


        adj[u].push_back(v);
        adj[v].push_back(u);

        // cout << u << " " << v << endl;
    }

    unordered_map<int, bool> visited;
    vector<vector<int>> ans;

    // Perform DFS for each node
    for (int i = 0; i < V; i++) { // V -> Total number of nodes in graph
        if (!visited[i]) {
            vector<int> component; // To store the current component
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }

    return ans;
}

int main() {
    int v = 7, E = 7;
    vector<vector<int>> edges = {
           
        {1, 2},
        {1, 7},
        {2, 3},
        {3, 4},
        {4, 5},
        {4, 8},
        {7, 8}  
    };

    vector<vector<int>> result = depthFirstSearch(v, E, edges);

    for (const auto &component : result) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}


/* 

    Input
    Let's assume the following input:

    V = 5 (Total number of nodes)
    E = 6 (Total number of edges)
    edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 4}, {3, 4}}

    Step 1: Prepare the Adjacency List
    The adjacency list adj will be populated as follows:

    adj[0] = {1, 2}
    adj[1] = {0, 3, 4}
    adj[2] = {0, 4}
    adj[3] = {1}
    adj[4] = {1, 2, 3}


 */