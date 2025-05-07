#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool bfs(int node , unordered_map<int , bool> &visited , unordered_map<int, list<int> > &adj) {
    
    unordered_map<int , int > parent;
    visited[node] = true;
    parent[node] = -1;

    queue<int> q;
    q.push(node);

    while(!q.empty()) {
        
        int front = q.front();
        q.pop();

        for(auto i:adj[front]) {

            if(visited[i] == true && i != parent[front]) {
                return true;
            }

            else if(visited[i] == false) {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }
}

string solve(int node , int e , vector<vector<int>> &edge) {
    
    unordered_map<int, list<int> > adj;
    for(int i = 0; i < edge.size(); i++) {
        int u = edge[i][0];
        int v = edge[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int , bool > vis;

    for(int i = 0; i < node; i++) {

        if(!vis[i]) {
            bool ans = bfs(i , vis , adj);

            if(ans == true) {
                return "Cycle is present";
            }
        }
    }
}

int main() {

    int v = 3, E = 2;
    vector<vector<int>> edges = {{2,1}, {2,0}};

    string ok = solve(v , E , edges);
    cout << "ok : " << ok << endl;

 return 0;
}