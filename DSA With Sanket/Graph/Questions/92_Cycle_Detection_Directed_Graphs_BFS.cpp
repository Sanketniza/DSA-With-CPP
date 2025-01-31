/* 

    ? cycle detection in directed graph using bfs 
    ? https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0


    Problem statement
You are given a directed graph having ‘N’ nodes. A matrix ‘EDGES’ of size M x 2 is given which represents the ‘M’ edges such that there is an edge directed from node EDGES[i][0] to node EDGES[i][1].

Find whether the graph contains a cycle or not, return true if a cycle is present in the given directed graph else return false.

For Example :
In the following directed graph has a cycle i.e. B->C->E->D->B.

Note :
1. The cycle must contain at least two nodes.
2. It is guaranteed that the given graph has no self-loops in the graph.
3. The graph may or may not be connected.
4. Nodes are numbered from 1 to N.
5. Your solution will run on multiple test cases. If you are using global variables make sure to clear them.

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
class Graph{
    public:

    unordered_map<int , list<int >> adj;

    void addEdge(int v , int u , bool direction) {

        // 0 -> undirected graph
        // 1 -> directed graph

        adj[u].push_back(v);

        if(direction == 0) {
            adj[v].push_back(u);
        }

    }

    void print() {

            for(auto i:adj) {

                cout << i.first << " -> ";

                for(auto j:i.second) {
                    cout << j << " , ";
                }
                
                 cout << endl;
            }
        }    
    
}; 
       int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {

        // prepare adj list
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < edges.size(); i++) {
          int u = edges[i].first - 1;
          int v = edges[i].second - 1;
          adj[u].push_back(v);
        }

           // find out indegree
        vector<int> indegree(n, 0);
        for(auto i:adj) {
          for(auto j:i.second) {
            indegree[j]++;
          }
        }

           // push 0 degree element into queue
        queue<int> q;
        for(int i = 0; i < n; i++) {
          if(indegree[i] == 0) {
            q.push(i);
          }
        }

           // do bfs
        int cnt = 0;

        while (!q.empty()) {

            int front = q.front();
            q.pop();

            cnt++;

            for(auto neineighbor:adj[front]) {
              indegree[neineighbor]--;
              if(indegree[neineighbor] == 0) {
                q.push(neineighbor);
              }
            }

        }

            if(cnt == n) {
                 return false;
            } 

            else {
                 return true;
            }

    }



int main() { 

       int n, e;
    cin >> n >> e;

    vector<pair<int, int>> edges(e);

    for(int i = 0; i < e; i++) {
      int u, v;
      cin >> u >> v;
      edges[i] = {u, v};
    }
    
    cout << "ans is : " << detectCycleInDirectedGraph(n, edges) << endl;

    

    return 0;
}