#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool solve (int node , int e , vector<vector<int>> &edge) {

    unordered_map<int , list< int>> adj;
    for(int i = 0; i < e; i++) {
        int u = edge[i][0];
        int v = edge[i][1];

        adj[u].push_back(v);
    }

    // find all indegree
    vector<int> indegree(node , 0);
    
    for(auto i : adj) {
        for(auto j : i.second) {
            indegree[j]++;
        }
    }

    // push 0 indegree into queue
    queue<int> q;
    for(int i = 0; i < node; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    // do bfs
    vector<int> ans;
    while(!q.empty()) {

        int temp = q.front();
        q.pop();

        ans.push_back(temp);

        // update the indegree of neighbors
        for(auto neighbors : adj[temp]) {
            indegree[neighbors]--;

            if(indegree[neighbors] == 0) {
                q.push(neighbors);
            }
        }
    }

    // check if the topological sort is possible or not
    if(ans.size() == node) {
        return true;
    }
    else {
        return false;
    }

    // return ans;
    // return "Cycle is not present";
    // return "Cycle is present";
}

int main() {

    int n = 4;
    int e = 5;

    vector<vector<int>> edges = {
        {0, 1},
        {0, 3},
        {1, 2},
        {2, 3},
        {3, 1}
    };

    // prepare the adjacency list
    if(solve(n, e, edges)) {
        cout << "Yes , cycle is present" << endl;
    } else {
        cout << "No , cycle is not present" << endl;
    }

 return 0;
}