#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class graph {
    public:

    unordered_map<int , list<pair<int , int>> > adj;

    void addEdge(int u , int v , int wt) {
        pair<int , int> p = make_pair(v , wt);
        adj[u].push_back(p);
    }

    void dfs(int node , unordered_map<int , bool> &vis , stack<int> &s) {

        // make the node as visited;
        vis[node] = true;

        // for each connected node , make a recursive call to check if it is visited of not ;

        for(auto i : adj[node] ) {
            if(!vis[i.first]) {
                dfs(i.first , vis , s);
            }
        }

        s.push(node);
    }

    void shortestPath(int src , vector<int> &dist , stack<int> &s) {
        
        dist[src] = 0;

        while (!s.empty()) {

            int top = s.top();
            s.pop();

            if(dist[top] != INT_MAX) {
                for(auto i : adj[top]) {

                    if(dist[top] + i.second < dist[i.first]) {
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }

};

int main() {

    graph g;

    g.addEdge(0 , 1 , 5);
    g.addEdge(0 , 2 , 3);
    g.addEdge(1 , 2 , 2);
    g.addEdge(1 , 3 , 6);
    g.addEdge(2 , 3 , 7);
    g.addEdge(2 , 4 , 4);
    g.addEdge(2 , 5, 2);
    g.addEdge(3 , 4 , -1);
    g.addEdge(4 , 5 , -2);

    int n = 6;
    int src = 1;

    stack<int> s;
    unordered_map<int , bool> vis;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            g.dfs(i , vis , s);
        }
    }

    vector<int> distance(n);

    for(int i = 0; i < n; i++)  {
        distance[i] = INT_MAX;
    }

    g.shortestPath(src , distance , s);

    for(int i = 1; i < n; i++)  {
        cout << distance[i] << " " ;
    }


 return 0;
}