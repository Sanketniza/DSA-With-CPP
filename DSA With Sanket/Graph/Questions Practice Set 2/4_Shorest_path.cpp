#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bfs(int node , unordered_map<int , list<int>> &adj , vector<int> &visited , queue<int> &q) {
    
    
}

vector<int> shortestPath(int node , int e , vector<vector<int>> &edges , int start , int end) {

    // prepare adj list 
    unordered_map<int , list<int> > adj;

    for(int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // visited array
    vector<vector<int , bool>> visited (node + 1 , false);
    vector<vector<int , int>> parent(node + 1 , -1);
    queue<int> q;

    q.push(start);
    visited[start] = true;
    parent[start] = -1;

    while(!@q.empty()) {

        int front = q.front();
        q.pop();

        for(auto i : adj[front]) {
            if(visited[i] == false) {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    // shortest path
    vector<int> ans;

    int currNode = end;
    ans.push_back(end);

    while(currNode != start) {
        currNode = parent[currNode];
        ans.push_back(currNode);
    }

    reverse(ans.begin() , ans.end());
    return ans;
}

int main() {

        int node = 8;
        int edge = 9;

        vector<vector<int>> edges = {
            {1 , 2}, {1 , 3}, {1 , 4},
            {2 , 5} , {3 , 8} , 
            {4 , 6}, {5 , 8}, {6 , 7},
            {7 , 8}
        };

        int start = 1;
        int end  = 8;

        vector<int> asn = shortestPath(node , edge , edges , start , end);

        for(auto i : ans) {
            cout << i << " -> ";
        }
    
 return 0;
}