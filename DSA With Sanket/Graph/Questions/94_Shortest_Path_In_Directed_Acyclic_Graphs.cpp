/* 

    ? Shortest path in a directed acyclic graph
    ? https://www.naukri.com/code360/library/shortest-path-in-a-directed-acyclic-graph

    

 */
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
class Graph{

    public:

        unordered_map<int , list<pair<int , int> > > adj;

        void addEdge(int u , int v , int wt) {
            pair<int , int> p = make_pair(v , wt);
            adj[u].push_back(p);
        }

        void PrintAdj() {
            cout << "Adjacency List of the Graph : " << endl;
            for(auto i:adj) {

                cout << i.first << " -> ";

                for(auto j:i.second) {
                    cout << "(" << j.first << " , " << j.second << ") ";
                }
                cout << endl;
            }
        }

        void dfs(int node , unordered_map<int, bool> &vis , stack<int> &st) {
            vis[node] = true;
            for(auto i:adj[node]) {
                if(!vis[i.first]) {
                    dfs(i.first , vis , st);
                }
            }
            st.push(node);
        }

        void shortestPath(int src , vector<int> &dist , stack<int> &st) {

            dist[src] = 0;

            while (!st.empty()) {
                int top = st.top();
                st.pop();

                if(dist[top] != INT_MAX) {
                    for(auto i:adj[top]) {
        
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

    /*  

        0
       / \
      1   2
      |  /|\
      3 | | 5
       \|/
        4


        

        0 -> 1 -> 3
        0 -> 2 -> 5
        0 -> 2 -> 4
        1 -> 2 -> 4
        1 -> 2 -> 5
        2 -> 3
        2 -> 4
        3 -> 4
        4 -> 5
        2 -> 5
        

    
     */


    g.PrintAdj(); // for checking the adjacency list
    // we need to do the topological sort

    //* topology sort

    int n = 6;

    stack<int> st;
    unordered_map<int, bool> vis;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            g.dfs(i , vis , st);
        }
    }

   
    int src = 1;
    vector<int> dist(n);
       

    for(int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }

    // dist[src] = 0;

    g.shortestPath(src, dist , st);

   

    cout << "ans is : ";

    for(auto i:dist) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}