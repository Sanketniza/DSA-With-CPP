#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:

        unordered_map<int , list <pair<int , int >>> adj;

        void addEdge(int u , int v , int wt) {
            pair<int , int> p = make_pair(v , wt);
            adj[u].push_back(p);
        }

        void printAdj() {

            cout << "Adjacency List of the Graph : " << endl;
            for(auto i : adj) {
                cout << i.first << " -> ";
                for(auto j : i.second) {
                    cout << "(" << j.first << " , " << j.second << ") ";
                }
                cout << endl;
            }

        }

        void topoSort(int node , unordered_map<int, bool> &vis , stack<int> &st) {
            vis[node] = true;

            for(auto i : adj[node]) {
                if(!vis[i.first]) {
                    topoSort(i.first , vis , st);
                }
            }
        }

        void shortestPath(int src , vector<int> &dist , stack<int> &st) {

            dist[src] = 0;

            while(!st.empty()) {
                int top = st.top();
                st.pop();

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

    Graph g;

    g.addEdge(0 , 1 , 5);
    //* (u <node1> , v <node2>, weight)
    g.addEdge(0 , 2 , 3);
    g.addEdge(1 , 2 , 2);
    g.addEdge(1 , 3 , 6);
    g.addEdge(2 , 3 , 7);
    g.addEdge(2 , 4 , 4);
    g.addEdge(2 , 5, 2);
    g.addEdge(3 , 4 , -1);
    g.addEdge(4 , 5 , -2);

    //* topological sort

    int n = 6;
    stack<int> st;
    unordered_map<int, bool> vis;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            g.topoSort(i , vis , st);
        }
    }

    int src = 1;
    vector<int> dist(n);
    for(auto i: dist) {
        dist[i] = INT_MAX;
    }

    g.shortestPath(src , dist , st);

    cout << "Shortest Path from source node " << src << " : " << endl;
    for(int i = 0; i < n; i++) {
        cout << "Node " << i << " : " << dist[i] << endl;
    }


 return 0;
}