#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // Adjacency list

void bfs(int node , vector<bool> &visit , queue<int> &q , vector<vector<int>> &result) {

    q.push(node);
    visit[node] = true;

    while(!q.empty()) {
        int temp = q.front();
        q.pop();

        result.push_back({temp});
        
        for(auto i : adj[temp]) {
            if(!visit[i]) {
                q.push(i);
                visit[i] = true;
            }
        }
    }
}

vector<vector<int>> PrintBFS(int node , int edge , vector<vector<int>> ed) {

    // prepare adj list 
    adj.resize(node + 1);
    for(int i = 0; i < edge; i++) {
        int u = ed[i][0];
        int v = ed[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    vector<bool> visited(node + 1, false); // 1 based indexing
    vector<vector<int>> result;

    for(int i = 1; i <= node; i++) {

        if(!visited[i]) {
            bfs(i , visited , q , result);
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
        {4, 5},
        {3, 4}
    };

    vector<vector<int>> result = PrintBFS(v, e, edge);

    for(auto i : result) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

 return 0;
}