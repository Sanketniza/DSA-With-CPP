
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
class graph {

    public:
        unordered_map<int , list<int>  > adj;

        void addEdge(int u , int v , bool direction) {

            // direction = 0 -> undirected graph
            // direction = 1 -> directed graph

            // first create an edge from u to v
            adj[u].push_back(v);

            if(direction == 0) { // undirected graph
                // then create an edge from v to u
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

int main() { 

    int n;
    cout << "Enter Number of nodes: " << endl;
    cin >> n;

    int m; 
    cout << "Enter Number of edges: " << endl;
    cin >> m;

    graph g;

    for(int i = 0 ; i < m ; i++) {
        int u , v;
        cout << "Enter " << i + 1 << "th edges: " << endl;
        cin >> u >> v;
        g.addEdge(u , v , 0); // here u = source node , v = destination node and 0 = undirected graph
    }

    cout << "Graph Created Successfully!" << endl << endl;
    cout << "Adjacency List: " << endl;
    g.print();

    return 0;
}