#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bfs(int node , unordered_map<int , bool> &visit , vector<vector<int>> &result , unordered_map<int , list<int>> &adj) {

    queue<int> q;
    q.push(node);
    visit[node] = true;
    vector<int> ans;

    while(!q.empty()) {
        
        int temp = q.front();
        q.pop();
        ans.push_back(temp);

        for(auto i : adj[temp]) {
            if(!visit[i]) {
                q.push(i);
                visit[i] = true;
            }
        }
    }
    result.push_back(ans);
    ans.clear();
}

vector<vector<int>> printAdjacency(int node , int e , vector<vector<int>> &edge) {

    // prepare adj list
    unordered_map<int , list<int>> adj;
    for(int i = 0; i < e; i++) {
        int u = edge[i][0];
        int v = edge[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int , bool> visit;
    vector<vector<int>> result;

    for(int i = 1; i <= node; i++) {
        if(!visit[i] ) {
            bfs(i , visit , result , adj);
        }
    }

    return result;
}

int main() {

    int n = 5;
    int e = 4;

    vector<vector<int>> edges {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5}
    };

    vector<vector<int>> ans = printAdjacency(n, e, edges);
    cout << "The BFS traversal of the graph is: " << endl;
    for(auto i : ans) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
 return 0;
}