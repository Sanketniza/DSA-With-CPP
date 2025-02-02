#include <vector>
#include <iostream>
using namespace std;

vector<int> bellmanFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> dist(n + 1, 1e8);
    dist[src] = 0;

    // Travel n - 1 times
    for (int i = 1; i <= n - 1; i++) {
        // Travel on edge list
        for (int j = 0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative weight cycle
    for (int j = 0; j < m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
            // Negative weight cycle detected
            return {};
        }
    }

    // Replace 1e8 with 1e8 for unreachable nodes
    for (int i = 1; i <= n; i++) {
        if (dist[i] == 1e8) {
            dist[i] = 1e8;
        }
    }

    return dist;
}

int main() {
    int n = 2, m = 1, src = 1;
    vector<vector<int>> edges = {
        {2, 1, 3}
    };

    vector<int> result = bellmanFord(n, m, src, edges);

    if (result.empty()) {
        cout << "Negative weight cycle detected" << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}