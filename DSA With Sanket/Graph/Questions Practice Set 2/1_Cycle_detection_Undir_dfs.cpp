#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool cycleDetection(int node , unordered_map<int, list<int>> &adj ,unordered_map<int, int> &visited ) {
    
    visited[node] = 1;
    
    for(auto i : adj[node]) {

        if(visited[i] == 1) {
            return true;
        }
        
        else if(visited[i] == 0) {
            bool ans = cycleDetection(i , adj , visited);
            if(ans) {
                return true;
            }
        }

    }

    return false;
}

string solve(int n, int e, vector<vector<int>> edges) {
    
    // prepare the adj list
    unordered_map<int, list<int>> adj;

    for(int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int , int > visited;
    
    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            bool ans = cycleDetection(i, adj, visited);

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

    string ans =  solve(n, e, edges);

    cout << "ans : " << ans << endl;

 return 0;
}