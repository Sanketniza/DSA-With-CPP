#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node , unordered_map<int , bool> &visited , vector<int> &parent , queue<int> &q  , unordered_map<int , list<int>> &adj) {

    // do bfs
   
   visited[node] = true;
   parent[node] = -1;
    q.push(node);

    while(!q.empty()) {

        int front = q.front();
        q.pop();

        for(auto i : adj[front]) {

            if(!visited[i]) {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }
}

vector<int> solve(int node , int m , vector<vector<int>> &edge , int s , int t) {
    
    // prepare the adjacency list
    unordered_map<int , list<int>> adj;
    for(int i = 0; i < m; i++) {
        int u = edge[i][0];
        int v = edge[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // need to create all data structure that need to be used
    unordered_map<int , bool> visited;
    vector<int> parent(node);
    queue<int> q;
    vector<int> ans;

    visited[node] = true;
     parent[node] = -1;
    q.push(node);

    while(!q.empty()) {

        int front = q.front();
        q.pop();

        for(auto i : adj[front]) {

            if(!visited[i]) {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }
    // now we need to find the cycle
    int currentNode = t;
    ans.push_back(t);

    while(currentNode != s) {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    reverse(ans.begin() , ans.end());
    return ans;

    
}

int main() {

    int n = 8;
    int m = 9;

    vector<vector<int>> edge = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5},
        {5, 6},
        {6, 7},
        {7, 0},
        {1, 3}
    };

    int s = 0;
    int t = 8;

    vector<int> ans = solve(n, m, edge , s , t);
    cout << "Shortest path from " << s << " to " << t << " is: ";

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
    cout << ans.back() << endl;

 return 0;
}