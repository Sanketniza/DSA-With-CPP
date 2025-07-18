#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isCycleInOrd(int node , unordered_map<int , list<int>> &adj , unordered_map<int , bool> &visited) {

    unordered_map<int , int> parent;
    visited[node] = true;
    parent[node] = -1;
    queue<int> q;

    q.push(node);

    while(!q.empty()) {

        int temp = q.front();
        q.pop();

        for(auto i : adj[temp]) {

            if(visited[i] == true && i != parent[temp]) {
                return true;
            }

            else if(visited[i] == false) {
                visited[i] = true;
                parent[i] = temp;
                q.push(i);
            }
        }
    }
}

string solve(int node , int e , vector<vector<int>> &edge) {

    unordered_map<int , list<int>> adj;

    for(int i = 0; i < e; i++) {

        int u = edge[i][0];
        int v = edge[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int , bool> visited;

    for(int i = 1; i <= node; i++) {

        if(!visited[i]) {
            bool ans = isCycleInOrd(i , adj , visited); // we use here bfs traversal
            

            if(ans == true) {
                return "Cycle is present";
            }
        }
    }

    return "Cycle is not present";
}

int main() {
    
    int node = 4;
    int edge = 4;

    vector<vector<int>> edges = {
        {1 , 2}, 
        {2 , 3}, 
        {3 , 4}, 
        {4 , 1}
    };

    string ans = solve(node , edge , edges);

    cout << "ans : " << ans << endl;

 return 0;
}