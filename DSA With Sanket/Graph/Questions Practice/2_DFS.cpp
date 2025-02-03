#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:
        unordered_map<int , list<int>> adj;

        void addEdge(int u , int v) {  // undirected graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        void print() {

            for(auto i : adj) {
                cout << i.first << " -> ";
                for(auto j:i.second) {
                    cout << j << " , ";
                }
                cout << endl;
            }
            cout << endl;
        }

};

int main() {

    Graph g;

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,3);

    g.print();
 return 0;
}