#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

void bfs(int node , vector<bool> &visited , queue<int> &q , unordered_map<int , list<int>> &adj , vector<vector<int>> &ans) {
    
    q.push(node);
    visited[node] = true;

    while(!q.empty()) {

        int temp = q.front();
        q.pop();

        ans.push_back({temp});

        for(auto i : adj[temp]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<vector<int>> PrintBFS(int node , int edge , vector<vector<int>>edges){ 

    // prepare for adj list
    unordered_map<int , list<int>> adj;

    // adj[node + 1];    

    for(int i = 0; i < edge; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // create visited array with false value
    vector<bool> visited(node + 1 , false);
    vector<vector<int>> ans;
    queue<int> q;

    for(int i = 1; i <= node; i++) {

        if(!visited[i]) {
            bfs(i , visited , q , adj , ans);
        }
    }

    return ans;
}



int main() {

    // Graph 
    vector<vector<int>> edges = { {1, 2},
    {2, 3},
    {3, 4},
    {3, 5}};
    int n = 3 , e = 3;

    vector<vector<int>> result = PrintBFS(n , e , edges);

    // print the ans

    for(int i = 0; i < result.size(); i++) {
        // cout << i << " -> ";

        for(int j = 0; j < result[i].size(); i++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }


 return 0;
}