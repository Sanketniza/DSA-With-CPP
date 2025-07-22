#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class  graph{
    public:

        unordered_map<int , list<pair<int , int>> > adj;

        void addEdge(int u , int v , int wt) {
            pair<int , int> p = make_pair(v , wt);
            adj[u].push_back(p);
        }

        void dfs(int node , unordered_map<int , bool> &visited , stack<int> &st) {
            
            visited[node] = true;

            for(auto neighbors : adj[node]) {
                if(!visited[neighbors.first]) {
                    dfs(neighbors.first , visited , st);
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
                    for(auto j : adj[top]) {
                        
                        if(dist[top] + j.second < dist[j.first]) {
                            dist[j.first] = dist[top] + j.second;
                        }
                    }
                }
            }
        }

        // void print() {

        //     cout << "Adjacency List of the Graph : " << endl;           

        //     for(auto i : adj) {

        //         cout << i.first << " -> " << endl;

        //         for(auto j = i.second) {

        //             cout << "( " << j.first << " , " << j.second << " ) " << endl;
        //         }
        //     }
        // }

};

int main() {

    graph g;

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

    // topological sort
    int n = 6;
    int src = 1;

    stack<int> s;
    unordered_map<int , bool> visited;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            g.dfs(i , visited , s);
        }
    }

    vector<int> dist(n);
    for(int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }


    g.shortestPath(src , dist , s);

    cout << "ans is : ";

    for(auto i:dist) {
        cout << i << " ";
    }

 return 0;
}