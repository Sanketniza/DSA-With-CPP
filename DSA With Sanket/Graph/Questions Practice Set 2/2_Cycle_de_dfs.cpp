#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool dfs(int node , unordered_map<int , list<int>> &adj , unordered_map<int , bool> &visited , unordered_map<int , bool> &dfsVisited) {
    

    visited[node] = true;
    dfsVisited[node] = true;

    for(auto i : adj[node]) {

        if(!visited[i]) {
            bool ans = dfs(i , adj , visited , dfsVisited);
            if(ans) {
                return true;
            }
        }

        else if(dfsVisited[i]) {
            return true;
        }
    }

    dfsVisited[node] = false;
    return false;
}

sting solve(int node , int edge , vector<vector<int>> edges) {
    
    // prepare for adj list
    for(int i = 0; i < edge; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // prepare two unodered map
    unordered_map<int , bool> visited;
    unordered_map<int , bool> dfsVisited;

    for(int i = 1; i <= node; i++) {

        if(!visited[i]) {
            bool ans = dfs(i , adj , visited , dfsVisited);

            if(ans) {
                return "Yes";
            }
        }
    }

    return "No";
}

int main() {

    int n = 5;
    int e = 4;

    vector<vector<int>> edges = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5}
    };

    string ans = solve(n, e, edges);
    cout << "ans : " << ans << endl;
 return 0;
}