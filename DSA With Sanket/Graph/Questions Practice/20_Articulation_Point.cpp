#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node , vector<bool> &visited , unordered_map<int , list<int>> &adj ) {

    visited[node] = true;

    for(auto nbr : adj[node]) {

        if(!visited[nbr]) {
            dfs(nbr , visited , adj );
        }
    }
}

vector<int> articulationPoints(int v , vector<vector<int>> &edge) {

    unordered_map<int , list<int>> adj;

    for(int i = 0; i < edge.size(); i++) {

        int u = edge[i][0];
        int v = edge[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> res;

    for(int i = 0; i < v; i++) {

        vector<bool> visited(v , false);
        visited[i] = true;

        // cout dfs call for i's neighbours

        int count = 0;

        for(auto nbr : adj[i]) {

            if(count > 1) {
                break;
            }

            if(!visited[nbr]) {
                dfs(nbr , visited , adj);
                count++;
            }
        }

        if(count > 1) {
            res.push_back(i);
        }
    }

    if(res.empty()) {
        return {-1};
    }

    return res;
}

int main() {

    int v;
    vector<vector<int>> edges {{0, 1}, {0, 2}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {3, 5}};

    vector<int> ans = articulationPoints(v, edges);

    cout << "Articulation Points are: ";
    // for(auto i : ans) {
    //     cout << i << " ";
    // }


 return 0;
}