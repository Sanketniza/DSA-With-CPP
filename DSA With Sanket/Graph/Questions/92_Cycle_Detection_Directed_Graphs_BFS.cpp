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

bool detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {

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
        return false; // no cycle
    } 

    else {
        return true; // cycle present
    }

}

int main() { 

    Graph g;

    int n, e;
    cout << "Enter number of nodes and edges : ";
    cin >> n >> e;

    vector<pair<int, int>> edges(e);

    for(int i = 0; i < e; i++) {
      int u, v;
      cin >> u >> v;
      g.addEdge(v, u, 1); // 1 for directed graph
    }
    
    cout << "ans is : " << detectCycleInDirectedGraph(n, edges) << endl;

    return 0;
}