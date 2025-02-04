#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

vector<vector<int>> adj; // Adjacency list

void bfs(int node, vector<bool>& visited, queue<int>& q, vector<vector<int>>& result) {
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int temp = q.front();
        q.pop();

        result.push_back({temp});

        for (auto i : adj[temp]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<vector<int>> PrintBFS(int node, int e, vector<vector<int>>& edge) {
    // Prepare the adj list
    adj.resize(node + 1); // Adjust size to accommodate 1-based indexing

    for (int i = 0; i < e; i++) {
        int u = edge[i][0];
        int v = edge[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // We need a data structure to keep track of visited nodes
    vector<bool> visited(node + 1, false); // Initialize all nodes as unvisited

    // We need a queue to keep track of nodes to visit
    queue<int> q;

    // We need a vector to keep track of the result
    vector<vector<int>> result;

    for (int i = 1; i <= node; i++) { // Adjusted to 1-based indexing
        if (!visited[i]) {
            bfs(i, visited, q, result);
        }
    }

    return result;
}

int main() {
    int v = 5;
    int e = 4;

    vector<vector<int>> edge = {
        {1, 2},
        {2, 3},
        {3, 4},
        {3, 5}
    };

    vector<vector<int>> result = PrintBFS(v, e, edge);

    cout << "Elements in the graph are : " << endl;

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
