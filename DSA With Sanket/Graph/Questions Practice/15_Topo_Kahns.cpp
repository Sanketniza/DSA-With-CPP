#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {

    // prepare the adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // find all indegree
    vector<int> indegree(v);
    for(auto i : adj) {
        for(auto j : i.second) {
            indegree[j]++;
        }
    }

    // push 0 indegree into queue
    queue<int> q;
    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;


    while(!q.empty()) {
        
        int front = q.front();
        q.pop();

        ans.push_back(front);

        // update the indegree of neighbors
        for(auto neigneighbors : adj[front]) {
            indegree[neigneighbors]--;
            if(indegree[neigneighbors] == 0) {
                q.push(neigneighbors);
            }
        }
    }

    return ans;
}

int main() {

    int v = 4;
    int e = 4;

    vector<vector<int> > edges = {
        {0, 1},
        {0, 3},
        {1, 2},
        {3, 2}

    };

    vector<int> ans = topologicalSort(edges, v, e);
    cout << "Topological Sort : ";

    for(auto i : ans) {
        cout << i << " ";
    }

 return 0;
}