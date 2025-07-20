#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(int node , int edge , vector<vector<int>> &edges) {
    
    //prepare adj list
    unordered_map<int , list<int>> adj;

    for(int i = 0; i < edge; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // find the indegree

    vector<int> indegree(node , 0);

    for(auto i : adj) { 
        for(auto j : i.second){ 
            indegree[j]++;
        }
    }

    // push 0 degree into queue;
    queue<int> q;
    for(int i = 0; i < node; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    // do bfs
    vector<int> ans;

    while(!q.empty()) {

        int front = q.front();
        q.pop();
        ans.push_back(front);

        for(auto nig : adj[front]) {

            indegree[nig]--;
            if(indegree[nig] == 0) {
                ans.push_back(nig);
            }
        }
    }

    return ans;

}

int main() {

    int v = 4;
    int e = 4;

    vector<vector<int> > edges = {
        {0, 1},
        {0, 3},
        {1, 2},
        {3, 2}

    };

    vector<int> ans = topologicalSort(v , e , edges);

    cout << "Topological Sort : " << endl;
    for(auto i:ans) {
        cout << i << " ";
    }
    cout << endl;
    

 return 0;
}