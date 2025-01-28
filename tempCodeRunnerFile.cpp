
// cycle detection in directed graphs using dfs
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isCyclic(int n, vector<vector<int>>& adj) {
    vector<int> inDegree(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j : adj[i]) {
            inDegree[j]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        count++;
        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return count != n;
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n);
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if (isCyclic(n, adj)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
